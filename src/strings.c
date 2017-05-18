//
// Created by chillten on 12.05.17.
//

#include "strings.h"
int slen(const char *s){
    const char *sc;

    for (sc = s; *sc != '\0'; ++sc);
    return sc - s;
}

char *sspn(const char *cs, const char *ct)
{
    const char *sc1, *sc2;

    for (sc1 = cs; *sc1 != '\0'; ++sc1) {
        for (sc2 = ct; *sc2 != '\0'; ++sc2) {
            if (*sc1 == *sc2)
                return (char *)sc1;
        }
    }
    return NULL;
}

char *stok(char **s, const char *ct)
{
    char *sbegin = *s;
    char *end;

    if (sbegin == NULL)
        return NULL;

    end = sspn(sbegin, ct);
    if (end)
        *end++ = '\0';
    *s = end;
    return sbegin;
}

int scmp(const char *s1, const char *s2)
{
    unsigned char c1, c2;

    while (1) {
        c1 = *s1++;
        c2 = *s2++;
        if (c1 != c2)
            return c1 < c2 ? -1 : 1;
        if (!c1)
            break;
    }
    return 0;
}

char *scpy(char *dest, const char *src){
    if(src != NULL && dest != NULL) {
        char *tmp = dest;

        while ((*dest++ = *src++) != '\0');
        return tmp;
    }
    return NULL;
}

void sconcat(char *dest, const char *src){
    while(*dest != '\0')
        dest++;
    scpy(dest, src);
}