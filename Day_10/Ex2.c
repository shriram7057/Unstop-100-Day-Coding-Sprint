#include <stdio.h>

int user_logic(int n, char* s) {
    int current = 0, maxDepth = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            current++;
            if (current > maxDepth) {
                maxDepth = current;
            }
        } else if (s[i] == ')') {
            current--;
        }
    }

    return maxDepth;
}

int main() {
    int n;
    char s[1001];
    scanf("%d %s", &n, s);
    int result = user_logic(n, s);
    printf("%d\n", result);
    return 0;
}