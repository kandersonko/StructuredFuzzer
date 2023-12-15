use std::str;
use libafl_bolts::{rands::{Rand, StdRand, RomuDuoJrRand}, Named};
use rand::{Rng, thread_rng};

use libafl::{
    corpus::Corpus,
    inputs::{Input, HasBytesVec},
    mutators::{MutationResult, Mutator},
    random_corpus_id,
    state::{HasCorpus, HasMetadata, HasRand},
    Error,
};

enum InputValue {
    Bool(u8),
    Integer(i32),
    Real(f32),

}

impl std::fmt::Display for InputValue {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            InputValue::Bool(b) => write!(f, "{}", b),
            InputValue::Integer(i) => write!(f, "{}", i),
            InputValue::Real(r) => write!(f, "{}", r),
        }
    }
}

struct ParsedInput {
    variable_address: String,
    variable_type: VariableType,
    input_value: InputValue,
}

#[derive(Debug)]
enum VariableKind {
    Input,
    Output,
}

#[derive(Debug)]
enum VariableSize {
    Bit,    // (X) 1-bit boolean
    Byte,   // (B) 8-bit integer or boolean
    Word,   // (W) 16-bit integer
    Double, // (D) 32-bit float
    // Long,   // (L) 64-bit integer
}

#[derive(Debug)]
struct VariableType {
    kind: VariableKind,
    size: VariableSize,
    address: (i32, i32),
}

impl ParsedInput {
    fn parse_line(input: &str) -> Option<ParsedInput> {

        // Split the input string into parts
        let parts: Vec<&str> = input.split(',').collect();
        if parts.len() != 3 {
            return None;
        }

        // Parse the variable kind
        let var_kind = parts[0];
        if !var_kind.starts_with('%') || var_kind.len() < 5 {
            return None;
        }

        let kind = match var_kind.chars().nth(1) {
            Some('I') => VariableKind::Input,
            Some('Q') => VariableKind::Output,
            _ => return None,
        };

        let size = match var_kind.chars().nth(2) {
            Some('X') => VariableSize::Bit,
            Some('B') => VariableSize::Byte,
            Some('W') => VariableSize::Word,
            Some('D') => VariableSize::Double,
            _ => return None,
        };

        let address_parts: Vec<&str> = var_kind[3..].split('.').collect();
        if address_parts.len() != 2 {
            return None;
        }

        let address = (
            address_parts[0].parse::<i32>().ok()?,
            address_parts[1].parse::<i32>().ok()?,
        );

        let variable_type = VariableType {
            kind,
            size,
            address,
        };


        // Parse the input value baed on the variable type
        let input_value = match parts[1].trim() {
            "BOOL" => InputValue::Bool(parts[2].parse::<u8>().ok()?),
            "INT" => InputValue::Integer(parts[2].parse::<i32>().ok()?),
            "REAL" => InputValue::Real(parts[2].parse::<f32>().ok()?),
            _ => return None,
        };

        Some(ParsedInput {
            variable_address: parts[0].to_string(),
            variable_type,
            input_value,
        })
    }

    fn parse(corpus_input: &str) -> Vec<Option<ParsedInput>> {

        // return a vector of parsed inputs
        return corpus_input
            .lines()
            .map(|line| ParsedInput::parse_line(line))
            .filter(|parsed_input| parsed_input.is_some())
            .collect();

    }

    // fn mutate(&mut self) {
    //     let mut rng = rand::thread_rng();
    //     match self.variable_type.size {
    //         VariableSize::Bit => {
    //             // For a bit, flip the boolean value
    //             self.input_value = InputValue::Bool(rng.between(0, 1) as u8);
    //         }
    //         VariableSize::Byte => {
    //             // For a byte, generate a random 8-bit number
    //             self.input_value = InputValue::Integer(rng.between(0, 255) as i32)
    //         }
    //         VariableSize::Word => {
    //             // For a word, generate a random 16-bit number
    //             self.input_value = InputValue::Integer(rng.between(0, 65535) as i32);
    //         }
    //         VariableSize::Double => {
    //             // For a double word, generate a random 32-bit float number
    //             self.input_value = InputValue::Real(rng.between(0, 65535) as f32);
    //         }
    //     }
    // }
}

fn format_variable_type(var_type: &VariableType) -> String {
    let kind_char = match var_type.kind {
        VariableKind::Input => 'I',
        VariableKind::Output => 'Q',
    };
    let size_char = match var_type.size {
        VariableSize::Bit => 'X',
        VariableSize::Byte => 'B',
        VariableSize::Word => 'W',
        VariableSize::Double => 'D',
    };
    format!(
        "%{}{}{}.{}",
        kind_char, size_char, var_type.address.0, var_type.address.1
    )
}

#[derive(Debug)]
pub struct PLCRandomInputMutator {
    rng: rand::rngs::ThreadRng,
}

impl PLCRandomInputMutator {
    pub fn new() -> Self {
        PLCRandomInputMutator {
            rng: thread_rng(),
        }
    }
}

// #[derive(Default, Debug)]
// pub struct PLCRandomInputMutator ;

// impl PLCRandomInputMutator {
//     pub fn new() -> Self {
//        Self
//     }
// }

impl Named for PLCRandomInputMutator {
    fn name(&self) -> &str {
        "PLCRandomInputMutator"
    }
}

impl<I, S> Mutator<I, S> for PLCRandomInputMutator
where
    I: HasBytesVec,
    S: HasRand + HasCorpus + HasRand
{
    fn mutate(
        &mut self,
        state: &mut S,
        input: &mut I,
        _stage_idx: i32,
    ) -> Result<MutationResult, Error> {
        // Convert your input to string
        let input_str = str::from_utf8(input.bytes())?;
        // let rng = state.rand_mut();
        let rng = &mut self.rng;
        let parsed_inputs = ParsedInput::parse(input_str);
        if parsed_inputs.len() > 0 {
            let mut mutated_input_strings = Vec::new();
            for parsed_input in parsed_inputs.iter().filter_map(|x| x.as_ref()) {
                // Apply mutations
                // parsed_input.mutate(state.rand_mut());
                // let rng = &mut self.rng;
                let mut input_value: InputValue;
                match parsed_input.variable_type.size {
                    VariableSize::Bit => {
                        // For a bit, flip the boolean value
                        // parsed_input.input_value = InputValue::Bool(rng.between(0, 1) as u8);
                        input_value = InputValue::Bool(rng.gen_range(0..=1) as u8);
                    }
                    VariableSize::Byte => {
                        // For a byte, generate a random 8-bit number
                        // parsed_input.input_value = InputValue::Integer(rng.between(0, 255) as i32);
                        input_value = InputValue::Integer(rng.gen::<u8>() as i32);
                    }
                    VariableSize::Word => {
                        // For a word, generate a random 16-bit number
                        // parsed_input.input_value = InputValue::Integer(rng.between(0, 65535) as i32);
                        input_value = InputValue::Integer(rng.gen::<u8>() as i32);
                    }
                    VariableSize::Double => {
                        // For a double word, generate a random 32-bit float number
                        // parsed_input.input_value = InputValue::Real(rng.between(0, 65535) as f32);
                        input_value = InputValue::Real(rng.gen_range(-1e3..1e3) as f32);
                    }
                }

                let input_type = match input_value {
                    InputValue::Bool(_) => "BOOL",
                    InputValue::Integer(_) => "INT",
                    InputValue::Real(_) => "REAL",
                    _ => "",
                };

                // Convert the mutated input back to a string
                let mutated_input_str = format!(
                    "{},{},{}",
                    parsed_input.variable_address,
                    input_type,
                    input_value
                );
                mutated_input_strings.push(mutated_input_str);
            }

            let mutated_input_str = mutated_input_strings.join("\n");

            // Convert string to bytes
            let mutated_input_bytes = mutated_input_str.into_bytes();

            // Replace the fuzzer's current input with the mutated bytes
            // let input_vec = input.bytes_mut();
            // *input_vec = mutated_input_bytes;
            *input.bytes_mut() = mutated_input_bytes;

            Ok(MutationResult::Mutated)
        } else {
            Ok(MutationResult::Skipped)
        }
    }
}
