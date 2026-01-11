#include <string.h>
#include "fallacy.h"

int detectHastyGeneralization(char text[]) {
    if ((strstr(text, "all") != NULL ||
         strstr(text, "always") != NULL ||
         strstr(text, "everyone") != NULL) &&
        (strstr(text, "one") != NULL ||
         strstr(text, "two") != NULL ||
         strstr(text, "some") != NULL ||
         strstr(text, "few") != NULL)) {
        return 1;
    }
    return 0;
}

int detectCircularReasoning(char text[]) {
    int count = 0;
    char *ptr = text;

    while ((ptr = strstr(ptr, "because")) != NULL) {
        count++;
        ptr += 7;
    }

    if (count >= 2) {
        return 1;
    }
    return 0;
}

int detectFalseCause(char text[]) {
    int hasTime = 0;
    int hasCause = 0;

    if (strstr(text, "after") != NULL ||
        strstr(text, "then") != NULL ||
        strstr(text, "when") != NULL) {
        hasTime = 1;
    }

    if (strstr(text, "because") != NULL ||
        strstr(text, "caused") != NULL ||
        strstr(text, "due to") != NULL) {
        hasCause = 1;
    }

    if (hasTime && hasCause) {
        return 1;
    }
    return 0;
}
