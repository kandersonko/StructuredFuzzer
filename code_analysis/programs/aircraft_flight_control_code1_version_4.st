PROGRAM PLC_PRG

VAR

CODE4: Code4 ; // instance of Code4

STICKINPUTIN: LREAL;

IN2: LREAL;

IN3: LREAL;

IN4: LREAL;

END_VAR

STICKINPUTIN:= 100 ;

IN2:= 100;

IN3:= 100;

IN4:= 100;

CODE4 (StickInputin := STICKINPUTIN,In2 := IN2 , In3 := IN3 , In4:= IN4
);

FUNCTION_BLOCK Code4

VAR_INPUT

StickInputin: LREAL;

In2: LREAL;

In3: LREAL;

In4: LREAL;

END_VAR

VAR_OUTPUT

Out1: LREAL;

Out2: LREAL;

END_VAR

VAR

Index1 : LREAL ;

Index2 : DINT ;

Array_: ARRAY [1..100] OF LREAL ;

INPUTTOINDEX : InputToIndex; //instance of InputsToIndex3

END_VAR

Index1 := (In2)+(In3)+(In4);

Index2 := LREAL_TO_INT (Index1);

Array_[Index2] := StickInputin;

INPUTTOINDEX(Input2:= In2,Input3:= In3,Input4:= In4);

(* Outputs for Atomic SubSystem: '<Root>/Code 1' *)

(* Sum: '<S1>/Sum2' incorporates:

* Gain: '<S1>/Gain2'

* Gain: '<S1>/Gain3'

* Sum: '<S1>/Sum1' *)

Out1 := StickInputin - ((0.8156 * In4) + (0.677 * In3));

(* Outport: '<Root>/Out2' incorporates:

* Gain: '<S1>/Gain'

* Sum: '<S1>/Sum' *)

Out2 := (-1.746 * Out1) + In2;

(* End of Outputs for SubSystem: '<Root>/Code 1' *)

FUNCTION_BLOCK InputToIndex

VAR_INPUT

Input2 : LREAL ;

Input3 : LREAL ;

Input4 : LREAL ;

END_VAR

VAR_OUTPUT

Array_ : ARRAY [1..100] OF LREAL ;

END_VAR

VAR

Index1 : LREAL ;

Index2 : DINT ;

i : DINT;

END_VAR

Index1 := Input2*Input3*Input4 ;

Index2 := LREAL_TO_DINT (Index1);

FOR i:= 0 TO Index2 DO

Array_[i] := Index2 + i ;

END_FOR
