#include <iostream>
#include <vector>
#include <string>
#include <climits>

void user_logic(const std::string& s, char ch, std::vector<int>& result) {
    int n = s.length();
    int prev = -n;  // safe initial value

    // Left to right pass
    for (int i = 0; i < n; i++) {
        if (s[i] == ch) prev = i;
        result[i] = i - prev;
    }

    // Right to left pass
    prev = 2 * n;  // safe initial value
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ch) prev = i;
        result[i] = std::min(result[i], prev - i);
    }
}

int main() {
    std::string s;
    char ch;
    std::cin >> s;
    std::cin >> ch;
    std::vector<int> result(s.length());
    user_logic(s, ch, result);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    return 0;
}