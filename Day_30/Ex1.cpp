#include <iostream>
#include <string>

int LongestConsecutiveCharacter(const std::string& s) {
    int maxLen = 0, curr = 0;

    for (int i = 0; i < s.size(); i++) {
        if (i == 0 || s[i] == s[i - 1]) {
            curr++;
        } else {
            curr = 1;
        }
        maxLen = std::max(maxLen, curr);
    }

    return maxLen;
}
int main() {
    std::string s;
    std::getline(std::cin, s);
    
    // Call user logic function and print the output
    int result = LongestConsecutiveCharacter(s);
    std::cout << result << std::endl;
    
    return 0;
}