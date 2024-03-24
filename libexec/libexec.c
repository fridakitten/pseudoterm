#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool execmode = false;

void execmodeswitch() {
    execmode = !execmode;
}

uint8_t exec(char* command) {
    if(execmode) {
        uint8_t execcode = system(command);
        return execcode;
    } else {
        return 55;
    }
    return 0;
}
