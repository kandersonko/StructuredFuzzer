PROGRAM AutomatedFireSuppressionSystem
VAR
    smokeLevel AT %IW0.0: INT;                       (* Smoke level in the room *)
    temperature AT %IW0.1: INT;                      (* Temperature in the room *)
    smokeDetected AT %QX0.0: BOOL;         (* Flag indicating if smoke is detected *)
    heatDetected AT %QX0.1 : BOOL;          (* Flag indicating if excessive heat is detected *)
    fireAlarmOn AT %QX0.2 : BOOL;           (* Flag indicating if the fire alarm is on *)
    sprinklerSystemActivated AT %QX0.3 : BOOL; (* Flag indicating if the sprinkler system is activated *)
    emergencyServicesNotified  AT %QX0.4 : BOOL; (* Flag indicating if emergency services have been notified *)
END_VAR

IF smokeLevel > 50 THEN
    smokeDetected := TRUE;
ELSE
    smokeDetected := FALSE;
END_IF;

IF temperature > 100 THEN
    heatDetected := TRUE;
ELSE
    heatDetected := FALSE;
END_IF;

(* Logical Bug: Incorrect logic combination for fire detection and response *)
(* The system should activate if EITHER smoke or heat is detected, not necessarily both *)
IF smokeDetected AND heatDetected THEN
    (* ActivateFireAlarm(); *)
    (* ActivateSprinklerSystem(); *)
    (* NotifyEmergencyServices(); *)
    fireAlarmOn := TRUE;
    sprinklerSystemActivated := TRUE;
    emergencyServicesNotified := TRUE;
ELSE
    (* DeactivateFireAlarm(); *)
    (* DeactivateSprinklerSystem(); *)
    (* DoNotNotifyEmergencyServices(); *)
    fireAlarmOn := FALSE;
    sprinklerSystemActivated := FALSE;
    emergencyServicesNotified := FALSE;
END_IF;
END_PROGRAM

CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : AutomatedFireSuppressionSystem;
  END_RESOURCE
END_CONFIGURATION
