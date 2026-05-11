#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <algorithm>
int minTimeToType(const std::string& word) {
    std::string s = word;
    sort(s.begin(), s.end());

    int time = 0;
    char current = 'a';

    for (char c : s) {
        int diff = abs(c - current);
        int move = std::min(diff, 26 - diff);
        time += move + 1;
        current = c;
    }

    return time;
}
int main() {
    std::string word;
    std::cin >> word;
    int result = minTimeToType(word);
    std::cout << result << std::endl;
    return 0;
}