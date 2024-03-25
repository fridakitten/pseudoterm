#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libhost/libhost.h"
#include "libinfo/libinfo.h"
#include "libconv/libconv.h"
#include "libexec/libexec.h"

bool execenabled = false;
uint8_t execmode = 0;

void output(char* input) {
    uint64_t converted = charuint(input);
    switch(converted) {
        case 478560413032: //hello
            printf("welcome %s\n",ghost());
            return;
        case 25705: //id
            getinfo();
            return;
        case 32419239451523173: //exec -s
            execenabled = true;
            execmode = 0;
            return;
        case 8317635178929682533: //exec -ns
            execenabled = true;
            execmode = 1;
            return;
        case 0: //NULL
            return;
        case 1953069157:
            return;
        default:
            break;
    }
    if(execenabled) {
        uint8_t code;
        if(execmode==0) {
            code = execns(input);
        } else if(execmode==1) {
            code = execs(input);
        }
        if(code!=0) {
            printf("exit with code: %d\n",code);
        }
    } else {
        printf("command %s(%llu) unknown\n",input,converted);
    }
}

int main() {
    bool loop = true;
    char *input;
    char *hostcal;
    sprintf(hostcal, "%s:/> ",ghost());
    while(loop) {
        input = readline(hostcal);
        output(input);
        if(strcmp(input, "exit") == 0) {
            return 0;
        }
    }
}
