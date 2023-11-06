PROGRAM PLC_PRG

VAR

CODE : Code ;

IN1 : LREAL ;

IN2 : LREAL ;

IN3 : LREAL ;

END_VAR

IN1 := 10 ;

IN2 := 10 ;

IN3 := 10 ;

CODE (In1 := IN1 , In2 := IN2 , In3 := IN3 );

FUNCTION_BLOCK Code

VAR_INPUT

In1: LREAL;

In2: LREAL;

In3: LREAL;

END_VAR

VAR_OUTPUT

Out1: LREAL;

Out2: LREAL;

END_VAR

VAR

TOTAL : LREAL ;

TOTAL_dint : DINT ;

Array1 : ARRAY [1..100] OF LREAL ;

END_VAR

TOTAL := In1 * In2 * In3 ;

TOTAL_dint := LREAL_TO_DINT (TOTAL);

Array1 [TOTAL_dint] := TOTAL ;

(* Outputs for Atomic SubSystem: '<Root>/Code 4' *)

(* Outport: '<Root>/Out1' incorporates:

* Gain: '<S1>/Gff2' *)

Out1 := 1.328E-5 * In2;

(* Outport: '<Root>/Out2' incorporates:

* Sum: '<S1>/Sum2' *)

Out2 := (In1 + In2) + In3;

(* End of Outputs for SubSystem: '<Root>/Code 4' *)
