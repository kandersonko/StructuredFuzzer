#!/usr/bin/env python3

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

args = argparser.parse_args()

# use science plots
plt.style.use('science')
# plt.style.use(['science','ieee'])

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

def plot_boxplot(plots_df, program_name, title):

   programs_df = plots_df[plots_df['program'].str.contains(program_name)]

   afl_programs = programs_df[programs_df['fuzzer_mode'] == 'afl']
   our_programs = programs_df[programs_df['fuzzer_mode'] == 'our']
   afl_programs_first = afl_programs[afl_programs['saved_crashes'] >= 1].groupby(['program', 'run'])[['relative_time']].min()
   our_programs_first = our_programs[our_programs['saved_crashes'] >= 1].groupby(['program', 'run'])[['relative_time']].min()
   programs = sorted(programs_df['program'].unique(), key=lambda x: int(x.split('_')[1]))
   plot_programs = []
   boxplot_data = []
   for program in programs:
      if program not in our_programs_first.index or program not in afl_programs_first.index:
         print(f'Program {program} not found in both dataframes')
         continue
      our_data = our_programs_first.loc[program]['relative_time']
      afl_data = afl_programs_first.loc[program]['relative_time']
      # make sure both have the same length
      plot_programs.append(program)
      min_length = min(len(afl_data), len(our_data))
      afl_data = afl_data.iloc[:min_length]
      our_data = our_data.iloc[:min_length]
      # use boxplot to plot the saved_crashes column
      # compute the position of the boxplot, use the list of programs to get the index of the program
      # positions = [position_idx-0.2, position_idx+0.2]
      # ax.boxplot([afl_data, our_data], positions=positions, patch_artist=True)
      boxplot_data.extend([afl_data, our_data])


   fig, ax = plt.subplots(figsize=(10, 5))
   # plot each program relative_time for crash
   num_programs = len(plot_programs)
   bp = plt.boxplot(boxplot_data, patch_artist=True, positions=np.arange(1, num_programs * 2 + 1))

   # Coloring and setting labels
   colors = ['lightblue', 'lightgray'] * num_programs
   for patch, color in zip(bp['boxes'], colors):
      patch.set_facecolor(color)

   # Adjusting x-tick positions and labels
   tick_positions = np.arange(1.5, num_programs * 2, step=2)
   # plt.xticks(tick_positions, [f'Program{i}' for i in range(1, num_programs + 1)])
   plt.xticks(tick_positions, plot_programs)

   plt.xlabel('Program')
   plt.ylabel('Time (s)')
   plt.title(title)

   # Adding legend
   plt.legend([bp["boxes"][0], bp["boxes"][1]], ['AFL', 'Our'])

   plt.tight_layout()

   ax.set_ylabel('Logscale Time (s)')
   ax.set_yscale('log')
   # # change the
   # plt.show()
   output_filename = Path(args.output_path) / f'{program_name}_boxplot.png'
   plt.savefig(output_filename, bbox_inches='tight')


if __name__ == "__main__":
    # Create output plots folder
    Path(args.output_path).mkdir(parents=True, exist_ok=True)

    plot_data_files = list(Path(args.input_path).glob("*-plot_data"))
    plot_data_df = process_plot_data(plot_data_files)
    programs = sorted(plot_data_df['program'].unique(), key=lambda x: int(x.split('_')[1]))
    # remove the indices in the program names
    programs = set([program.split('_')[0] for program in programs])
    print(programs)
    titles = {
        'complex': 'First crash time for complex programs',
        'depth': 'First crash time for programs with variable depths',
        'width': 'First crash time for programs with variable widths',
        'condition': 'First crash time for programs with various conditions',
    }
    for program in programs:
        print("Plotting boxplot for program", program)
        plot_boxplot(plot_data_df, program, titles[program])
