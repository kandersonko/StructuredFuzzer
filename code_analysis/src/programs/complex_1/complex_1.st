
PROGRAM SafetyCriticalOperation
VAR
    sensorValue AT %IW0.0 : INT := 10;     (* Sensor reading, expected range 0-100 *)
    safeThreshold AT %QW0.0 : INT := 5;   (* Threshold for safe operation *)
    emergencyStop AT %QX0.1 : BOOL;  (* Emergency stop flag *)
END_VAR


(* Logical Bug: Incorrect comparison operator *)
(* The operation should stop if the sensor value is ABOVE the safe threshold *)
IF sensorValue < safeThreshold THEN
    emergencyStop := TRUE;
    (* Initiate emergency shutdown *)
ELSE
    emergencyStop := FALSE;
    (* Continue normal operation *)
END_IF;
END_PROGRAM

CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : SafetyCriticalOperation;
  END_RESOURCE
END_CONFIGURATION
