/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Copyright (C) 2003-2011  Mario de Sousa (msousa@fe.up.pt)
 *  Copyright (C) 2007-2011  Laurent Bessard and Edouard Tisserant
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * This code is made available on the understanding that it will not be
 * used in safety-critical situations without a full and competent review.
 *
 *
 * Minimal standaloen C runtime, for test purpose.
 * TODO : UPDATE
 *
 */

#include <linux/limits.h>
#ifdef __WIN32__
#include <stdio.h>
#include <sys/timeb.h>
#include <time.h>
#include <windows.h>
#else
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#endif

#include "iec_types.h"
#include "iec_std_lib.h"
#include "iec_std_functions.h"

#include "inputs.h"


void config_init__(void);
/*
 * Functions and variables provied by generated C softPLC
 **/ 
extern int common_ticktime__;

IEC_BOOL __DEBUG;

/*
 * Functions and variables provied by plc.c
 **/ 
// void run(long int tv_sec, long int tv_nsec);
// void run(PLC_Input inputs[], int size);
void run(int argc,char **argv);

int main(int argc, char **argv) {
    config_init__();

    run(argc, argv);  // Adjust this call as necessary to use input_data

    return 0;
}
