PROGRAM SafetyCriticalOperation
VAR
    sensorValue : INT;     // Sensor reading, expected range 0-100
    safeThreshold : INT := 50;   // Threshold for safe operation
    emergencyStop : BOOL;  // Emergency stop flag
END_VAR

PROCEDURE ShutdownSystem()
    // Shut down the system
END_PROCEDURE

PROCEDURE ContinueOperation()
    // Continue normal operation
END_PROCEDURE


// Logical Bug: Incorrect comparison operator
// The operation should stop if the sensor value is ABOVE the safe threshold
IF sensorValue < safeThreshold THEN
    emergencyStop := TRUE;
    // Initiate emergency shutdown
    ShutdownSystem();
ELSE
    // Continue normal operation
    ContinueOperation();
END_IF
END_PROGRAM

CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain :  SafetyCriticalOperation;
  END_RESOURCE
END_CONFIGURATION
