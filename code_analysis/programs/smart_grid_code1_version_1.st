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

INPUTTOINDEX_3D_1 : InputToIndex_3D ; //first instance of function
InputToIndex_3D

INPUTTOINDEX_3D_2 : InputToIndex_3D ; //second instance OF FUNCTION
InputToIndex_3D

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

IF In5 >= 0.5 THEN

IF Input_Multip > 1000 THEN

INPUTTOINDEX_3D_1(Input1 := In1,Input2 := In2 ,Input3 := In3, Input4 :=
In4, Input5 := In5 , Input6 := In6 , Input7 := In7);

rtb_Switch := SIN(((0.017453292519943295 * In3) + In2) + In4) * In1;

ELSE

INPUTTOINDEX_3D_2(Input1 := In1,Input2 := In2 ,Input3 := In3, Input4 :=
In4, Input5 := In5 , Input6 := In6 , Input7 := In7);

Array_ [Input_Multip_int] := Input_Multip;

rtb_Switch := SIN(((0.017453292519943295 * In3) + In2) + In4) * In1;

END_IF;

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

FUNCTION_BLOCK InputToIndex_3D

VAR_INPUT

Input1 : LREAL ;

Input2 : LREAL ;

Input3 : LREAL ;

Input4 : LREAL ;

Input5 : LREAL ;

Input6 : LREAL ;

Input7 : LREAL ;

END_VAR

VAR_OUTPUT

Array_3D : ARRAY [1..100,1..100,1..100] OF LREAL :=
[100(1),100(1),100(1)];

Array_1D : ARRAY [1..100] OF LREAL := [100(1)];

END_VAR

VAR

Index1 : LREAL ;

Index2 : LREAL ;

Index3 : LREAL ;

Index1_int : DINT := 0;

Index2_int : DINT := 0;

Index3_int : DINT := 0;

i : DINT;

j : DINT ;

k : DINT ;

END_VAR

Index1 := (Input1)*(Input2);

Index2 := (Input3)*(Input4);

Index3 := (Input5)*(Input6);

Index1_int := LREAL_TO_DINT (Index1);

Index2_int := LREAL_TO_DINT (Index2);

Index3_int := LREAL_TO_DINT (Index3);

FOR i:= 0 TO Index1_int DO

FOR j:= 0 TO Index2_int DO

FOR k:= 0 TO Index3_int DO

Array_3D[i,j,k] := Input7;

END_FOR

END_FOR

END_FOR
