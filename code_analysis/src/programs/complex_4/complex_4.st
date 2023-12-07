PROGRAM RailwayCrossingControl
VAR
    sensorReading AT %IW0.0: INT;           (* Sensor reading for train detection (0 for no train, 1 for train detected) *)
    trainDetected AT %QX0.0 : BOOL;          (* Flag indicating if a train is detected *)
    gateClosed AT %QX0.1 : BOOL;             (* Flag indicating if the crossing gate is closed *)
    redLightOn AT %QX0.2: BOOL;             (* Flag indicating if the red light is on *)
    greenLightOn AT %QX0.3: BOOL;           (* Flag indicating if the green light is on *)
    warningAlarmOn AT %QX0.4: BOOL;         (* Flag indicating if the warning alarm is on *)
END_VAR


(* Determine if a train is detected based on the sensor reading *)
IF sensorReading = 1 THEN
    trainDetected := TRUE;  (* Train is detected *)
ELSE
    trainDetected := FALSE; (* No train detected *)
END_IF;

(* Logical Bug: Inconsistent condition handling for gate and light control *)
IF trainDetected THEN
    (* Close gate and turn on warning systems *)
    (* CloseGate(); *)
    (* TurnOnRedLight(); *)
    (* TurnOffGreenLight(); *)
    (* TurnOnWarningAlarm(); *)
    gateClosed := TRUE;
    redLightOn := TRUE;
    greenLightOn := FALSE;
    warningAlarmOn := TRUE;
ELSE
    (* Open gate and turn off warning systems *)
    (* OpenGate(); *)
    (* TurnOffRedLight(); *)
    (* Bug: Green light should not be on when the gate is open *)
    (* TurnOnGreenLight(); *)
    (* TurnOffWarningAlarm(); *)
    gateClosed := FALSE;
    redLightOn := FALSE;
    greenLightOn := TRUE;
    warningAlarmOn := FALSE;
END_IF;
END_PROGRAM

CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : RailwayCrossingControl;
  END_RESOURCE
END_CONFIGURATION
