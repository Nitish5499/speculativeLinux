/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _LINUX_UNISTD_H_
#define _LINUX_UNISTD_H_

/*
 * Include machine specific syscall numbers
 */
#include <asm/unistd.h>

struct prcs_nitish {
        int prio;                       // priority
        long state;                     // -1 unrunnable, 0 runnable, >0 stopped 
        unsigned int cpu;               // Current CPU
        unsigned long nvcsw;            // context switch count
        unsigned long long start_time;  // start time in ns
};

#endif /* _LINUX_UNISTD_H_ */
