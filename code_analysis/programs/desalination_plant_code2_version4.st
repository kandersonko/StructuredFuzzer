PROGRAM PLC_PRG

VAR

CODE : Code ; //instance of Code

IN1 : LREAL ;

SETPOINT : LREAL ;

END_VAR

IN1 := 100 ;

SETPOINT := 100 ;

CODE (Input := IN1 , Setpoint := SETPOINT);

FUNCTION_BLOCK Code

VAR_INPUT

ssMethodType: SINT;

Setpoint: LREAL;

Input: LREAL;

END_VAR

VAR_OUTPUT

Output: LREAL;

END_VAR

VAR

Index1 : LREAL ;

Index2 : DINT ;

Array_ : ARRAY [1..100] OF LREAL ;

Filter_DSTATE: LREAL;

Integrator_DSTATE: LREAL;

rtb_FilterCoefficient: LREAL;

Output_tmp: LREAL;

END_VAR

CASE ssMethodType OF

SS_INITIALIZE:

(* SystemInitialize for Atomic SubSystem: '<Root>/Code 2' *)

(* InitializeConditions for DiscreteIntegrator: '<S31>/Filter' *)

Filter_DSTATE := 0.0;

(* InitializeConditions for DiscreteIntegrator: '<S36>/Integrator' *)

Integrator_DSTATE := 0.0;

(* End of SystemInitialize for SubSystem: '<Root>/Code 2' *)

SS_STEP:

Index1 := (Input+Setpoint)*1000;

Index2 := LREAL_TO_DINT (Index1);

Array_[Index2] := Index2 + 1000 ;

(* Outputs for Atomic SubSystem: '<Root>/Code 2' *)

(* Gain: '<S39>/Filter Coefficient' incorporates:

* DiscreteIntegrator: '<S31>/Filter'

* Gain: '<S30>/Derivative Gain'

* Sum: '<S31>/SumD' *)

rtb_FilterCoefficient := (0.0 - Filter_DSTATE) * 100.0;

(* Sum: '<S2>/Sum1' incorporates:

* Sum: '<S2>/Sum2' *)

Output_tmp := Setpoint - Input;

(* Outport: '<Root>/Output' incorporates:

* DiscreteIntegrator: '<S36>/Integrator'

* Gain: '<S41>/Proportional Gain'

* Sum: '<S2>/Sum1'

* Sum: '<S45>/Sum' *)

Output := ((Output_tmp * 50.0) + Integrator_DSTATE) +
rtb_FilterCoefficient;

(* Update for DiscreteIntegrator: '<S31>/Filter' *)

Filter_DSTATE := (0.2 * rtb_FilterCoefficient) + Filter_DSTATE;

(* Update for DiscreteIntegrator: '<S36>/Integrator' incorporates:

* Gain: '<S33>/Integral Gain' *)

Integrator_DSTATE := ((Output_tmp * 10.0) * 0.2) + Integrator_DSTATE;

(* End of Outputs for SubSystem: '<Root>/Code 2' *)

END_CASE;