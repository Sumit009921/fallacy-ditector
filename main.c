#include <stdio.h>
#include <ctype.h>
#include "fallacy.h"

int main() {
    char argument[1000];
    int i;
    int score = 100;

    // Read input directly
    fgets(argument, 1000, stdin);

    for (i = 0; argument[i] != '\0'; i++) {
        argument[i] = tolower(argument[i]);
    }

    if (detectHastyGeneralization(argument)) {
        printf("Hasty Generalization\n");
        score -= 30;
    }

    if (detectCircularReasoning(argument)) {
        printf("Circular Reasoning\n");
        score -= 40;
    }

    if (detectFalseCause(argument)) {
        printf("False Cause\n");
        score -= 25;
    }

    if (score < 0) score = 0;

    printf("Score:%d\n", score);

    return 0;
}
