//
// Created by chillten on 12.05.17.
//

#include "path_module.h"

int path_input(char *delim, char *paths, uint32_t p_size){
    if(delim && paths) {
        printf("delim: ");
        fgets(delim, p_size, stdin);
        delim[1] = '\0';
        printf("paths: ");
        fgets(paths, p_size * 16, stdin);
        *(paths + slen(paths) - 1) = '\0';
        return 0;
    }
    return 1;
}

int get_os_type(const char *path){
    for(const char *c = path; *c != '\0'; c++){
        if(*c == '\\') {
            return os_win;
        }
        if(*c == '/') {
            return os_unix;
        }
    }
    return os_unknown;
}

int path_check(const char *path, const char *disallow_chars){
    int status = 0;
    int os = get_os_type(path);
    char slah[2] = "";
    if(os == os_unix) {
        scpy(slah, "\\");
    } else {
        if(os == os_win)
            scpy(slah, "/");
    }

    if(sspn(path, disallow_chars) || sspn(path, slah)){
        status = 1;
    }
    return status;
}

void path_process(const char *path, char *new_path, char *delim){
    char *t = malloc(slen(path));
    scpy(t, path);
    char slah[] = "/";

    char m[255][255];
    int size = 0;

    if(get_os_type(path) == os_win)
        scpy(slah, "\\");

    char *token;

    while( (token = stok(&t,slah)) != NULL ) {
        //printf("debug: sub path %s\n", token);
        scpy(m[size++], token);
    }
    int nn = 0;
    for(int i = size - 1; i >= 1; i--){
        if(scmp(m[i], ".") == 0)
            scpy(m[i], "");
        else if(scmp(m[i], "..") == 0){
            scpy(m[i], "");
            nn++;
        } else if(nn > 0 && scmp(m[i], "") != 0) {
            scpy(m[i], "");
            nn--;
        }
    }

    for(int i = 0; i < size; i++){
        if(i == 0 || scmp(m[i], "") != 0) {
            sconcat(new_path, m[i]);
            if (i != size - 1)
                sconcat(new_path, slah);
        }
    }
    sconcat(new_path, delim);
    free(t);
}

void path_output(const char *path){
    printf("%s\n", path);
}