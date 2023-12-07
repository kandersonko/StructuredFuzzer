PROGRAM AutomatedTrafficControl
VAR
    currentTime AT %IW0.0 : INT;        (* Current time in hours (24-hour format) *)
    trafficCondition AT %IW0.1 : INT;   (* Traffic condition (1 for low, 2 for moderate, 3 for high) *)
    trafficLightState AT %QW0.0 : INT;     (* State of the traffic lights (0 for Red", 1 for Green, 2 for Yellow) *)
END_VAR

(* Logical Bug: Incorrect handling of traffic light states in case statement *)
CASE currentTime OF
    0..5: (* Late night *)
        trafficLightState := 2; (* Yellow *)
    6..9: (* Morning rush hour *)
        IF trafficCondition = 3 THEN
            trafficLightState := 1; (* Green *)
        ELSE
            trafficLightState := 0; (* Red *)
        END_IF;
    10..15: (* Day time *)
        trafficLightState := 1; (* Green *)
    16..19: (* Evening rush hour *)
        (* Bug: Red light during high traffic in the evening rush hour *)
        IF trafficCondition = 3 THEN
            trafficLightState := 0; (* Red *)
        ELSE
            trafficLightState := 1; (* Green *)
        END_IF;
    20..23: (* Night *)
        trafficLightState := 2; (* Yellow *)
END_CASE;

(* SetTrafficLightState(trafficLightState); *)
END_PROGRAM

CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : AutomatedTrafficControl;
  END_RESOURCE
END_CONFIGURATION
