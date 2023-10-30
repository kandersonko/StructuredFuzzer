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
void run(PLC_Input inputs[], int size);

#define maxval(a,b) ((a>b)?a:b)

#define MAX_INPUT 100

PLC_Input global_inputs[MAX_INPUT];
int global_size = MAX_INPUT;

void timer_notify(sigval_t val)
{
    struct timespec CURRENT_TIME;
    clock_gettime(CLOCK_REALTIME, &CURRENT_TIME);
    // run(CURRENT_TIME.tv_sec, CURRENT_TIME.tv_nsec);
    run(global_inputs, global_size);
}

void catch_signal(int sig)
{
  signal(SIGTERM, catch_signal);
  signal(SIGINT, catch_signal);
  printf("Got Signal %d\n",sig);
}

void terminate_process(int signo) {
    exit(0);
}

int main(int argc,char **argv)
{
    timer_t timer;
    struct sigevent sigev;
    long tv_nsec = common_ticktime__ % 1000000000;
    time_t tv_sec =  common_ticktime__ / 1000000000;
 
    struct itimerspec timerValues;
    
    memset (&sigev, 0, sizeof (struct sigevent));
    memset (&timerValues, 0, sizeof (struct itimerspec));

    // Setting the termination handler
    sigev.sigev_value.sival_int = 0;
    sigev.sigev_notify = SIGEV_SIGNAL;
    sigev.sigev_signo = SIGUSR1;  // Using user-defined signal 1. Ensure no other part of your program uses it.
    signal(SIGUSR1, terminate_process);

    timerValues.it_value.tv_sec = tv_sec;
    timerValues.it_value.tv_nsec = tv_nsec;
    // Not setting it_interval because we want the timer to run only once.

    printf("common_ticktime__: %ld ns\n", common_ticktime__);

    printf("\n - timerValues - \n");
    printf("interval tv_sec = %ld, tv_nsec = %ld\n", timerValues.it_interval.tv_sec, timerValues.it_interval.tv_nsec); 
    printf("config_init__();\n");
    config_init__();

    int err = timer_create (CLOCK_REALTIME, &sigev, &timer);

    if (err < 0) {
        printf("Error while creating timer\n");
    }
    timer_settime (timer, 0, &timerValues, NULL);

    sigval_t emptySigVal;
    emptySigVal.sival_int = 0;
    timer_notify(emptySigVal);

    // Wait indefinitely. The program will be terminated by our signal handler once the timer reaches the end of its cycle.
    pause();

    // This line will never be reached, but it's good practice to cleanup.
    timer_delete(timer);
    
    return 0;
}

