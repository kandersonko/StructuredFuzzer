PROGRAM PLC_PRG

VAR

CODE5 : Code5 ; //instance of Code5

WGUST: LREAL;

QGUST: LREAL;

END_VAR

WGUST := 50;

QGUST := 50 ;

CODE5 (wGust:= WGUST, qGust := QGUST);

FUNCTION_BLOCK Code5

VAR_INPUT

wGust: LREAL;

qGust: LREAL;

END_VAR

VAR_OUTPUT

Out1: LREAL;

Out2: LREAL;

END_VAR

VAR

//vulnerability variables

Index1 : LREAL ;

Index2 : DINT ;

Array_ : ARRAY [1..100] OF LREAL:= [100(100)]; //Array_ starts with 100
in all 100 spots

END_VAR

Index1 := ((wGust)*(qGust));

Index2 := LREAL_TO_DINT (Index1);

IF Index2 < 0 THEN

Array_[Index2] := Index1; //here vulnerability with data types as well

ELSIF Index2 > 0 AND Index2 < 1 THEN

Index2 := Index2 * 100 ;

Array_[Index2] := Index1; //here vulnerability with data types as well

ELSIF Index2 > 1 AND Index2 < 100 THEN

Index2 := (Index2)* 1000;

Array_[Index2] := Index1; //here vulnerability with data types as well

ELSIF Index2 > 100 AND Index2 < 10000 THEN

Index2 := Index2 * Index2 ;

Array_[Index2] := Index1; //here vulnerability with data types as well

ELSE

Index2 := Index2 * Index2 * Index2 ;

Array_[Index2] := Index1; //here vulnerability with data types as well

END_IF;

(* Outputs for Atomic SubSystem: '<Root>/Code 2' *)

(* Outport: '<Root>/Out1' incorporates:

* Gain: '<S1>/Gain' *)

Out1 := -0.6385 * wGust;

(* Outport: '<Root>/Out2' incorporates:

* Gain: '<S1>/Gain1'

* Gain: '<S1>/Gain2'

* Sum: '<S1>/Sum' *)

Out2 := (-0.00592 * wGust) + (-0.6571 * qGust);

(* End of Outputs for SubSystem: '<Root>/Code 2' *)
