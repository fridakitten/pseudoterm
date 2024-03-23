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
    uint64_t hello = charuint(input);
    printf("%llu\n",hello);
    /*if(strcmp(input, "info") == 0) {
        getinfo();
    } else if(strcmp(input, "hello") == 0) {
        printf("welcome %s\n",ghost());
    } else if(strcmp(input, "exit") == 0) {
        return;
    }*/
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
