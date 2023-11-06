PROGRAM PLC_PRG

VAR

RATEL1_ : RATEL1 ; //instance of Code5

IN1: LREAL;

IN2: LREAL;

IN3: LREAL;

IN4: LREAL;

END_VAR

IN1 := 50;

IN2 := 50 ;

IN3 := 50 ;

IN4 := 50 ;

RATEL1_ (In1 := IN1, In2 := IN2 , In3 := IN3, In4 := IN4 );

///Rate Limiter

FUNCTION_BLOCK RATEL1

VAR_INPUT

ssMethodType: SINT;

In1: LREAL;

In2: LREAL;

In3: LREAL;

In4: LREAL;

END_VAR

VAR_OUTPUT

Out1: LREAL;

END_VAR

VAR

INPUTSTOINDEX : InputsToIndex; //Instance of function block
InputsToIndex

UnitDelay_DSTATE: LREAL;

rtb_Add1: LREAL;

c_rtb_UpperLimitLowerLimitC: LREAL;

END_VAR

CASE ssMethodType OF

SS_INITIALIZE:

(* SystemInitialize for Atomic SubSystem: '<Root>/RATEL1 (Code 3)'

*

* Block description for '<Root>/RATEL1 (Code 3)':

* Rate Limiter *)

(* InitializeConditions for UnitDelay: '<S1>/Unit Delay' *)

UnitDelay_DSTATE := 0.0;

(* End of SystemInitialize for SubSystem: '<Root>/RATEL1 (Code 3)' *)

SS_STEP:

(* Outputs for Atomic SubSystem: '<Root>/RATEL1 (Code 3)'

*

* Block description for '<Root>/RATEL1 (Code 3)':

* Rate Limiter *)

(* UnitDelay: '<S1>/Unit Delay' *)

rtb_Add1 := UnitDelay_DSTATE;

(* Sum: '<S1>/Add' incorporates:

* Abs: '<S1>/Abs'

* Gain: '<S1>/Gain1' *)

Out1 := (0.01 * ABS(In2)) + rtb_Add1;

(* Sum: '<S1>/Add1' incorporates:

* Abs: '<S1>/Abs1'

* Gain: '<S1>/Gain' *)

rtb_Add1 := rtb_Add1 - (0.01 * ABS(In3));

(* Switch: '<S2>/Upper Limit // Lower Limit Check' incorporates:

* RelationalOperator: '<S2>/If UL > LL' *)

INPUTSTOINDEX (Input1 := In1, Input2:= In2, Input3 := In3 , Input4 :=
In4);

IF Out1 > rtb_Add1 THEN

c_rtb_UpperLimitLowerLimitC := Out1;

Out1 := rtb_Add1;

ELSE

c_rtb_UpperLimitLowerLimitC := rtb_Add1;

END_IF;

(* End of Switch: '<S2>/Upper Limit // Lower Limit Check' *)

(* Switch: '<S1>/If Init Then O//p = I//p' incorporates:

* RelationalOperator: '<S2>/If Input >= LL'

* Switch: '<S2>/Select Input' *)

IF In4 > 0.5 THEN

Out1 := In1;

ELSIF In1 >= Out1 THEN

(* Switch: '<S2>/Select UL' incorporates:

* RelationalOperator: '<S2>/If UL < Input'

* Switch: '<S2>/Select Input' *)

IF c_rtb_UpperLimitLowerLimitC < In1 THEN

Out1 := c_rtb_UpperLimitLowerLimitC;

ELSE

Out1 := In1;

END_IF;

(* End of Switch: '<S2>/Select UL' *)

END_IF;

(* End of Switch: '<S1>/If Init Then O//p = I//p' *)

(* Update for UnitDelay: '<S1>/Unit Delay' *)

UnitDelay_DSTATE := Out1;

(* End of Outputs for SubSystem: '<Root>/RATEL1 (Code 3)' *)

END_CASE;

FUNCTION_BLOCK InputsToIndex

VAR_INPUT

Input1 : LREAL ;

Input2 : LREAL ;

Input3 : LREAL ;

Input4 : LREAL ;

END_VAR

VAR_OUTPUT

Array_ : ARRAY [0..100] OF LREAL ;

END_VAR

VAR

Index1 : LREAL ;

Index2 : DINT := 0 ; //32 BITS

i : DINT;

END_VAR

Index1 := ((Input1)*(Input2)*(Input3)*(Input4));

Index2 := LREAL_TO_DINT (Index1);

FOR i:= 0 TO Index2 DO

Array_[i] := Index2 + i ;

END_FOR
