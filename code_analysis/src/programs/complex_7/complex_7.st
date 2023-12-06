PROGRAM AutomatedTemperatureControl
VAR
    currentTemperature : REAL;       // Current temperature in the reactor (in Celsius)
    desiredTemperature : REAL := 250.0; // Desired operational temperature (in Celsius)
    coolingSystemActivated : BOOL;    // State of the cooling system
    heatingSystemActivated : BOOL;    // State of the heating system
    alertRaised : BOOL;               // Flag for raising an alert
END_VAR

// Dummy functions for sensor readings and control actions
PROCEDURE GetCurrentTemperature() : REAL; BEGIN END_PROCEDURE;
PROCEDURE ActivateCoolingSystem(); BEGIN END_PROCEDURE;
PROCEDURE DeactivateCoolingSystem(); BEGIN END_PROCEDURE;
PROCEDURE ActivateHeatingSystem(); BEGIN END_PROCEDURE;
PROCEDURE DeactivateHeatingSystem(); BEGIN END_PROCEDURE;
PROCEDURE RaiseAlert(); BEGIN END_PROCEDURE;
PROCEDURE LowerAlert(); BEGIN END_PROCEDURE;

// Main logic
currentTemperature := GetCurrentTemperature();

// Logical Bug: Incorrect arithmetic operations in temperature control logic
// The system should activate cooling if the temperature exceeds the desired level by more than 10 degrees
// and heating if it is below the desired level by more than 10 degrees
IF currentTemperature > (desiredTemperature + 10.0) THEN
    ActivateCoolingSystem();
    coolingSystemActivated := TRUE;
    heatingSystemActivated := FALSE;
ELSEIF currentTemperature < (desiredTemperature - 10.0) THEN
    ActivateHeatingSystem();
    heatingSystemActivated := TRUE;
    coolingSystemActivated := FALSE;
ELSE
    // Bug: Deactivating both systems when the temperature is within the threshold
    DeactivateCoolingSystem();
    DeactivateHeatingSystem();
    coolingSystemActivated := FALSE;
    heatingSystemActivated := FALSE;
END_IF

// Raise an alert if temperature deviates significantly from the desired level
IF ABS(currentTemperature - desiredTemperature) > 20.0 THEN
    RaiseAlert();
    alertRaised := TRUE;
ELSE
    LowerAlert();
    alertRaised := FALSE;
END_IF
END_PROGRAM
