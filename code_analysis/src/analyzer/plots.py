import pandas as pd
import numpy as np
from pathlib import Path
import matplotlib.pyplot as plt
import scienceplots
import re
import argparse

argparser = argparse.ArgumentParser()
# add input folder argument
argparser.add_argument("-i", "--input_path", help="path to the input folder", default="./results")
# add output folder argument
argparser.add_argument("-o", "--output_path", help="path to the output folder", default="./plots")
# add input folder for log files
argparser.add_argument("-l", "--log_path", help="path to the log files", default="./results")

args = argparser.parse_args()

# use science plots
# plt.style.use('science')
# plt.style.use(['science','ieee'])

FONT_SIZE = 18
FONT_WEIGHT = 550
FONT_FAMILY = 'serif'

# Adjust global font size and weight
plt.rcParams.update({'font.size': FONT_SIZE, 'font.weight': FONT_WEIGHT, 'axes.labelweight': FONT_WEIGHT, 'axes.titleweight': FONT_WEIGHT, 'figure.dpi': 300, 'font.family': FONT_FAMILY})

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
        df['total_execs'] = df['executions'].astype(int)
        df['execs_per_sec'] = df['exec/sec'].astype(float)

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


def prepare_df(plots_df, program_name, target_col='relative_time', normalize=False):
    programs_df = plots_df[plots_df['program'].str.contains(program_name)]

    # Filter data for each mode
    afl_programs = programs_df[programs_df['fuzzer_mode'] == 'afl']
    our_programs = programs_df[programs_df['fuzzer_mode'] == 'our']
    fuzzer_programs = programs_df[programs_df['fuzzer_mode'] == 'fuzzer']

    # Group and get first occurrence
    afl_programs_first = None
    our_programs_first = None
    fuzzer_programs_first = None

    if target_col == 'execs_per_sec':
        afl_programs_first = afl_programs.groupby(['program', 'run'])[[target_col, 'total_execs']].max()
        our_programs_first = our_programs.groupby(['program', 'run'])[[target_col, 'total_execs']].max()
        fuzzer_programs_first = fuzzer_programs.groupby(['program', 'run'])[[target_col, 'total_execs']].max()

        if normalize:
            afl_programs_first[target_col] =  afl_programs_first[target_col] / afl_programs_first['total_execs']
            our_programs_first[target_col] =  our_programs_first[target_col] / our_programs_first['total_execs']
            fuzzer_programs_first[target_col] =  fuzzer_programs_first[target_col] / fuzzer_programs_first['total_execs']
    else:
        afl_programs_first = afl_programs[afl_programs['saved_crashes'] >= 1].groupby(['program', 'run'])[[target_col]].min()
        our_programs_first = our_programs[our_programs['saved_crashes'] >= 1].groupby(['program', 'run'])[[target_col]].min()
        fuzzer_programs_first = fuzzer_programs[fuzzer_programs['saved_crashes'] >= 1].groupby(['program', 'run'])[[target_col]].min()

    programs = sorted(programs_df['program'].unique(), key=lambda x: int(x.split('_')[1]))

    return programs, afl_programs_first, our_programs_first, fuzzer_programs_first

    # afl_values = []
    # our_values = []
    # fuzzer_values = []

    # speedup_data = []
    # for idx, program in enumerate(programs):
    #     if program not in our_programs_first.index or program not in afl_programs_first.index or program not in fuzzer_programs_first.index:
    #         print(f'Program {program} not found in all dataframes')
    #         continue

    #     our_data = our_programs_first.loc[program]['relative_time']
    #     afl_data = afl_programs_first.loc[program]['relative_time']
    #     fuzzer_data = fuzzer_programs_first.loc[program]['relative_time']
    #     if not len(our_data) or not len(afl_data) or not len(fuzzer_data):
    #         print(f'Program {program} has empty data')
    #         continue

    #     print(f"Program: {program}")
    #     print(f"Length our: {len(our_data)}, afl: {len(afl_data)}, fuzzer: {len(fuzzer_data)}")

    #     min_len = min(len(our_data), len(afl_data), len(fuzzer_data))
    #     our_data_item = our_data[:min_len]
    #     afl_data_item = afl_data[:min_len]
    #     fuzzer_data_item = fuzzer_data[:min_len]
    #     afl_values.append(afl_data_item)
    #     our_values.append(our_data_item)
    #     fuzzer_values.append(fuzzer_data_item)

    #     # compute speedup
    #     afl_mean = afl_data_item.mean()
    #     our_mean = our_data_item.mean()
    #     fuzzer_mean = fuzzer_data_item.mean()
    #     afl_speedup = afl_mean / fuzzer_mean
    #     our_speedup = our_mean / fuzzer_mean
    #     speedup_data.append((afl_speedup, our_speedup))


    # return programs, afl_values, our_values, fuzzer_values, speedup_data

def plot_boxplot(plots_df, program_name, xlabel, our_name='Our', afl_name='AFL++', fuzzer_name='Our Fuzzer', rotation=0, box_width=0.6, spacing=4, offset=1):
    programs, afl_programs_first, our_programs_first, fuzzer_programs_first = prepare_df(plots_df, program_name)
    boxplot_data = []

    # Accumulate positions
    positions = []

    results = []

    speedup_data = []

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

        print(f"Program: {program}")
        print(f"Length our: {len(our_data)}, afl: {len(afl_data)}, fuzzer: {len(fuzzer_data)}")

        min_len = min(len(our_data), len(afl_data), len(fuzzer_data))
        our_data = our_data[:min_len]
        afl_data = afl_data[:min_len]
        fuzzer_data = fuzzer_data[:min_len]


        # Add data for each fuzzer mode
        boxplot_data.append(afl_data)
        boxplot_data.append(our_data)
        boxplot_data.append(fuzzer_data)

        results.append({'afl': afl_data.mean(), 'our': our_data.mean(), 'fuzzer': fuzzer_data.mean(), 'program': program})

        afl_mean = afl_data.mean()
        our_mean = our_data.mean()
        fuzzer_mean = fuzzer_data.mean()
        afl_speedup = afl_mean / fuzzer_mean
        our_speedup = our_mean / fuzzer_mean
        print(afl_mean)
        print(our_mean)
        print(fuzzer_mean)
        print(afl_speedup)
        print(our_speedup)

        speedup_data.append((afl_speedup, our_speedup))

        plotted_programs.append(program)


    for idx, program in enumerate(plotted_programs): 
        # Calculate positions for each set of boxplots
        base_position = idx * spacing  # Adjust the multiplier as needed
        positions.extend([base_position - offset, base_position, base_position + offset])


    if len(boxplot_data) == 0:
        print(f'No data for program {program_name}')
        return
    fig, ax = plt.subplots(figsize=(10, 5))
    bp = plt.boxplot(boxplot_data, patch_artist=True, positions=positions,  widths=box_width, showfliers=False)

    programs = plotted_programs

    # Coloring and setting labels
    colors = ['lightblue', 'lightgray', 'lightgreen'] * len(programs)
    for patch, color in zip(bp['boxes'], colors):
        patch.set_facecolor(color)

    # Adjusting x-tick positions and labels
    plt.xticks([i * spacing for i in range(len(programs))], programs)

    plt.xlabel(xlabel)
    plt.ylabel('Time (s)')
    plt.xticks(rotation=rotation)

    # Adding legend
    # plt.legend([bp["boxes"][0], bp["boxes"][1], bp["boxes"][2]], [afl_name, our_name, fuzzer_name])
    fig.legend([bp["boxes"][0], bp["boxes"][1], bp["boxes"][2]], [afl_name, our_name, fuzzer_name], loc='upper center', ncol=3)

    # make the program name more readable, e.g., `complex_1` -> `Complex 1`
    programs = [program.split('_')[0].capitalize() + ' ' + program.split('_')[1] for program in programs]

    ax.set_xticklabels(programs)

    # plt.tight_layout()
    plt.tight_layout(rect=[0, 0., 1, 0.90])
    # ax.set_ylabel('Time (s)')
    ax.set_ylabel('Time (log scale) [s]')
    # ax.set_yscale('log')

    plt.savefig(f'./plots/{program_name}_boxplot.png', bbox_inches='tight')

    # save results as a table
    # create a dataframe from the boxplot data
    df = pd.DataFrame(results)
    # rename the columns
    df.rename(columns={'afl': afl_name, 'our': our_name, 'fuzzer': fuzzer_name, 'program': 'Program'}, inplace=True)
    # reorder the columns
    df = df[['Program', afl_name, our_name, fuzzer_name]]
    # format the time values to 2 decimal places
    df[afl_name] = df[afl_name].map('{:.2f}'.format)
    df[our_name] = df[our_name].map('{:.2f}'.format)
    df[fuzzer_name] = df[fuzzer_name].map('{:.2f}'.format)
    # format the program name to be more readable
    df['Program'] = df['Program'].str.replace('_', ' ').str.title()

    # set the program name as the first column
    df = df[['Program', afl_name, our_name, fuzzer_name]]
    # add speedup over afl
    df['Speedup over'+afl_name] = df[afl_name].mean() / df[fuzzer_name].mean()
    # add speedup over our
    df['Speedup over'+our_name] = df[our_name].mean() / df[fuzzer_name].mean()

    # no index
    # df.set_index('Program', inplace=True)
    # save as a csv file
    df.to_csv(f'./plots/{program_name}_boxplot.csv')
    # save as a latex table with title, caption, and label
    df.to_latex(f'./plots/{program_name}_boxplot.tex',
                caption=f'Average time for {program_name} to find the crash for each fuzzer',
                label=f'tab:{program_name}-average_crash_times')


    ###
    bar_width = box_width
    index = np.arange(len(programs))

    afl_bars = ax.bar(index - bar_width/2, [speedup[0] for speedup in speedup_data], bar_width, label=afl_name)
    our_bars = ax.bar(index + bar_width/2, [speedup[1] for speedup in speedup_data], bar_width, label=our_name)

    # make the program name more readable, e.g., `complex_1` -> `Complex 1`
    # programs = [program.split('_')[0].capitalize() + ' ' + program.split('_')[1] for program in programs]

    # create a dataframe from the data
    speedup_df = pd.DataFrame(speedup_data, columns=[afl_name, our_name])
    speedup_df['Program'] = programs
    # format the speedup values to 2 decimal places
    speedup_df[afl_name] = speedup_df[afl_name].map('{:.2f}'.format)
    speedup_df[our_name] = speedup_df[our_name].map('{:.2f}'.format)
    # make the program name the first column
    speedup_df = speedup_df[['Program', afl_name, our_name]]
    # save as a latex table with title, caption, and label
    speedup_df.to_latex(f'./plots/{program_name}_speedup.tex',
                        index=False, caption=f'Speedup for {program_name}',
                        label=f'tab:{program_name}_speedup')

    # save as a csv file
    speedup_df.to_csv(f'./plots/{program_name}_speedup.csv', index=False)

    ax.set_xlabel(xlabel)
    ax.set_ylabel('Speedup')
    ax.set_xticks(index)
    # ax.set_xticklabels(programs)
    ax.set_xticklabels(programs, rotation=rotation)
    # ax.legend()

    fig.legend([afl_bars, our_bars], [afl_name, our_name], loc='upper center', ncol=2)

    # plt.tight_layout()
    plt.tight_layout(rect=[0, 0., 1, 0.92])

    plt.savefig(f'./plots/{program_name}_speedup_barplot.png', bbox_inches='tight')


def plot_speedup_barplot(plots_df, program_name, xlabel, our_name='Our', afl_name='AFL++', fuzzer_name='Our Fuzzer', rotation=0, bar_width=0.35):

    programs, afl_programs_first, our_programs_first, fuzzer_programs_first = prepare_df(plots_df, program_name)
    speedup_data = []

    plotted_programs = []
    for program in programs:
        # if program in our_programs_first.index and program in afl_programs_first.index and program in fuzzer_programs_first.index:
        if program not in our_programs_first.index or program not in afl_programs_first.index or program not in fuzzer_programs_first.index:
            print(f'Program {program} not found in all dataframes')
            continue

        our_data = our_programs_first.loc[program]['relative_time']
        afl_data = afl_programs_first.loc[program]['relative_time']
        fuzzer_data = fuzzer_programs_first.loc[program]['relative_time']
        if not len(our_data) or not len(afl_data) or not len(fuzzer_data):
            print(f'Program {program} has empty data')
            continue

        print(f"Program: {program}")
        print(f"Length our: {len(our_data)}, afl: {len(afl_data)}, fuzzer: {len(fuzzer_data)}")

        min_len = min(len(our_data), len(afl_data), len(fuzzer_data))
        our_data = our_data[:min_len]
        afl_data = afl_data[:min_len]
        fuzzer_data = fuzzer_data[:min_len]

        afl_mean = afl_data.mean()
        our_mean = our_data.mean()
        fuzzer_mean = fuzzer_data.mean()
        #

        # Calculate speedp
        afl_speedup = afl_mean / fuzzer_mean
        our_speedup = our_mean / fuzzer_mean

        plotted_programs.append(program)
        speedup_data.append((afl_speedup, our_speedup))

    # Creating the bar plot
    fig, ax = plt.subplots(figsize=(10, 5))

    # Plotting data
    # bar_width = 0.35
    index = np.arange(len(programs))

    afl_bars = ax.bar(index - bar_width/2, [speedup[0] for speedup in speedup_data], bar_width, label=afl_name)
    our_bars = ax.bar(index + bar_width/2, [speedup[1] for speedup in speedup_data], bar_width, label=our_name)

    # make the program name more readable, e.g., `complex_1` -> `Complex 1`
    programs = [program.split('_')[0].capitalize() + ' ' + program.split('_')[1] for program in programs]

    # create a dataframe from the data
    speedup_df = pd.DataFrame(speedup_data, columns=[afl_name, our_name])
    speedup_df['Program'] = programs
    # format the speedup values to 2 decimal places
    speedup_df[afl_name] = speedup_df[afl_name].map('{:.2f}'.format)
    speedup_df[our_name] = speedup_df[our_name].map('{:.2f}'.format)
    # make the program name the first column
    speedup_df = speedup_df[['Program', afl_name, our_name]]
    # save as a latex table with title, caption, and label
    speedup_df.to_latex(f'./plots/{program_name}_speedup.tex',
                        index=False, caption=f'Speedup for {program_name}',
                        label=f'tab:{program_name}_speedup')

    # save as a csv file
    speedup_df.to_csv(f'./plots/{program_name}_speedup.csv', index=False)

    ax.set_xlabel(xlabel)
    ax.set_ylabel('Speedup')
    ax.set_xticks(index)
    # ax.set_xticklabels(programs)
    ax.set_xticklabels(programs, rotation=rotation)
    # ax.legend()

    fig.legend([afl_bars, our_bars], [afl_name, our_name], loc='upper center', ncol=2)

    # plt.tight_layout()
    plt.tight_layout(rect=[0, 0., 1, 0.92])

    plt.savefig(f'./plots/{program_name}_speedup_barplot.png', bbox_inches='tight')


def plot_execs_per_sec_barplot(plots_df, program_name, xlabel, our_name='Our', afl_name='AFL++', fuzzer_name='Our Fuzzer', rotation=0, bar_width=0.35, normalize=False):
    programs, afl_programs_first, our_programs_first, fuzzer_programs_first = prepare_df(plots_df, program_name, target_col='execs_per_sec', normalize=normalize)

    afl_speeds = []
    our_speeds = []
    fuzzer_speeds = []
    plotted_programs = []
    for program in programs:
        if program in our_programs_first.index and program in afl_programs_first.index and program in fuzzer_programs_first.index:
            # Calculate median times for each program
            min_len = min(len(afl_programs_first.loc[program]['execs_per_sec']), len(our_programs_first.loc[program]['execs_per_sec']), len(fuzzer_programs_first.loc[program]['execs_per_sec']))
            afl_programs = afl_programs_first.loc[program]['execs_per_sec'][:min_len]
            our_programs = our_programs_first.loc[program]['execs_per_sec'][:min_len]
            fuzzer_programs = fuzzer_programs_first.loc[program]['execs_per_sec'][:min_len]

            afl_median = afl_programs.mean()
            our_median = our_programs.mean()
            fuzzer_median = fuzzer_programs.mean()
            print(f"Program: {program}")
            print(f"AFL: {afl_median}, Our: {our_median}, Fuzzer: {fuzzer_median}")

            afl_speeds.append(afl_median)
            our_speeds.append(our_median)
            fuzzer_speeds.append(fuzzer_median)
            plotted_programs.append(program)

    # Creating the bar plot
    fig, ax = plt.subplots(figsize=(10, 5))
    afl_bars = ax.bar(np.arange(len(plotted_programs)) - bar_width, afl_speeds, bar_width, label=afl_name)
    our_bars = ax.bar(np.arange(len(plotted_programs)), our_speeds, bar_width, label=our_name)
    fuzzer_bars = ax.bar(np.arange(len(plotted_programs)) + bar_width, fuzzer_speeds, bar_width, label=fuzzer_name)


    ax.set_xlabel(xlabel)
    ylabel = 'Execs/sec'
    if normalize:
        ylabel = 'Normalized execs/sec'
    ax.set_ylabel(ylabel)
    ax.set_xticks(np.arange(len(plotted_programs)))

    # make the program name more readable, e.g., `complex_1` -> `Complex 1`
    programs = [program.split('_')[0].capitalize() + ' ' + program.split('_')[1] for program in programs]

    ax.set_xticklabels(programs, rotation=rotation)

    fig.legend([afl_bars, our_bars, fuzzer_bars], [afl_name, our_name, fuzzer_name], loc='upper center', ncol=3)

    plt.tight_layout(rect=[0, 0., 1, 0.90])
    filename=f'./plots/{program_name}_execs_per_sec_barplot.png'
    if normalize:
        filename = f'./plots/{program_name}_execs_per_sec_normalized_barplot.png'
    plt.savefig(filename, bbox_inches='tight')
    print("Plotted programs:", plotted_programs)


def plot_execs_per_sec_boxplot(plots_df, program_name, xlabel, our_name='Our', afl_name='AFL++', fuzzer_name='Our Fuzzer', rotation=0, bar_width=0.35):
    programs, afl_programs_first, our_programs_first, fuzzer_programs_first = prepare_df(plots_df, program_name, target_col='execs_per_sec')
    boxplot_data = []

    plotted_programs = []
    for program in programs:
        if program in our_programs_first.index and program in afl_programs_first.index and program in fuzzer_programs_first.index:
            # Calculate median times for each program
            min_len = min(len(afl_programs_first.loc[program]['execs_per_sec']), len(our_programs_first.loc[program]['execs_per_sec']), len(fuzzer_programs_first.loc[program]['execs_per_sec']))
            afl_programs = afl_programs_first.loc[program]['execs_per_sec'][:min_len]
            our_programs = our_programs_first.loc[program]['execs_per_sec'][:min_len]
            fuzzer_programs = fuzzer_programs_first.loc[program]['execs_per_sec'][:min_len]

            # Add data for each fuzzer mode
            boxplot_data.append(afl_programs)
            boxplot_data.append(our_programs)
            boxplot_data.append(fuzzer_programs)

            plotted_programs.append(program)

    if len(boxplot_data) == 0:
        print(f'No data for program {program_name}')
        return
    fig, ax = plt.subplots(figsize=(10, 5))
    bp = plt.boxplot(boxplot_data, patch_artist=True)

    programs = plotted_programs

    # Coloring and setting labels
    colors = ['lightblue', 'lightgray', 'lightgreen'] * len(programs)
    for patch, color in zip(bp['boxes'], colors):
        patch.set_facecolor(color)

    # Adjusting x-tick positions and labels
    plt.xticks([i * 3 for i in range(len(programs))], programs)

    plt.xlabel(xlabel)
    plt.ylabel('Executions/sec')

    # make the program name more readable, e.g., `complex_1` -> `Complex 1`
    programs = [program.split('_')[0].capitalize() + ' ' + program.split('_')[1] for program in programs]

    ax.set_xticklabels(programs, rotation=rotation)


    # Adding legend
    plt.legend([bp["boxes"][0], bp["boxes"][1], bp["boxes"][2]], [afl_name, our_name, fuzzer_name], ncol=3)
    plt.tight_layout(rect=[0, 0., 1, 0.90])

    plt.savefig(f'./plots/{program_name}_execs_per_sec_boxplot.png', bbox_inches='tight')


def make_plot(plots_df, program_name, kind,  figsize=(10,5), afl_name="AFL++", our_name="AFL++/IG", fuzzer_name="Our Fuzzer", **kwargs):
    valid_kinds = ['box_plot', 'bar_plot']
    if kind not in valid_kinds:
        print(f'Invalid kind {kind}')
        return
    programs, afl_data, our_data, fuzzer_data, speedup_data = prepare_df(plots_df, program_name)

    if kind == 'box_plot':

        boxplot_data = []
        for idx, program in enumerate(programs):
            # Calculate positions for each set of boxplots
            base_position = idx * kwargs['spacing']
            positions = [base_position - kwargs['offset'], base_position, base_position + kwargs['offset']]
            # Add data for each fuzzer mode
            boxplot_data.append(afl_data[idx])
            boxplot_data.append(our_data[idx])
            boxplot_data.append(fuzzer_data[idx])


        print(len(boxplot_data), len(positions))
        fig, ax = plt.subplots(figsize=figsize)
        bp = plt.boxplot(boxplot_data, patch_artist=True, positions=positions,  widths=kwargs['width'], showfliers=False)

        # Coloring and setting labels
        colors = ['lightblue', 'lightgray', 'lightgreen'] * len(programs)
        for patch, color in zip(bp['boxes'], colors):
            patch.set_facecolor(color)

        # Adjusting x-tick positions and labels
        plt.xticks([i * kwargs['spacing'] for i in range(len(programs))], programs)

        plt.xlabel(kwargs['xlabel'])
        plt.xticks(rotation=kwargs['rotation'])

        # Adding legend
        # plt.legend([bp["boxes"][0], bp["boxes"][1], bp["boxes"][2]], [afl_name, our_name, fuzzer_name])
        fig.legend([bp["boxes"][0], bp["boxes"][1], bp["boxes"][2]], [afl_name, our_name, fuzzer_name], loc='upper center', ncol=3)

        # make the program name more readable, e.g., `complex_1` -> `Complex 1`
        programs = [program.split('_')[0].capitalize() + ' ' + program.split('_')[1] for program in programs]

        ax.set_xticklabels(programs)

        # plt.tight_layout()
        plt.tight_layout(rect=[0, 0., 1, 0.90])
        # ax.set_ylabel('Time (s)')
        ax.set_ylabel('Time (log scale) [s]')
        # ax.set_yscale('log')

        plt.savefig(f'./plots/{program_name}_boxplot.png', bbox_inches='tight')


if __name__ == "__main__":
    # Create output plots folder
    Path(args.output_path).mkdir(parents=True, exist_ok=True)

    plot_data_files = list(Path(args.input_path).glob("*-plot_data"))
    plot_data_df = process_plot_data(plot_data_files)

    logfiles = list(Path(args.log_path).glob("*log"))
    log_df = process_logs(logfiles)
    cols = ['program', 'program_id', 'run', 'fuzzer_mode', 'relative_time', 'saved_crashes', 'execs_per_sec', 'total_execs']
    plots_df = plot_data_df[cols]
    log_df = log_df[cols]

    merged_df = pd.concat([plots_df, log_df])
    programs = sorted(merged_df['program'].unique(), key=lambda x: int(x.split('_')[1]))
    # remove the indices in the program names
    programs = set([program.split('_')[0] for program in programs])
    for program in programs:
        print("Plotting boxplot for program", program)
        if program == 'complex':
            rotation = 45
            bar_width = 0.25
            box_width = 0.9
            box_spacing = 4
            box_offset = 1
            exec_bar = 0.2
            xlabel = 'Program'
        else:
            rotation = 0
            bar_width = 0.07
            box_width = 0.3
            box_spacing = 5
            box_offset = 1
            exec_bar = 0.06
            xlabel = 'Characteristics'

        # plot_execs_per_sec_boxplot(merged_df, program, our_name='AFL++/IG', afl_name='AFL++', fuzzer_name='Our Fuzzer', rotation=rotation, bar_width=0.2, xlabel=xlabel)
        # plot_execs_per_sec_barplot(merged_df, program, our_name='AFL++/IG', afl_name='AFL++', fuzzer_name='Our Fuzzer', rotation=rotation, bar_width=exec_bar, xlabel=xlabel)
        # plot_execs_per_sec_barplot(merged_df, program, our_name='AFL++/IG', afl_name='AFL++', fuzzer_name='Our Fuzzer', rotation=rotation, bar_width=exec_bar, xlabel=xlabel, normalize=True)
        plot_boxplot(merged_df, program, our_name='AFL++/IG', afl_name='AFL++', rotation=rotation, box_width=box_width, spacing=box_spacing, offset=box_offset, xlabel=xlabel)
        # plot_speedup_barplot(merged_df, program, our_name='AFL++/IG', afl_name='AFL++', rotation=rotation, bar_width=bar_width, xlabel=xlabel)

        # make_plot(merged_df, program, kind="box_plot", our_name='AFL++/IG', afl_name='AFL++', rotation=rotation, width=box_width, spacing=box_spacing, offset=box_offset, xlabel=xlabel)
