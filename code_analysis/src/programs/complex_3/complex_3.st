PROGRAM AutomatedChemicalMixing
VAR
    chemicalALevel AT %ID0.0 : REAL;   (* Level of Chemical A *)
    chemicalBLevel AT %ID0.1: REAL;   (* Level of Chemical B *)
    valve1Open AT %QX0.0 : BOOL;       (* State of Valve 1 (TRUE if open) *)
    valve2Open AT %QX0.1 : BOOL;       (* State of Valve 2 (TRUE if open) *)
    mixerOn AT %QX0.2 : BOOL;          (* State of Mixer (TRUE if on) *)
    isMixingSafe AT %QX0.3: BOOL;     (* Flag to indicate if mixing conditions are safe *)
END_VAR


(* Logical Bug: Incorrect conditions for safe mixing *)
(* Safe mixing requires both chemicals to be within specific levels, but the bug allows mixing when it's unsafe *)
IF (chemicalALevel > 50.0 AND chemicalBLevel > 50.0) THEN
    isMixingSafe := TRUE;
ELSE
    isMixingSafe := FALSE;
END_IF;

IF isMixingSafe THEN
    (* OpenValve1(); *)
    (* OpenValve2(); *)
    (* StartMixer(); *)
    valve1Open := TRUE;
    valve2Open := TRUE;
    mixerOn := TRUE;
ELSE
    (* CloseValve1(); *)
    (* CloseValve2(); *)
    (* StopMixer(); *)
    valve1Open := FALSE;
    valve2Open := FALSE;
    mixerOn := FALSE;
END_IF;
END_PROGRAM

CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : AutomatedChemicalMixing;
  END_RESOURCE
END_CONFIGURATION
