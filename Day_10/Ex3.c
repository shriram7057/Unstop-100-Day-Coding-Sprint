#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

int check_if_can_break(const char* s1, const char* s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    
    if (n1 != n2) return 0;

    char *a = (char*)malloc((n1 + 1) * sizeof(char));
    char *b = (char*)malloc((n2 + 1) * sizeof(char));

    strcpy(a, s1);
    strcpy(b, s2);

    qsort(a, n1, sizeof(char), cmp);
    qsort(b, n2, sizeof(char), cmp);

    int can1 = 1, can2 = 1;

    for (int i = 0; i < n1; i++) {
        if (a[i] < b[i]) can1 = 0;
        if (b[i] < a[i]) can2 = 0;
    }

    free(a);
    free(b);

    return can1 || can2;
}

int main() {
    char s1[100001];
    char s2[100001];
    
    scanf("%100000s", s1);
    scanf("%100000s", s2);
    
    int result = check_if_can_break(s1, s2);
    if (result) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    return 0;
}