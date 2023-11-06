PROGRAM PLC_PRG

VAR

CODE : Code ; //instance of function block code

IN1 : LREAL ;

END_VAR

IN1 := 50 ;

CODE(In1 := IN1 ) ;

FUNCTION_BLOCK Code

VAR_INPUT

In1: LREAL;

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

TOTAL := (In1)* 1000 ;

TOTAL_dint := LREAL_TO_DINT (TOTAL);

Array1[TOTAL_dint] := In1 ;

TOTAL_Time := LREAL_TO_TIME (TOTAL) ;

fbTimer (IN := TRUE, PT := TOTAL_Time) ; //will return true after timer
off

IF fbTimer.Q THEN

(* Outputs for Atomic SubSystem: '<Root>/Code 3' *)

(* Gain: '<S1>/T-Sensor' *)

Out1 := 0.32 * In1;

(* Saturate: '<S1>/Sat Block (mA) - S' *)

END_IF ;

IF Out1 >= 4.8 THEN

(* Outport: '<Root>/Out1' *)

Out1 := 4.8;

ELSIF Out1 <= -11.2 THEN

(* Outport: '<Root>/Out1' *)

Out1 := -11.2;

END_IF;

(* End of Saturate: '<S1>/Sat Block (mA) - S' *)

(* End of Outputs for SubSystem: '<Root>/Code 3' *)
