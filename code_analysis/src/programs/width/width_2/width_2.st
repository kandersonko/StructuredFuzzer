PROGRAM My_Program
  VAR
    sensor1 AT %IW0.0 : INT;
    actuator AT %QW0.0 : INT;
  END_VAR

  CASE sensor1 OF
  10: actuator := 10;
  20: actuator := 20;
  ELSE
    actuator := 0;
  END_CASE;
    
END_PROGRAM


CONFIGURATION STD_CONF

  RESOURCE STD_RESSOURCE ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst0 WITH TaskMain : My_Program;
  END_RESOURCE
END_CONFIGURATION
