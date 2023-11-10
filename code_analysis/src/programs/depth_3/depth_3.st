PROGRAM My_Program
  VAR
    button1 AT %IX0.0 : BOOL;
    button2 AT %IX0.1 : BOOL;
    button3 AT %IX0.2 : BOOL;
    led AT %QX0.0 : BOOL;
  END_VAR
  VAR
    LED_ON : BOOL;
  END_VAR

  LED_ON := OR(button1, button2);
  IF button1 = TRUE THEN
    IF button2 = TRUE THEN
      IF button3 = TRUE THEN
        led := LED_ON;
      ELSE
        led := FALSE;
      END_IF;
    ELSE
      led := FALSE;
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
