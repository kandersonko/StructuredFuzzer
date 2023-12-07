PROGRAM AutomatedTemperatureControl
VAR
    currentTemperature AT %ID0.0 : REAL;        (* Current temperature in the reactor (in Celsius) *)
    desiredTemperature AT %ID0.1 : REAL;         (* Desired operational temperature (in Celsius) *)
    coolingSystemActivated AT %QX0.0 : BOOL;    (* State of the cooling system *)
    heatingSystemActivated AT %QX0.1 : BOOL;    (* State of the heating system *)
    alertRaised AT %QX0.2 : BOOL;               (* Flag for raising an alert *)
END_VAR

VAR
    temperatureDifference : REAL;               (* Difference between current and desired temperature *)
END_VAR

(* Logical Bug: Incorrect arithmetic operations in temperature control logic *)
(* The system should activate cooling if the temperature exceeds the desired level by more than 10 degrees *)
(* and heating if it is below the desired level by more than 10 degrees *)
temperatureDifference := currentTemperature - desiredTemperature;
IF temperatureDifference > 10.0 THEN
    (* ActivateCoolingSystem(); *)
    coolingSystemActivated := TRUE;
    heatingSystemActivated := FALSE;
ELSE
    (* Bug: Deactivating both systems when the temperature is within the threshold *)
    (* DeactivateCoolingSystem(); *)
    (* DeactivateHeatingSystem(); *)
    coolingSystemActivated := FALSE;
    heatingSystemActivated := FALSE;
END_IF;

(* Raise an alert if temperature deviates significantly from the desired level *)
IF ABS(currentTemperature - desiredTemperature) > 20.0 THEN
    (* RaiseAlert(); *)
    alertRaised := TRUE;
ELSE
    (* LowerAlert(); *)
    alertRaised := FALSE;
END_IF;
END_PROGRAM

CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : AutomatedTemperatureControl;
  END_RESOURCE
END_CONFIGURATION
