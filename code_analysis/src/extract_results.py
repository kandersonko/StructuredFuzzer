#!/usr/bin/env python3

import argparse
from pathlib import Path
import re
import os

arg_parser = argparse.ArgumentParser()
# add output directory argument
arg_parser.add_argument("--output", "-o", default="results", help="output directory")
# add input directory argument
arg_parser.add_argument("--input", "-i", default="programs", help="input directory")

args = arg_parser.parse_args()

def main():
    # Create output folder
    output_path = Path(args.output)
    output_path.mkdir(parents=True, exist_ok=True)
    folders = Path(args.input).glob("*/runs/*/*-outdir/default/")
    for folder in folders:
        plot_data = folder / "plot_data"
        stats = folder / "fuzzer_stats"

        # Check if the plot data and fuzzer stats files exist
        if not plot_data.exists() or not stats.exists():
            continue


        # get the run id from the match of the path where there is `run-<id>`
        run = re.search(r'run-(\d+)', str(folder)).group(1)
        # get the program name from the match of the path where there is `programs/<name>/`
        program = re.search(r'programs/([^/]+)/', str(folder)).group(1)
        # get the fuzzer mode from the match of the path where there is `/<mode>-outdir/`
        mode = re.search(r'/([^/]+)-outdir/', str(folder)).group(1)

        print(f"Processing {program} run {run} mode {mode}")

        # Create the output plot_data file filename with the run number and program name
        output_plot_data = output_path / f"{program}-mode_{mode}-run_{run}-plot_data"

        # Create the output fuzzer_stats file filename with the run number and program name
        output_fuzzer_stats = output_path / f"{program}-mode_{mode}-run_{run}-fuzzer_stats"

        # Copy the plot data file to the output folder
        os.system(f"cp {plot_data} {output_plot_data}")
        # Copy the fuzzer stats file to the output folder
        os.system(f"cp {stats} {output_fuzzer_stats}")



if __name__ == '__main__':
    main()
