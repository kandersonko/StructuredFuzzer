PROGRAM AutomatedReactorControl
VAR
    reactorMode : INT;             // Operational mode of the reactor (1 for startup, 2 for normal, 3 for shutdown, 4 for emergency)
    coolantFlowRate : REAL;        // Coolant flow rate (in liters per second)
    controlRodPosition : REAL;     // Position of control rods (0% to 100%, where 100% is fully inserted)
    alarmActivated : BOOL;         // State of the alarm system
END_VAR

// Dummy functions for control actions
PROCEDURE SetCoolantFlowRate(rate : REAL); BEGIN END_PROCEDURE;
PROCEDURE SetControlRodPosition(position : REAL); BEGIN END_PROCEDURE;
PROCEDURE ActivateAlarm(); BEGIN END_PROCEDURE;
PROCEDURE DeactivateAlarm(); BEGIN END_PROCEDURE;

// Main logic
// Logical Bug: Inappropriate control rod and coolant flow adjustments for some reactor modes
CASE reactorMode OF
    1: // Startup mode
        coolantFlowRate := 30.0;   // Moderate coolant flow
        controlRodPosition := 20.0; // Partially withdrawn control rods
    2: // Normal operation mode
        coolantFlowRate := 50.0;   // High coolant flow
        controlRodPosition := 50.0; // Halfway inserted control rods
    3: // Shutdown mode
        coolantFlowRate := 20.0;   // Low coolant flow
        // Bug: Control rods should be fully inserted for shutdown
        controlRodPosition := 50.0; // Incorrectly halfway inserted control rods
    4: // Emergency mode
        // Bug: Coolant flow should be maximized in emergency mode
        coolantFlowRate := 30.0;   // Insufficient coolant flow for emergency
        controlRodPosition := 100.0; // Fully inserted control rods
        ActivateAlarm();
        alarmActivated := TRUE;
    ELSE
        // Default safe state in case of an unrecognized mode
        ActivateAlarm();
        alarmActivated := TRUE;
        SetCoolantFlowRate(0.0);
        SetControlRodPosition(100.0); // Fully insert control rods
END_CASE

SetCoolantFlowRate(coolantFlowRate);
SetControlRodPosition(controlRodPosition);

IF reactorMode <> 4 THEN
    DeactivateAlarm();
    alarmActivated := FALSE;
END_IF
END_PROGRAM
