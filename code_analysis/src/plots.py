import pandas as pd
import numpy as np
from pathlib import Path
import matplotlib.pyplot as plt
import scienceplots
import re
import argparse

argparser = argparse.ArgumentParser()
# add input folder argument
argparser.add_argument("-i", "--input_path", help="path to the input folder")
# add output folder argument
argparser.add_argument("-o", "--output_path", help="path to the output folder")
# add input folder for log files
argparser.add_argument("-l", "--log_path", help="path to the log files")

args = argparser.parse_args()

# use science plots
plt.style.use('science')
# plt.style.use(['science','ieee'])

def process_logs(logfiles):
    dfs = []
    for logfile in logfiles:
        log_data = logfile.read_text()
        # skip if log data is empty
        if not log_data:
            continue
        # Regular expression to match each line in the log file
        log_regex = r'(\d+\.\d+)s \[(\w+) #\d+\] run time: (\d+h-\d+m-\d+s), clients: (\d+), corpus: (\d+), objectives: (\d+), executions: (\d+), exec/sec: (\d+\.\d+)'
        # Parsing the log file
        parsed_data = re.findall(log_regex, log_data)

        # Creating the DataFrame
        columns = ['timestamp', 'event', 'run_time', 'clients', 'corpus', 'objectives', 'executions', 'exec/sec']
        df = pd.DataFrame(parsed_data, columns=columns)

        # Converting data types
        df['timestamp'] = df['timestamp'].astype(float)
        df['clients'] = df['clients'].astype(int)
        df['corpus'] = df['corpus'].astype(int)
        df['objectives'] = df['objectives'].astype(int)
        df['executions'] = df['executions'].astype(int)
        df['exec/sec'] = df['exec/sec'].astype(float)

        # Convert the first timestamp to a reference starting time
        start_time = df['timestamp'].iloc[0]
        df['time_elapsed'] = df['timestamp'] - start_time

        # get the run id from the match of the path where there is `run-<id>`
        df['run'] = re.search(r'run_(\d+)', str(logfile)).group(1)
        # get the program name from the match of the path where there is `/<name>/-run`
        program = re.search(r'([^/]+)-mode', str(logfile)).group(1)
        df['program'] = program
        # get the program id from the program name 
        df['program_id'] = program.split('_')[1]
        # get the fuzzer mode from the match of the path where there is `<mode>-outdir`
        mode = re.search(r'mode_([^/]+)-run', str(logfile)).group(1)
        df['fuzzer_mode'] = mode

        df['saved_crashes'] = df['objectives']
        df['relative_time'] = df['time_elapsed']

        # Calculate the time elapsed since the start of the log for each entry
        df['time_elapsed'] = df['timestamp'] - start_time
        dfs.append(df)

    return pd.concat(dfs)


def process_fuzzer_stats(stats):
    data = []
    for stat in stats:
        content = stat.read_text().splitlines()
        params = [{line.split(':')[0].strip(): line.split(':')[1].strip()} for line in content if ':' in line]
        # merge the params array into a single dict
        params = {k: v for d in params for k, v in d.items()}
        # get the run id from the match of the path where there is `run-<id>`
        params['run'] = re.search(r'run_(\d+)', str(stat)).group(1)
        # get the program name from the match of the path where there is `/<name>/-run`
        params['program'] = re.search(r'([^/]+)-mode', str(stat)).group(1)
        # get the program id from the program name 
        params['program_id'] = params['program'].split('_')[1]
        # get the fuzzer mode from the match of the path where there is `<mode>-outdir`
        mode = re.search(r'mode_([^/]+)-run', str(stat)).group(1)
        params['fuzzer_mode'] = mode
        data.append(params)

    # create a dataframe from the data
    df = pd.DataFrame(data)
    # convert the columns to numeric
    for col in df.columns:
        if col not in ['run', 'program', 'fuzzer_mode', 'target_mode', 'afl_banner', 'afl_version', 'command_line', 'stability', 'bitmap_cvg']:
            df[col] = pd.to_numeric(df[col])

    return df

def process_plot_data(plot_data):
    dfs = []
    for plot in plot_data:
        # get the program name from the match of the path where there is `/<name>/-run`
        program_name = re.search(r'([^/]+)-mode', str(plot)).group(1)
        # get the program id from the program name
        program_id = program_name.split('_')[1]
        # get the run id from the match of the path where there is `run-<id>`
        run_id = re.search(r'run_(\d+)', str(plot)).group(1)
        # get the fuzzer mode from the match of the path where there is `<mode>-outdir`
        mode = re.search(r'mode_([^/]+)-run', str(plot)).group(1)
        df = pd.read_csv(plot)
        # add the program name and run id to the dataframe
        df['program'] = program_name
        df['program_id'] = program_id
        df['run'] = run_id
        df['fuzzer_mode'] = mode

        # rename the column '# relative_time' to 'relative_time'
        df.rename(columns={'# relative_time': 'relative_time'}, inplace=True)

        # convert the values to numeric
        for col in df.columns:
            if col not in ['program', 'run', 'fuzzer_mode']:
                df[col] = pd.to_numeric(df[col], errors='coerce')

        # strip spaces in column names
        df.columns = df.columns.str.strip()

        dfs.append(df)

    # create a dataframe from the data
    return pd.concat(dfs)


def plot_boxplot(plots_df, program_name, spacing=3, offset=0.5, title=None, our_name='Our', afl_name='AFL++', fuzzer_name='Fuzzer'):
    programs_df = plots_df[plots_df['program'].str.contains(program_name)]

    # Filter data for each mode
    afl_programs = programs_df[programs_df['fuzzer_mode'] == 'afl']
    our_programs = programs_df[programs_df['fuzzer_mode'] == 'our']
    fuzzer_programs = programs_df[programs_df['fuzzer_mode'] == 'fuzzer']

    # Group and get first occurrence
    afl_programs_first = afl_programs[afl_programs['saved_crashes'] >= 1].groupby(['program', 'run'])[['relative_time']].min()
    our_programs_first = our_programs[our_programs['saved_crashes'] >= 1].groupby(['program', 'run'])[['relative_time']].min()
    fuzzer_programs_first = fuzzer_programs[fuzzer_programs['saved_crashes'] >= 1].groupby(['program', 'run'])[['relative_time']].min()

    programs = sorted(programs_df['program'].unique(), key=lambda x: int(x.split('_')[1]))
    boxplot_data = []

    # Accumulate positions
    positions = []

    plotted_programs = []
    for idx, program in enumerate(programs):
        if program not in our_programs_first.index or program not in afl_programs_first.index or program not in fuzzer_programs_first.index:
            print(f'Program {program} not found in all dataframes')
            continue

        our_data = our_programs_first.loc[program]['relative_time']
        afl_data = afl_programs_first.loc[program]['relative_time']
        fuzzer_data = fuzzer_programs_first.loc[program]['relative_time']
        if not len(our_data) or not len(afl_data) or not len(fuzzer_data):
            print(f'Program {program} has empty data')
            continue

        # Add data for each fuzzer mode
        boxplot_data.append(afl_data)
        boxplot_data.append(our_data)
        boxplot_data.append(fuzzer_data)

        plotted_programs.append(program)


    for idx, program in enumerate(plotted_programs): 
        # Calculate positions for each set of boxplots
        base_position = idx * spacing  # Adjust the multiplier as needed
        positions.extend([base_position - offset, base_position, base_position + offset])


    if len(boxplot_data) == 0:
        print(f'No data for program {program_name}')
        return
    fig, ax = plt.subplots(figsize=(10, 5))
    bp = plt.boxplot(boxplot_data, patch_artist=True, positions=positions)

    programs = plotted_programs

    # Coloring and setting labels
    colors = ['lightblue', 'lightgray', 'lightgreen'] * len(programs)
    for patch, color in zip(bp['boxes'], colors):
        patch.set_facecolor(color)

    # Adjusting x-tick positions and labels
    plt.xticks([i * spacing for i in range(len(programs))], programs)

    plt.xlabel('Program')
    plt.ylabel('Time (s)')
    if title:
        plt.title(title)

    # Adding legend
    plt.legend([bp["boxes"][0], bp["boxes"][1], bp["boxes"][2]], [afl_name, our_name, fuzzer_name])

    # make the program name more readable, e.g., `complex_1` -> `Complex 1`
    programs = [program.split('_')[0].capitalize() + ' ' + program.split('_')[1] for program in programs]

    ax.set_xticklabels(programs)

    plt.tight_layout()
    # ax.set_ylabel('Time (s)')
    ax.set_ylabel('Logscale Time (s)')
    ax.set_yscale('log')

    plt.savefig(f'./plots/{program_name}_boxplot.png', bbox_inches='tight')


def plot_speedup_barplot(plots_df, program_name, title=None, our_name='Our', afl_name='AFL++', fuzzer_name='Fuzzer'):
    programs_df = plots_df[plots_df['program'].str.contains(program_name)]

    # Filter data for each mode
    afl_programs = programs_df[programs_df['fuzzer_mode'] == 'afl']
    our_programs = programs_df[programs_df['fuzzer_mode'] == 'our']
    fuzzer_programs = programs_df[programs_df['fuzzer_mode'] == 'fuzzer']

    # Group and get first occurrence
    afl_programs_first = afl_programs[afl_programs['saved_crashes'] >= 1].groupby(['program', 'run'])[['relative_time']].min()
    our_programs_first = our_programs[our_programs['saved_crashes'] >= 1].groupby(['program', 'run'])[['relative_time']].min()
    fuzzer_programs_first = fuzzer_programs[fuzzer_programs['saved_crashes'] >= 1].groupby(['program', 'run'])[['relative_time']].min()

    programs = sorted(programs_df['program'].unique(), key=lambda x: int(x.split('_')[1]))
    speedup_data = []

    plotted_programs = []
    for program in programs:
        if program in our_programs_first.index and program in afl_programs_first.index and program in fuzzer_programs_first.index:
            # Calculate median times for each program
            afl_median = afl_programs_first.loc[program]['relative_time'].median()
            our_median = our_programs_first.loc[program]['relative_time'].median()
            fuzzer_median = fuzzer_programs_first.loc[program]['relative_time'].median()

            # Calculate speedup
            afl_speedup = afl_median / fuzzer_median
            our_speedup = our_median / fuzzer_median
        # else:
        #     # Placeholder values if program data is missing
        #     afl_speedup = np.nan
        #     our_speedup = np.nan
            plotted_programs.append(program)
            speedup_data.append((afl_speedup, our_speedup))

    # Creating the bar plot
    fig, ax = plt.subplots(figsize=(10, 5))

    # Plotting data
    bar_width = 0.35
    programs = plotted_programs
    index = np.arange(len(programs))

    afl_bars = ax.bar(index - bar_width/2, [speedup[0] for speedup in speedup_data], bar_width, label=afl_name)
    our_bars = ax.bar(index + bar_width/2, [speedup[1] for speedup in speedup_data], bar_width, label=our_name)

    # make the program name more readable, e.g., `complex_1` -> `Complex 1`
    programs = [program.split('_')[0].capitalize() + ' ' + program.split('_')[1] for program in programs]

    ax.set_xlabel('Program')
    ax.set_ylabel('Speedup')
    if title:
        ax.set_title(title)
    ax.set_xticks(index)
    ax.set_xticklabels(programs)
    ax.legend()

    plt.tight_layout()
    plt.savefig(f'./plots/{program_name}_speedup_barplot.png', bbox_inches='tight')


if __name__ == "__main__":
    # Create output plots folder
    Path(args.output_path).mkdir(parents=True, exist_ok=True)

    plot_data_files = list(Path(args.input_path).glob("*-plot_data"))
    plot_data_df = process_plot_data(plot_data_files)

    logfiles = list(Path(args.log_path).glob("*log"))
    log_df = process_logs(logfiles)
    cols = ['program', 'program_id', 'run', 'fuzzer_mode', 'relative_time', 'saved_crashes']
    plots_df = plot_data_df[cols]
    log_df = log_df[cols]

    merged_df = pd.concat([plots_df, log_df])
    programs = sorted(merged_df['program'].unique(), key=lambda x: int(x.split('_')[1]))
    # remove the indices in the program names
    programs = set([program.split('_')[0] for program in programs])
    titles = {
        'complex': 'First crash time for complex programs',
        'depth': 'First crash time for programs with variable depths',
        'width': 'First crash time for programs with variable widths',
        'condition': 'First crash time for programs with various conditions',
    }
    for program in programs:
        print("Plotting boxplot for program", program)
        plot_boxplot(merged_df, program, spacing=4, offset=0.6, our_name='AFL++ with input generation', afl_name='AFL++', fuzzer_name='Our fuzzer')
        plot_speedup_barplot(merged_df, program, our_name='Speedup over AFL++ with input generation', afl_name='Speedup over AFL++', fuzzer_name='Our fuzzer')


    
