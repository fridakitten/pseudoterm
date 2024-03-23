#include "libhost.h"
#include <stdio.h>
#include <unistd.h>

char* ghost() {
    static char hostname[256]; // Making it static to avoid returning a pointer to a local variable

    // Get the hostname
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        return hostname;
    } else {
        perror("gethostname");
        return NULL;
    }
}
