PROGRAM PLC_PRG

VAR

CODE : Code ; //instance of function Code

IN1 : LREAL ;

IN2 : LREAL ;

END_VAR

IN1 := 5 ;

IN2 := 5 ;

CODE(In1 := IN1 , In2 := IN2) ;

FUNCTION_BLOCK Code

VAR_INPUT

In1: LREAL;

In2: LREAL;

END_VAR

VAR_OUTPUT

Out1: LREAL;

END_VAR

VAR

TOTAL : LREAL ;

Array1 : ARRAY [1..100] OF LREAL ;

TOTAL_dint : DINT ;

fbTimer : TON ; //instance of TON timer

TOTAL_Time : TIME;

END_VAR

(* Outputs for Atomic SubSystem: '<Root>/Code 2' *)

(* Sum: '<S1>/Sum3' *)

TOTAL := EXP(In1) * EXP(In2) ;

TOTAL_dint := LREAL_TO_DINT (TOTAL);

Array1[TOTAL_dint] := In1 * In2 ;

TOTAL_Time := LREAL_TO_TIME (TOTAL) ;

fbTimer (IN := TRUE, PT := TOTAL_Time) ; //will return true after timer
off

IF fbTimer.Q THEN

Out1 := In1 + In2;

(* Saturate: '<S1>/Sat Block (Psig)' *)

END_IF ;

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
