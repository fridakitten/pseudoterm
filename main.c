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

void output(char* input) {
    uint64_t converted = charuint(input);
    switch(converted) {
        case 478560413032: //hello
            printf("welcome %s\n",ghost());
            break;
        case 25705: //id
            getinfo();
            break;
        case 32419239451523173: //exec -s
            execmodeswitch();
        case 0: //NULL
            return;
        case 1953069157:
            return;
        default:
            break;
    }
    uint8_t code = exec(input);
    if(code==55) {
        printf("command %s(%llu) unknown\n",input,converted);
    } else if(code!=0) {
        printf("exit with code: %d\n",code);
    }
}

int main() {
    bool loop = true;
    char *input;
    while(loop) {
        input = readline("localhost:/> ");
        output(input);
        if(strcmp(input, "exit") == 0) {
            return 0;
        }
    }
}
