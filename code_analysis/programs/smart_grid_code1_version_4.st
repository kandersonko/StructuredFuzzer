PROGRAM PLC_PRG

VAR

CODE_1 : Code_1 ; //Instance of function Code_1

IN1 : LREAL;

IN2 : LREAL;

IN3 : LREAL;

IN4 : LREAL;

IN5 : LREAL;

IN6 : LREAL;

IN7 : LREAL;

END_VAR

IN1 := 5;

IN2 := 5 ;

IN3 := 5 ;

IN4 := 5 ;

IN5 := 5 ;

IN6 := 5 ;

IN7 := 5 ;

CODE_1 (In1 := IN1, In2 := IN2, In3 := IN3, In4 := IN4, In5 := IN5, In6
:= IN6, In7 := IN7);

FUNCTION_BLOCK Code_1

VAR_INPUT

In1: LREAL;

In2: LREAL;

In3: LREAL;

In4: LREAL;

In5: LREAL;

In6: LREAL;

In7: LREAL;

END_VAR

VAR_OUTPUT

Out1: ARRAY[0..1] OF BOOL;

Out2: BOOL;

END_VAR

VAR

Input_Multip : LREAL ;

Input_Multip_int : DINT ;

rtb_Switch: LREAL;

rtb_RelationalOperator: BOOL;

Array_: ARRAY [1..100] OF LREAL := [100(10)];

END_VAR

(* Outputs for Atomic SubSystem: '<Root>/Code_1' *)

(* Switch: '<S1>/Switch' incorporates:

* Gain: '<S1>/Gain2'

* Product: '<S1>/Product'

* Sum: '<S1>/Sum'

* Trigonometry: '<S1>/Trigonometric Function' *)

Input_Multip := In1 * In2 * In3 * In4 * In5 * In6 * In7 ;

Input_Multip_int := LREAL_TO_DINT (Input_Multip);

Array_ [Input_Multip_int] := Input_Multip;

IF In5 >= 0.5 THEN

rtb_Switch := SIN(((0.017453292519943295 * In3) + In2) + In4) * In1;

ELSE

rtb_Switch := In6;

END_IF;

(* End of Switch: '<S1>/Switch' *)

(* RelationalOperator: '<S1>/Relational Operator' *)

rtb_RelationalOperator := rtb_Switch >= In7;

(* End of Outputs for SubSystem: '<Root>/Code_1' *)

(* Outport: '<Root>/Out1' incorporates:

* Logic: '<S1>/BL4' *)

Out1[0] := rtb_RelationalOperator;

(* Outputs for Atomic SubSystem: '<Root>/Code_1' *)

Out1[1] := NOT rtb_RelationalOperator;

(* Outport: '<Root>/Out2' incorporates:

* Gain: '<S1>/Gain3'

* RelationalOperator: '<S1>/Relational Operator1' *)

Out2 := ( -rtb_Switch) >= In7;

(* End of Outputs for SubSystem: '<Root>/Code_1' *)