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

void output(char* input) {
    uint64_t converted = charuint(input);
    switch(converted) {
        case 478560413032:
            printf("welcome %s\n",ghost());
            break;
        case 25705:
            getinfo();
            break;
        case 1953069157:
            return;
        case 0:
            return;
        default:
            printf("command %s(%llu) unknown\n",input,converted);
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
