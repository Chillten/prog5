//
// Created by chillten on 12.05.17.
//
#include <stddef.h>
#include <stdint.h>

#ifndef PROG_LAV5_STRINGS_H
#define PROG_LAV5_STRINGS_H

int slen(const char *s);

char *sspn(const char *cs, const char *ct);

char *stok(char **s, const char *ct);

int scmp(const char *s1, const char *s2);

char *scpy(char *dest, const char *src);

void sconcat(char *dest, const char *src);
#endif //PROG_LAV5_STRINGS_H
