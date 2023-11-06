PROGRAM PLC_PRG

VAR

CODE3 : Code3 ; //instance of Code3

ssMethodType_INPUT :SINT ;

IN1 : LREAL ;

END_VAR

ssMethodType_INPUT := 1 ;

IN1 := 50 ;

CODE3 (ssMethodType := ssMethodType_INPUT, In1 := IN1);

FUNCTION_BLOCK Code3

VAR_INPUT

ssMethodType: SINT;

In1: LREAL;

END_VAR

VAR_OUTPUT

y: LREAL;

END_VAR

VAR

Square: LREAL;

Filter_DSTATE: LREAL;

Integrator_DSTATE: LREAL;

rtb_Subtract: LREAL;

rtb_FilterCoefficient: LREAL;

Index1 : LREAL ;

Index2 : DINT ;

Array_ : ARRAY [1..100] OF LREAL ;

END_VAR

CASE ssMethodType OF

GVL_CONSTS.SS_INITIALIZE:

(* SystemInitialize for Atomic SubSystem: '<Root>/Code 2' *)

(* InitializeConditions for DiscreteIntegrator: '<S29>/Filter' *)

Filter_DSTATE := 0.0;

(* InitializeConditions for DiscreteIntegrator: '<S34>/Integrator' *)

Integrator_DSTATE := 0.0;

(* End of SystemInitialize for SubSystem: '<Root>/Code 2' *)

(* ConstCode for Atomic SubSystem: '<Root>/Code 2' *)

(* ConstCode for Math: '<S1>/Square' incorporates:

* Constant: '<S1>/Constant' *)

Square := 458751.02394617227;

(* End of ConstCode for SubSystem: '<Root>/Code 2' *)

GVL_CONSTS.SS_STEP:

(* Outputs for Atomic SubSystem: '<Root>/Code 2' *)

(* Sum: '<S1>/Subtract' incorporates:

* Math: '<S1>/Square1' *)

Index1 := In1*In1;

Index2 := LREAL_TO_DINT (Index1);

Array_[Index2] := Index2 + 1000 ;

rtb_Subtract := Square - (In1 * In1);

(* Gain: '<S37>/Filter Coefficient' incorporates:

* DiscreteIntegrator: '<S29>/Filter'

* Gain: '<S28>/Derivative Gain'

* Sum: '<S29>/SumD' *)

rtb_FilterCoefficient := ((0.10932922971946307 * rtb_Subtract) -
Filter_DSTATE) * 3.8620401712747761;

(* Outport: '<Root>/y' incorporates:

* DiscreteIntegrator: '<S34>/Integrator'

* Gain: '<S39>/Proportional Gain'

* Sum: '<S43>/Sum' *)

y := ((2.5899754807860003 * rtb_Subtract) + Integrator_DSTATE) +
rtb_FilterCoefficient;

(* Update for DiscreteIntegrator: '<S29>/Filter' *)

Filter_DSTATE := (5.0E-6 * rtb_FilterCoefficient) + Filter_DSTATE;

(* Update for DiscreteIntegrator: '<S34>/Integrator' incorporates:

* Gain: '<S31>/Integral Gain' *)

Integrator_DSTATE := ((19.365373103211319 * rtb_Subtract) * 5.0E-6) +
Integrator_DSTATE;

(* End of Outputs for SubSystem: '<Root>/Code 2' *)

END_CASE;
