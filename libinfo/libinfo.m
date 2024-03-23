#include "libinfo.h"
#include <stdio.h>
#include <Foundation/Foundation.h>

void getinfo() {
    int uid = getuid();
    int gid = getgid();
    printf("uid=%d gid=%d\n",uid,gid);
}
