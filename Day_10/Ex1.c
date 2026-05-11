#include <stdio.h>
#include <string.h>

const char* follows_ab_pattern(const char* s) {
    int seen_b = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'b') {
            seen_b = 1;
        } else if (s[i] == 'a') {
            if (seen_b) return "NO";
        }
    }

    return "YES";
}

int main() {
    char s[1000005];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;
    
    const char* result = follows_ab_pattern(s);
    printf("%s\n", result);
    
    return 0;
}