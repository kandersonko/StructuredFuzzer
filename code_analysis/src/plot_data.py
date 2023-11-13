from pathlib import Path
import argparse
import pandas as pd
import matplotlib.pyplot as plt

# takes the input path as an argument
argparser = argparse.ArgumentParser()
argparser.add_argument("-i", "--input_path", help="path to the input file")

args = argparser.parse_args()

def prepare(data_path):
    data = pd.read_csv(data_path)
    data.columns = data.columns.str.strip()
    data.rename(columns={"# relative_time": "relative_time"}, inplace=True)
    return data

def plot_speedup(afl_data, our_data, output_path):
    """The speedup in finding crashes relative to AFL"""
    speedup = afl_data["saved_crashes"] / our_data["saved_crashes"]
    plt.figure(figsize=(10, 5))
    
    plt.plot(our_data["relative_time"], speedup, label="Speedup")
    
    plt.xlabel("Time (s)")
    plt.ylabel("Speedup")
    plt.legend()
    plt.savefig(f"{output_path}_speedup.png")


def plot_crashes(afl_data, our_data, output_path):
    plt.figure(figsize=(10, 5))

    plt.plot(our_data["relative_time"], our_data["saved_crashes"], label="Our")
    
    plt.plot(afl_data["relative_time"], afl_data["saved_crashes"], label="AFL")
    
    plt.xlabel("Time (s)")
    plt.ylabel("Saved crashes")

    plt.legend()
    
    plt.savefig(f"{output_path}_crashes.png")


def main():
    # set index to column relative_time
    # data.set_index("relative_time", inplace=True)
    folders = [f for f in Path(args.input_path).glob("./*")]
    results = []
    for folder in folders:
        paths = folder.glob("*-outdir")
        
        our_data = None
        afl_data = None
        for data_path in paths:
            if "our" in data_path.name:
                our_data = prepare(data_path / "default/plot_data")
            else:
                afl_data = prepare(data_path / "default/plot_data")
                

        min_len = min(len(our_data), len(afl_data))
        our_data = our_data[:min_len]
        afl_data = afl_data[:min_len]
        print("folder:", folder)
        
        filename = folder / folder.name
        print("filename:", filename)

        plot_speedup(afl_data, our_data, filename)
        plot_crashes(afl_data, our_data, filename)

if __name__ == "__main__":
    
    main()

