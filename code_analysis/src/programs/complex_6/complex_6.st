PROGRAM AutomatedFireSuppressionSystem
VAR
    smokeDetected : BOOL;         // Flag indicating if smoke is detected
    heatDetected : BOOL;          // Flag indicating if excessive heat is detected
    fireAlarmOn : BOOL;           // Flag indicating if the fire alarm is on
    sprinklerSystemActivated : BOOL; // Flag indicating if the sprinkler system is activated
    emergencyServicesNotified : BOOL; // Flag indicating if emergency services have been notified
END_VAR

// Dummy functions for sensor readings and control actions
PROCEDURE DetectSmoke() : BOOL; BEGIN END_PROCEDURE;
PROCEDURE DetectHeat() : BOOL; BEGIN END_PROCEDURE;
PROCEDURE ActivateFireAlarm(); BEGIN END_PROCEDURE;
PROCEDURE DeactivateFireAlarm(); BEGIN END_PROCEDURE;
PROCEDURE ActivateSprinklerSystem(); BEGIN END_PROCEDURE;
PROCEDURE DeactivateSprinklerSystem(); BEGIN END_PROCEDURE;
PROCEDURE NotifyEmergencyServices(); BEGIN END_PROCEDURE;
PROCEDURE DoNotNotifyEmergencyServices(); BEGIN END_PROCEDURE;

// Main logic
smokeDetected := DetectSmoke();
heatDetected := DetectHeat();

// Logical Bug: Incorrect logic combination for fire detection and response
// The system should activate if EITHER smoke or heat is detected, not necessarily both
IF smokeDetected AND heatDetected THEN
    ActivateFireAlarm();
    ActivateSprinklerSystem();
    NotifyEmergencyServices();
    fireAlarmOn := TRUE;
    sprinklerSystemActivated := TRUE;
    emergencyServicesNotified := TRUE;
ELSE
    DeactivateFireAlarm();
    DeactivateSprinklerSystem();
    DoNotNotifyEmergencyServices();
    fireAlarmOn := FALSE;
    sprinklerSystemActivated := FALSE;
    emergencyServicesNotified := FALSE;
END_IF
END_PROGRAM
