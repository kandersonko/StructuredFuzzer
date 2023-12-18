PROGRAM My_Program
  VAR
    button1 AT %IX0.0 : BOOL;
    button2 AT %IX0.1 : BOOL;
    led AT %QX0.0 : BOOL;
  END_VAR

  IF button1 = TRUE THEN
    IF button2 = TRUE THEN
      led := TRUE;
    END_IF;
  ELSE
    led := FALSE;
  END_IF;
END_PROGRAM


CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : My_Program;
  END_RESOURCE
END_CONFIGURATION