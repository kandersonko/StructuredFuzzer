PROGRAM AutomatedConveyorControl
VAR
    itemType AT %IW0.0 : INT;                   (* Type of item on the conveyor (1 for fragile, 2 for standard, 3 for heavy) *)
    conveyorSpeed AT %QD0.0 : REAL;             (* Conveyor belt speed (in meters per second) *)
    emergencyStopActivated AT %QX0.0 : BOOL;    (* Flag indicating if emergency stop is activated *)
END_VAR

(* Logical Bug: Incorrect conveyor speed settings for different item types *)
CASE itemType OF
    1: (* Fragile items *)
        conveyorSpeed := 0.5; (* Slow speed for fragile items *)
    2: (* Standard items *)
        conveyorSpeed := 1.5; (* Medium speed for standard items *)
    3: (* Heavy items *)
        (* Bug: Too fast for heavy items, might cause damage *)
        conveyorSpeed := 2.0; (* High speed for heavy items *)
    ELSE
        (* In case of an unrecognized item type, activate emergency stop *)
        (* ActivateEmergencyStop(); *)
        emergencyStopActivated := TRUE;
        conveyorSpeed := 0.0;
END_CASE;

(* SetConveyorSpeed(conveyorSpeed); *)

END_PROGRAM


CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : AutomatedConveyorControl;
  END_RESOURCE
END_CONFIGURATION
