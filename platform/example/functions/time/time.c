/* time( time_t * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <time.h>

#ifndef REGTEST

#ifdef __ANDROID__
/* typedef sigset_t */
#include "bits/signal_types.h"
#define _STRUCT_TIMESPEC
#endif

#ifdef __CYGWIN__
#define _CLOCK_T_DECLARED
#define _SYS__TIMESPEC_H_
#endif

#include "sys/time.h"

/* See comments in _PDCLIB_config.h on the semantics of time_t. */

time_t time( time_t * timer )
{
    struct timeval tv;

    if ( gettimeofday( &tv, NULL ) == 0 )
    {
        if ( timer != NULL )
        {
            *timer = tv.tv_sec;
        }

        return tv.tv_sec;
    }

    return -1;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    TESTCASE( NO_TESTDRIVER );
    return TEST_RESULTS;
}

#endif
