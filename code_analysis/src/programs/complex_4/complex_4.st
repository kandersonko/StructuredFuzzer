PROGRAM RailwayCrossingControl
VAR
    trainDetected : BOOL;          // Flag indicating if a train is detected
    gateClosed : BOOL;             // Flag indicating if the crossing gate is closed
    redLightOn : BOOL;             // Flag indicating if the red light is on
    greenLightOn : BOOL;           // Flag indicating if the green light is on
    warningAlarmOn : BOOL;         // Flag indicating if the warning alarm is on
    sensorReading : INT;           // Sensor reading for train detection (0 for no train, 1 for train detected)
END_VAR

// Dummy functions for hardware control
PROCEDURE CloseGate(); BEGIN END_PROCEDURE;
PROCEDURE OpenGate(); BEGIN END_PROCEDURE;
PROCEDURE TurnOnRedLight(); BEGIN END_PROCEDURE;
PROCEDURE TurnOffRedLight(); BEGIN END_PROCEDURE;
PROCEDURE TurnOnGreenLight(); BEGIN END_PROCEDURE;
PROCEDURE TurnOffGreenLight(); BEGIN END_PROCEDURE;
PROCEDURE TurnOnWarningAlarm(); BEGIN END_PROCEDURE;
PROCEDURE TurnOffWarningAlarm(); BEGIN END_PROCEDURE;

PROCEDURE DetectTrain() : BOOL
VAR
    sensorReading : INT;  // Hypothetical sensor reading (0 for no train, 1 for train detected)
END_VAR

    // Simulate reading from a sensor
    sensorReading := GetSensorValue();

    // Determine if a train is detected based on the sensor reading
    IF sensorReading = 1 THEN
        RETURN TRUE;  // Train is detected
    ELSE
        RETURN FALSE; // No train detected
    END_IF
END_PROCEDURE

// Main logic
trainDetected := DetectTrain();

// Logical Bug: Inconsistent condition handling for gate and light control
IF trainDetected THEN
    // Close gate and turn on warning systems
    CloseGate();
    TurnOnRedLight();
    TurnOffGreenLight();
    TurnOnWarningAlarm();
    gateClosed := TRUE;
    redLightOn := TRUE;
    greenLightOn := FALSE;
    warningAlarmOn := TRUE;
ELSE
    // Open gate and turn off warning systems
    OpenGate();
    TurnOffRedLight();
    // Bug: Green light should not be on when the gate is open
    TurnOnGreenLight();
    TurnOffWarningAlarm();
    gateClosed := FALSE;
    redLightOn := FALSE;
    greenLightOn := TRUE;
    warningAlarmOn := FALSE;
END_IF
END_PROGRAM
