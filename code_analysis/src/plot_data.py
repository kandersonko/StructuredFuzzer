from pathlib import Path
import argparse
import pandas as pd
import matplotlib.pyplot as plt

# takes the input path as an argument
argparser = argparse.ArgumentParser()
argparser.add_argument("-i", "--input_path", help="path to the input file")

# takes the output path as an argument
argparser.add_argument("-o", "--output_path", help="path to the output file")

args = argparser.parse_args()

def prepare(data_path):
    data = pd.read_csv(data_path)
    data.columns = data.columns.str.strip()
    data.rename(columns={"# relative_time": "relative_time"}, inplace=True)
    return data


def main():
    # set index to column relative_time
    # data.set_index("relative_time", inplace=True)
    our_data_path = f"{args.input_path}_our"
    afl_data_path = f"{args.input_path}_afl"
    our_data = prepare(our_data_path)
    afl_data = prepare(afl_data_path)
    
    min_len = min(len(our_data), len(afl_data))
    our_data = our_data[:min_len]
    afl_data = afl_data[:min_len]
    
    # plot the crashes and set the legend and labels
    # our_data.plot(x="relative_time", y="saved_crashes")
    plt.figure(figsize=(10, 5))

    plt.plot(our_data["relative_time"], our_data["saved_crashes"], label="Our")
    
    plt.plot(afl_data["relative_time"], afl_data["saved_crashes"], label="AFL")
    
    plt.xlabel("Time (s)")
    plt.ylabel("Saved crashes")

    plt.legend()
    
    plt.savefig(args.output_path)

if __name__ == "__main__":
    
    main()

