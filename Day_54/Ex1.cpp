#include <iostream>
#include <string>

void user_logic(const std::string& str, const std::string& pattern, std::string& result_substring, int& index) {
    index = str.find(pattern);
    
    if (index == std::string::npos) {
        index = -1;
        result_substring = str;
    } else {
        result_substring = str.substr(0, index);
    }
}

int main() {
    std::string str;
    std::string pattern;
    std::string result_substring;
    int index;
    
    std::cin >> str >> pattern;
    
    user_logic(str, pattern, result_substring, index);
    
    if (index == -1) {
        std::cout << result_substring << " " << index;
    } else {
        std::cout << result_substring << " " << index;
    }
    
    return 0;
}