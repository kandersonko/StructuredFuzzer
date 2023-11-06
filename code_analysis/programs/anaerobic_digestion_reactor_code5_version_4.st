PROGRAM PLC_PRG

VAR

CODE : Code ; //instance of Code

IN1 : LREAL ;

END_VAR

IN1 := 100 ;

CODE (In1 := IN1);

FUNCTION_BLOCK Code

VAR_INPUT

In1: LREAL;

END_VAR

VAR_OUTPUT

Out1: LREAL;

END_VAR

VAR

TOTAL : LREAL ;

TOTAL_dint : DINT ;

Array_ : ARRAY [1..100] OF LREAL ;

END_VAR

(* Outputs for Atomic SubSystem: '<Root>/Code 5' *)

(* Saturate: '<S1>/Saturation' *)

TOTAL := In1*1000;

TOTAL_dint := LREAL_TO_DINT (TOTAL);

Array_[TOTAL_dint] := TOTAL + 1000 ;

IF In1 >= 6.0 THEN

Out1 := 6.0;

ELSIF In1 > -6.0 THEN

Out1 := In1;

ELSE

Out1 := -6.0;

END_IF;

(* End of Saturate: '<S1>/Saturation' *)

(* Gain: '<S1>/Influent control Valve' *)

Out1 := 3333.33 * Out1;

(* End of Outputs for SubSystem: '<Root>/Code 5' *)
