PROGRAM AutomatedVentilationControl
VAR
    oxygenLevel : REAL;       // Oxygen concentration in the room (%)
    carbonDioxideLevel : REAL; // Carbon Dioxide concentration in the room (%)
    airFlowRate : REAL;        // Airflow rate into the room (cubic meters per minute)
    alarmActivated : BOOL;     // Alarm state for unsafe conditions
    ventilationOn : BOOL;      // Ventilation system state
END_VAR

// Dummy functions for sensor readings and control actions
PROCEDURE GetOxygenLevel() : REAL; BEGIN END_PROCEDURE;
PROCEDURE GetCarbonDioxideLevel() : REAL; BEGIN END_PROCEDURE;
PROCEDURE SetAirFlowRate(flowRate : REAL); BEGIN END_PROCEDURE;
PROCEDURE ActivateAlarm(); BEGIN END_PROCEDURE;
PROCEDURE DeactivateAlarm(); BEGIN END_PROCEDURE;
PROCEDURE TurnOnVentilation(); BEGIN END_PROCEDURE;
PROCEDURE TurnOffVentilation(); BEGIN END_PROCEDURE;

// Main logic
oxygenLevel := GetOxygenLevel();
carbonDioxideLevel := GetCarbonDioxideLevel();

// Logical Bug: Incorrect thresholds and logic for ventilation control
// The ventilation should turn on if oxygen level is below 21% or CO2 level is above 0.5%
IF (oxygenLevel >= 21.0 AND carbonDioxideLevel <= 0.5) THEN
    TurnOffVentilation();
    ventilationOn := FALSE;
    DeactivateAlarm();
ELSE
    TurnOnVentilation();
    SetAirFlowRate(5.0); // Set a fixed airflow rate
    ventilationOn := TRUE;
    IF (oxygenLevel < 19.0 OR carbonDioxideLevel > 1.0) THEN
        ActivateAlarm();
        alarmActivated := TRUE;
    ELSE
        DeactivateAlarm();
        alarmActivated := FALSE;
    END_IF
END_IF
END_PROGRAM
