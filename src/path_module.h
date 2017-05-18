//
// Created by chillten on 12.05.17.
//
#include <stdint.h>
#include <stdio.h>
#include "strings.h"
#include <stdlib.h>
#ifndef PROG_LAV5_PATH_MODULE_H
#define PROG_LAV5_PATH_MODULE_H
enum OS
{
    os_unknown = 0,
    os_unix = 1,
    os_win = 2
} e_os;
int path_input(char *delim, char *paths, uint32_t p_size);
int path_check(const char *path, const char *disallow_chars);
void path_process(const char *path, char *new_path, char *delim);
void path_output(const char *path);
#endif //PROG_LAV5_PATH_MODULE_H
