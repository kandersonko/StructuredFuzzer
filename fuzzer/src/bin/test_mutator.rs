use core::{cell::RefCell, time::Duration};
use std::{
    env,
    fs::{self, OpenOptions},
    io::Write,
    path::PathBuf,
    process,
};

use clap::{Arg, ArgAction, Command};
use libafl::{
    corpus::{Corpus, InMemoryOnDiskCorpus, InMemoryCorpus, OnDiskCorpus},
    events::SimpleEventManager,
    executors::forkserver::{ForkserverExecutor, TimeoutForkserverExecutor},
    feedback_or,
    feedbacks::{CrashFeedback, MaxMapFeedback, TimeFeedback},
    fuzzer::{Fuzzer, StdFuzzer},
    inputs::{BytesInput, HasBytesVec, Input},
    monitors::SimpleMonitor,
    mutators::{
        scheduled::havoc_mutations, token_mutations::I2SRandReplace, tokens_mutations,
        StdMOptMutator, StdScheduledMutator, Tokens,
    },
    observers::{HitcountsMapObserver, StdCmpValuesObserver, StdMapObserver, TimeObserver},
    schedulers::{
        powersched::PowerSchedule, IndexesLenTimeMinimizerScheduler, StdWeightedScheduler,
    },
    stages::{
        calibrate::CalibrationStage, power::StdPowerMutationalStage, StdMutationalStage,
        TracingStage,
    },
    state::{HasCorpus, HasMetadata, StdState},
    Error,
};
use libafl_bolts::{
    current_nanos, current_time,
    rands::StdRand,
    shmem::{ShMem, ShMemProvider, UnixShMemProvider},
    tuples::{tuple_list, Merge},
    AsMutSlice,
};
use libafl_targets::cmps::AFLppCmpLogMap;
use nix::sys::signal::Signal;

use libafl::mutators::Mutator;

// import the PLCRuntimeMutator from lib.rs
use fuzzer::PLCRandomInputMutator;


fn main() -> Result<(), libafl::Error> {

    // Initialize the components needed for the mutator
    let mut state = StdState::new(
        StdRand::with_seed(42),
        InMemoryCorpus::<BytesInput>::new(),
        InMemoryCorpus::<BytesInput>::new(),
        &mut (),
        &mut (),
    ).unwrap();


    // let mut input = BytesInput::new(b"%IW0.0,INT,0".to_vec());
    // let mut input = BytesInput::new(b"%IX0.0,BOOL,0".to_vec());
    let input_str = "
%ID0.0,REAL,0.0
%IW0.0,INT,0
%IX0.0,BOOL,0".as_bytes();
    let mut input = BytesInput::new(input_str.to_vec());
    let mut mutator = PLCRandomInputMutator::new();

    for _ in 0..20 {
        // Apply the mutator
        mutator.mutate(&mut state, &mut input, 0)?;

        // Print the mutated input
        println!("Mutated input: {:?}", String::from_utf8_lossy(input.bytes()));
    }

    Ok(())
}
