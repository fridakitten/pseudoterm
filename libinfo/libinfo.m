#include "libinfo.h"
#include <stdio.h>
#include <Foundation/Foundation.h>

void getinfo() {
    int uid = getuid();
    int gid = getgid();
    int pid = getpid();
    printf("UID: %d\nGID: %d\nPID: %d\n",uid,gid,pid);
}
