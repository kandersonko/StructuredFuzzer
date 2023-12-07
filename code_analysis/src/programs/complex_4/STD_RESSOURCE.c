/*******************************************/
/*     FILE GENERATED BY iec2c             */
/* Editing this file is not recommended... */
/*******************************************/

#include "iec_std_lib.h"

// RESOURCE STD_RESSOURCE

extern unsigned long long common_ticktime__;

#include "accessor.h"
#include "POUS.h"

#include "STD_CONF.h"

#include "POUS.c"

BOOL TASKMAIN;
RAILWAYCROSSINGCONTROL STD_RESSOURCE__INST0;
#define INST0 STD_RESSOURCE__INST0

void STD_RESSOURCE_init__(void) {
  BOOL retain;
  retain = 0;
  
  TASKMAIN = __BOOL_LITERAL(FALSE);
  RAILWAYCROSSINGCONTROL_init__(&INST0,retain);
}

void STD_RESSOURCE_run__(unsigned long tick) {
  TASKMAIN = !(tick % 1);
  if (TASKMAIN) {
    RAILWAYCROSSINGCONTROL_body__(&INST0);
  }
}

