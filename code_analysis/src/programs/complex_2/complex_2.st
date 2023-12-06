PROGRAM ComplexManufacturingProcess
VAR
    conveyorBeltSpeed : INT;      // Speed of the conveyor belt (0-100)
    temperatureSensor : REAL;     // Temperature sensor reading
    pressureSensor : REAL;        // Pressure sensor reading
    safetyOverride : BOOL;        // Manual safety override switch
    systemStatus : STRING;        // Status of the system ("Safe", "Warning", "Critical")
END_VAR

// Dummy functions to simulate sensor readings and actions
PROCEDURE GetConveyorBeltSpeed() : INT; BEGIN END_PROCEDURE;
PROCEDURE GetTemperatureSensorValue() : REAL; BEGIN END_PROCEDURE;
PROCEDURE GetPressureSensorValue() : REAL; BEGIN END_PROCEDURE;
PROCEDURE GetSafetyOverrideStatus() : BOOL; BEGIN END_PROCEDURE;
PROCEDURE TriggerEmergencyShutdown(); BEGIN END_PROCEDURE;
PROCEDURE ReduceOperationSpeed(); BEGIN END_PROCEDURE;
PROCEDURE ContinueNormalOperation(); BEGIN END_PROCEDURE;

// Main logic
conveyorBeltSpeed := GetConveyorBeltSpeed();
temperatureSensor := GetTemperatureSensorValue();
pressureSensor := GetPressureSensorValue();
safetyOverride := GetSafetyOverrideStatus();

// Complex Logical Bug: Incorrect logical conjunctions and misplaced parentheses
IF (conveyorBeltSpeed > 80 AND temperatureSensor < 100.0) OR (pressureSensor > 50.0) AND NOT safetyOverride THEN
    systemStatus := 'Critical';
    TriggerEmergencyShutdown();
ELSIF (temperatureSensor > 80.0 OR pressureSensor > 40.0) AND NOT safetyOverride THEN
    systemStatus := 'Warning';
    ReduceOperationSpeed();
ELSE
    systemStatus := 'Safe';
    ContinueNormalOperation();
END_IF
END_PROGRAM

CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : ComplexManufacturingProcess;
  END_RESOURCE
END_CONFIGURATION
