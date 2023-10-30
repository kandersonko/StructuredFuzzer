#ifndef INPUTS_H
#define INPUTS_H

typedef union {
  BOOL bValue;
  SINT sintValue;
  INT intValue;
  DINT dintValue;
  LINT lintValue;
  USINT usintValue;
  UINT uintValue;
  UDINT udintValue;
  ULINT ulintValue;
  REAL realValue;
  LREAL lrealValue;
  BYTE byteValue;
  WORD wordValue;
  DWORD dwordValue;
  LWORD lwordValue;
  // If necessary, extend with more PLC datatypes
} PLC_Value;


typedef struct {
  char* name;
  char* type;  // "BOOL", "SINT", "INT", "DINT", etc.
  PLC_Value value;
} PLC_Input;

#include <stdio.h>
#include <string.h>

#define MAX_INPUTS 1000
#define MAX_LINE_LEN 512

// int read_inputs_from_file(const char* filename, PLC_Input inputs[]) {
//   FILE* file = fopen(filename, "r");
//   if (!file) {
//     perror("Error opening file");
//     return -1;
//   }
//
//   char line[MAX_LINE_LEN];
//   int count = 0;
//
//   while (fgets(line, sizeof(line), file) && count < MAX_INPUTS) {
//     char* token;
//
//     // Extract name
//     token = strtok(line, ",");
//     if (token == NULL) continue;
//     inputs[count].name = strdup(token);  // Duplicate the string to store
//
//     // Extract type
//     token = strtok(NULL, ",");
//     if (token == NULL) continue;
//     inputs[count].type = strdup(token);
//
//     // Extract value based on type
//     token = strtok(NULL, ",");
//     if (token == NULL) continue;
//
//     if (strcmp(inputs[count].type, "BOOL") == 0) {
//       inputs[count].value.bValue = (strcmp(token, "TRUE") == 0);
//     } else if (strcmp(inputs[count].type, "SINT") == 0) {
//       inputs[count].value.sintValue = atoi(token);
//     } else if (strcmp(inputs[count].type, "INT") == 0) {
//       inputs[count].value.intValue = atoi(token);
//     } else if (strcmp(inputs[count].type, "DINT") == 0) {
//       inputs[count].value.dintValue = atoi(token);
//     } else if (strcmp(inputs[count].type, "LINT") == 0) {
//       inputs[count].value.lintValue = atol(token);
//     } else if (strcmp(inputs[count].type, "USINT") == 0) {
//       inputs[count].value.usintValue = (USINT) atoi(token);
//     } else if (strcmp(inputs[count].type, "UINT") == 0) {
//       inputs[count].value.uintValue = (UINT) atoi(token);
//     } else if (strcmp(inputs[count].type, "UDINT") == 0) {
//       inputs[count].value.udintValue = (UDINT) atol(token);
//     } else if (strcmp(inputs[count].type, "ULINT") == 0) {
//       inputs[count].value.ulintValue = (ULINT) strtoul(token, NULL, 10);
//     } else if (strcmp(inputs[count].type, "REAL") == 0) {
//       inputs[count].value.realValue = atof(token);
//     } else if (strcmp(inputs[count].type, "LREAL") == 0) {
//       inputs[count].value.lrealValue = atof(token);
//     } else if (strcmp(inputs[count].type, "BYTE") == 0) {
//       inputs[count].value.byteValue = (BYTE) strtoul(token, NULL, 16);
//     } else if (strcmp(inputs[count].type, "WORD") == 0) {
//       inputs[count].value.wordValue = (WORD) strtoul(token, NULL, 16);
//     } else if (strcmp(inputs[count].type, "DWORD") == 0) {
//       inputs[count].value.dwordValue = (DWORD) strtoul(token, NULL, 16);
//     } else if (strcmp(inputs[count].type, "LWORD") == 0) {
//       inputs[count].value.lwordValue = (LWORD) strtoull(token, NULL, 16);
//     }
//     count++;
//   }
//
//   fclose(file);
//   return count;  // Return the number of inputs read
// }


#endif // !INPUTS_H
