PROGRAM ComplexManufacturingProcess
VAR
    conveyorBeltSpeed AT %IW0.0 : INT;      (* Speed of the conveyor belt (0-100) *)
    temperatureSensor AT %ID0.0 : REAL;     (* Temperature sensor reading *)
    pressureSensor AT %ID0.1 : REAL;        (* Pressure sensor reading *)
    safetyOverride AT %QX0.0 : BOOL;        (* Manual safety override switch *)
    systemStatus AT %QW0.0 : INT;        (* Status of the system (0 -> "Safe", 1 -> "Warning", -1 -> "Critical") *)
END_VAR


(* Complex Logical Bug: Incorrect logical conjunctions and misplaced parentheses *)
IF (conveyorBeltSpeed > 80 AND temperatureSensor < 100.0) OR (pressureSensor > 50.0) AND NOT safetyOverride THEN
    systemStatus := -1; (* Critical *)
    (* TriggerEmergencyShutdown(); *)
ELSIF (temperatureSensor > 80.0 OR pressureSensor > 40.0) AND NOT safetyOverride THEN
    systemStatus := 1; (* Warning *)
    (* ReduceOperationSpeed(); *)
ELSE
    systemStatus := 0; (* Safe *)
    (* ContinueNormalOperation(); *)
END_IF;
END_PROGRAM

CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : ComplexManufacturingProcess;
  END_RESOURCE
END_CONFIGURATION
