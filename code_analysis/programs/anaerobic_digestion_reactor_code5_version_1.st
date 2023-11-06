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

INPUTTOINDEX : InputToIndex; //instance of InputsToIndex3

END_VAR

(* Outputs for Atomic SubSystem: '<Root>/Code 5' *)

(* Saturate: '<S1>/Saturation' *)

IF In1 >= 6.0 THEN

Out1 := 6.0;

ELSIF In1 > -6.0 THEN

Out1 := In1;

ELSE

Out1 := -6.0;

END_IF;

(* End of Saturate: '<S1>/Saturation' *)

INPUTTOINDEX(Input1:= In1);

(* Gain: '<S1>/Influent control Valve' *)

Out1 := 3333.33 * Out1;

(* End of Outputs for SubSystem: '<Root>/Code 5' *)

FUNCTION_BLOCK InputToIndex

VAR_INPUT

Input1 : LREAL ;

END_VAR

VAR_OUTPUT

Array_ : ARRAY [1..100] OF LREAL ;

END_VAR

VAR

Index1 : LREAL ;

Index2 : DINT ;

i : DINT;

END_VAR

Index1 := SQRT(Input1);

Index2 := LREAL_TO_DINT (Index1);

FOR i:= 0 TO Index2 DO

Array_[i] := Index2 + i ;

END_FOR
