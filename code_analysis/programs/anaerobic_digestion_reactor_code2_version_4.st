PROGRAM PLC_PRG

VAR

CODE : Code ;

IN1 : LREAL ;

IN2 : LREAL ;

END_VAR

IN1 := 100 ;

IN2 := 100 ;

CODE (In1 := IN1 , In2 := IN2 );

FUNCTION_BLOCK Code

VAR_INPUT

In1: LREAL;

In2: LREAL;

END_VAR

VAR_OUTPUT

Out1: LREAL;

END_VAR

VAR

INPUTTOINDEX1 : InputToIndex1 ; //Instance of InputToIndex1 function

INPUTTOINDEX2 : InputToIndex2 ; //Instance of InputToIndex1 function

END_VAR

(* Outputs for Atomic SubSystem: '<Root>/Code 2' *)

(* Sum: '<S1>/Sum3' *)

Out1 := In1 + In2;

(* Saturate: '<S1>/Sat Block (Psig)' *)

INPUTTOINDEX1(Input1 := In1 , Input2 := In2) ;

INPUTTOINDEX2(Input1 := In1 , Input2 := In2);

IF Out1 >= 3.6 THEN

Out1 := 3.6;

ELSIF Out1 <= -8.4 THEN

Out1 := -8.4;

END_IF;

(* End of Saturate: '<S1>/Sat Block (Psig)' *)

(* Gain: '<S1>/Heat input Valve' *)

Out1 := 0.1667 * Out1;

(* Saturate: '<S1>/Valve Limits' *)

IF Out1 <= -1.4 THEN

(* Outport: '<Root>/Out1' *)

Out1 := -1.4;

END_IF;

(* End of Saturate: '<S1>/Valve Limits' *)

(* End of Outputs for SubSystem: '<Root>/Code 2' *)

FUNCTION_BLOCK InputToIndex1

VAR_INPUT

Input1 : LREAL ;

Input2 : LREAL ;

END_VAR

VAR_OUTPUT

Array_ : ARRAY [0..1000] OF LREAL ;

END_VAR

VAR

Index1 : LREAL ;

Index2 : DINT ; //32 BITS

i : DINT;

END_VAR

Index1 := ((Input1)*(Input2));

Index2 := LREAL_TO_DINT (Index1);

FOR i:= 0 TO Index2 DO

Array_[i] := Index2 + i ;

END_FOR

FUNCTION_BLOCK InputToIndex2

VAR_INPUT

Input1 : LREAL ;

Input2 : LREAL ;

END_VAR

VAR_OUTPUT

Array_ : ARRAY [0..100] OF LREAL ;

END_VAR

VAR

Index1 : LREAL ;

Index2 : DINT ; //32 BITS

END_VAR

Index1 := ((Input1)*(Input2));

Index2 := LREAL_TO_DINT (Index1);

Array_[Index2] := Index2 ;
