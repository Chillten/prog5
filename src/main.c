#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "path_module.h"

const uint32_t D_SIZE = 256;

int main()
{
    char *delim = (char*) malloc(sizeof(char) * D_SIZE);
    char *paths = (char*) malloc(sizeof(char) * D_SIZE * 16);
    char *new_paths = (char*) malloc(sizeof(char) * D_SIZE * 16);
    *new_paths = '\0';

    char *t_path = paths;
    char *token;

    path_input(delim, paths, D_SIZE);
    while( (token = stok(&paths,delim)) != NULL ) {
        if (!path_check(token, delim)) {
            path_process(token, new_paths, delim);
        } else {
            printf("path:%s contain invalid symbols\n", token);
        }
    }

    path_output(new_paths);

    free(delim);
    free(t_path);
    free(new_paths);

    return 0;
}