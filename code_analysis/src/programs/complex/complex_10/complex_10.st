PROGRAM AutomatedReactorControl
VAR
    reactorMode AT %IW0.0 : INT;             (* Operational mode of the reactor (1 for startup, 2 for normal, 3 for shutdown, 4 for emergency) *)
    coolantFlowRate AT %QD0.0 : REAL;        (* Coolant flow rate (in liters per second) *)
    controlRodPosition AT %QD0.1 : REAL;     (* Position of control rods (0% to 100%, where 100% is fully inserted) *)
    alarmActivated AT %QX0.0 : BOOL;         (* State of the alarm system *)
END_VAR


(* Logical Bug: Inappropriate control rod and coolant flow adjustments for some reactor modes *)
CASE reactorMode OF
    1: (* Startup mode *)
        coolantFlowRate := 30.0;   (* Moderate coolant flow *)
        controlRodPosition := 20.0; (* Partially withdrawn control rods *)
    2: (* Normal operation mode *)
        coolantFlowRate := 50.0;   (* High coolant flow *)
        controlRodPosition := 50.0; (* Halfway inserted control rods *)
    3: (* Shutdown mode *)
        coolantFlowRate := 20.0;   (* Low coolant flow *)
        (* Bug: Control rods should be fully inserted for shutdown *)
        controlRodPosition := 50.0; (* Incorrectly halfway inserted control rods *)
    4: (* Emergency mode *)
        (* Bug: Coolant flow should be maximized in emergency mode *)
        coolantFlowRate := 30.0;   (* Insufficient coolant flow for emergency *)
        controlRodPosition := 100.0; (* Fully inserted control rods *)
        (* ActivateAlarm(); *)
        alarmActivated := TRUE;
    ELSE
        (* Default safe state in case of an unrecognized mode *)
        (* ActivateAlarm(); *)
        alarmActivated := TRUE;
        coolantFlowRate := 0.0;
        controlRodPosition := 100.0; (* Fully insert control rods *)
END_CASE;


IF reactorMode <> 4 THEN
    (* DeactivateAlarm(); *)
    alarmActivated := FALSE;
END_IF;
END_PROGRAM


CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : AutomatedReactorControl;
  END_RESOURCE
END_CONFIGURATION
