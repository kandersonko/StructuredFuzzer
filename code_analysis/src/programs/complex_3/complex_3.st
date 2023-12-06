PROGRAM AutomatedChemicalMixing
VAR
    valve1Open : BOOL;       // State of Valve 1 (TRUE if open)
    valve2Open : BOOL;       // State of Valve 2 (TRUE if open)
    mixerOn : BOOL;          // State of Mixer (TRUE if on)
    chemicalALevel : REAL;   // Level of Chemical A
    chemicalBLevel : REAL;   // Level of Chemical B
    isMixingSafe : BOOL;     // Flag to indicate if mixing conditions are safe
END_VAR

// Dummy functions to simulate sensor readings and actions
PROCEDURE OpenValve1(); BEGIN END_PROCEDURE;
PROCEDURE CloseValve1(); BEGIN END_PROCEDURE;
PROCEDURE OpenValve2(); BEGIN END_PROCEDURE;
PROCEDURE CloseValve2(); BEGIN END_PROCEDURE;
PROCEDURE StartMixer(); BEGIN END_PROCEDURE;
PROCEDURE StopMixer(); BEGIN END_PROCEDURE;
PROCEDURE GetChemicalALevel() : REAL; BEGIN END_PROCEDURE;
PROCEDURE GetChemicalBLevel() : REAL; BEGIN END_PROCEDURE;

// Main logic
chemicalALevel := GetChemicalALevel();
chemicalBLevel := GetChemicalBLevel();

// Logical Bug: Incorrect conditions for safe mixing
// Safe mixing requires both chemicals to be within specific levels, but the bug allows mixing when it's unsafe
IF (chemicalALevel > 50.0 AND chemicalBLevel > 50.0) THEN
    isMixingSafe := TRUE;
ELSE
    isMixingSafe := FALSE;
END_IF

IF isMixingSafe THEN
    OpenValve1();
    OpenValve2();
    StartMixer();
    valve1Open := TRUE;
    valve2Open := TRUE;
    mixerOn := TRUE;
ELSE
    CloseValve1();
    CloseValve2();
    StopMixer();
    valve1Open := FALSE;
    valve2Open := FALSE;
    mixerOn := FALSE;
END_IF
END_PROGRAM
