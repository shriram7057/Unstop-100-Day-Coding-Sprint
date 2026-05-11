#include <iostream>
#include <string>

#define MOD 1000000007

int homogenous_substring(const std::string &s) {
    long long ans = 0;
    long long count = 1;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            ans = (ans + (count * (count + 1)) / 2) % MOD;
            count = 1;
        }
    }

    // Add last group
    ans = (ans + (count * (count + 1)) / 2) % MOD;

    return (int)ans;
}
int main() {
    std::string s;
    std::cin >> s;
    
    // Call user logic function and print the output
    int result = homogenous_substring(s);
    std::cout << result << std::endl;
    
    return 0;
}