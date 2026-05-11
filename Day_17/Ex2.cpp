#include <iostream>
#include <vector>
#include <string>

int count_characters(const std::vector<std::string>& words, const std::string& chars) {
    std::vector<int> base(26, 0);

    for (char c : chars) {
        base[c - 'a']++;
    }

    int total = 0;

    for (const std::string& word : words) {
        std::vector<int> freq(26, 0);
        bool valid = true;

        for (char c : word) {
            freq[c - 'a']++;
            if (freq[c - 'a'] > base[c - 'a']) {
                valid = false;
                break;
            }
        }

        if (valid) {
            total += word.length();
        }
    }

    return total;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> words(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> words[i];
    }
    std::string chars;
    std::cin >> chars;
    
    int result = count_characters(words, chars);
    std::cout << result << std::endl;
    return 0;
}