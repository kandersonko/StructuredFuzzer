PROGRAM AutomatedVentilationControl
VAR
    oxygenLevel AT %ID0.0: REAL;       (* Oxygen concentration in the room (%) *)
    carbonDioxideLevel AT %ID0.1: REAL; (* Carbon Dioxide concentration in the room (%) *)
    airFlowRate AT %QD0.1 : REAL;        (* Airflow rate into the room (cubic meters per minute) *)
    alarmActivated AT %QX0.0 : BOOL;     (* Alarm state for unsafe conditions *)
    ventilationOn AT %QX0.1 : BOOL;      (* Ventilation system state *)
END_VAR


(* Logical Bug: Incorrect thresholds and logic for ventilation control *)
(* The ventilation should turn on if oxygen level is below 21% or CO2 level is above 0.5% *)
IF (oxygenLevel >= 21.0 AND carbonDioxideLevel <= 0.5) THEN
    (* TurnOffVentilation(); *)
    ventilationOn := FALSE;
    (* DeactivateAlarm(); *)
ELSE
    (* TurnOnVentilation(); *)
    airFlowRate := 5.0; (* Set a fixed airflow rate *)
    ventilationOn := TRUE;
    IF (oxygenLevel < 19.0 OR carbonDioxideLevel > 1.0) THEN
        (* ActivateAlarm(); *)
        alarmActivated := TRUE;
    ELSE
        (* DeactivateAlarm(); *)
        alarmActivated := FALSE;
    END_IF;
END_IF;
END_PROGRAM

CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain :  AutomatedVentilationControl;
  END_RESOURCE
END_CONFIGURATION
