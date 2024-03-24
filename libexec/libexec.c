#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool execmode = false;

void execmodeswitch() {
    if(execmode==false) {
        execmode = true;
    } else {
        execmode = false;
    }
}

uint8_t exec(char* command) {
    if(execmode==true) {
        uint8_t execcode = system(command);
        return execcode;
    } else {
        return 55;
    }
    return 0;
}
