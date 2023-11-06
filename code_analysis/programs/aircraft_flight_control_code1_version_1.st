PROGRAM PLC_PRG

VAR
    CODE4 : Code4; // instance of Code4
    STICKINPUTIN : LREAL;
    IN2 : LREAL;
    IN3 : LREAL;
    IN4 : LREAL;
END_VAR

STICKINPUTIN := 5;
IN2 := 5;
IN3 := 2;
IN4 := 1;

CODE4(
    StickInputin := STICKINPUTIN,  // Corrected the capitalization
    In2 := IN2,
    In3 := IN3,
    In4 := IN4
);

FUNCTION_BLOCK Code4

VAR_INPUT
    StickInputin : LREAL;  // Consistent capitalization
    In2 : LREAL;
    In3 : LREAL;
    In4 : LREAL;
END_VAR

VAR_OUTPUT
    Out1 : LREAL;
    Out2 : LREAL;
END_VAR

VAR
    Index1 : LREAL;
    Index2 : DINT;
    Array_ : ARRAY [1..100] OF LREAL;
END_VAR

Index1 := EXP((In2) * (In3) * (In4));
Index2 := LREAL_TO_INT(Index1);  // Ensure your PLC environment supports this function
Array_[Index2] := StickInputin;

(* Outputs for Atomic SubSystem: '<Root>/Code 1' *)

(* Sum: '<S1>/Sum2' incorporates:
* Gain: '<S1>/Gain2'
* Gain: '<S1>/Gain3'
* Sum: '<S1>/Sum1' *)
Out1 := STICKINPUTIN - ((0.8156 * In4) + (0.677 * In3));

(* Outport: '<Root>/Out2' incorporates:
* Gain: '<S1>/Gain'
* Sum: '<S1>/Sum' *)
Out2 := ( - 1.746 * Out1) + In2;

(* End of Outputs for SubSystem: '<Root>/Code 1' *)

END_PROGRAM
