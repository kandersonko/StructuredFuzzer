#ifndef INPUTS_H
#define INPUTS_H

typedef union {
    BOOL _BOOL;
    SINT _SINT;
    INT _INT;
    DINT _DINT;
    LINT _LINT;
    USINT _USINT;
    UINT _UINT;
    UDINT _UDINT;
    ULINT _ULINT;
    REAL _REAL;
    LREAL _LREAL;
} PLC_Value;

typedef struct {
  char* name;
  char* type;  // "BOOL", "SINT", "INT", "DINT", etc.
  PLC_Value value;
} PLC_Input;



#endif // !INPUTS_H
