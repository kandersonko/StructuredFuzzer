PROGRAM PLC_PRG

VAR

CODE : Code ; //instance of Code

IN1 : LREAL ;

IN2 : LREAL ;

IN3 : LREAL ;

END_VAR

IN1 := 50 ;

IN2 := 50 ;

IN3 := 50 ;

CODE (In1 := IN1 ,In2 := IN2 , In3 := IN3 );

FUNCTION_BLOCK Code

VAR_INPUT

In1: LREAL;

In2: LREAL;

In3: LREAL;

END_VAR

VAR_OUTPUT

Out1: LREAL;

Out2: LREAL;

Out3: LREAL;

END_VAR

VAR

Index1 : LREAL ;

Index2 : DINT ;

Array_ : ARRAY [1..100] OF LREAL ;

END_VAR

Index1 := (In1+In2+In3);

Index2 := LREAL_TO_DINT (Index1);

Array_[Index2] := Index2 ;

(* Outputs for Atomic SubSystem: '<Root>/Code 3' *)

(* Outport: '<Root>/Out1' incorporates:

* Constant: '<S1>/Bo, (ton//min)'

* Sum: '<S1>/Sum' *)

Out1 := In1 + 217.25;

(* Outport: '<Root>/Out2' incorporates:

* Constant: '<S1>/Tf, (C)'

* Sum: '<S1>/Sum1' *)

Out2 := In2 + 35.0;

(* Outport: '<Root>/Out3' incorporates:

* Constant: '<S1>/Ws, (kg//min)'

* Sum: '<S1>/Sum2' *)

Out3 := In3 + 2453.6;

(* End of Outputs for SubSystem: '<Root>/Code 3' *)
