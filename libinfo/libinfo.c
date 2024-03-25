#include <stdio.h>
#include <unistd.h>

void getinfo() {
    int uid = getuid();
    int gid = getgid();
    printf("uid=%d gid=%d\n",uid,gid);
}
