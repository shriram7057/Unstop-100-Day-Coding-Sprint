#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

void frequency_sort(std::string& s) {
    std::unordered_map<char, int> freq;
    std::unordered_map<char, int> firstPos;

    // Count frequency and store first occurrence
    for (int i = 0; i < s.size(); i++) {
        freq[s[i]]++;

        if (firstPos.find(s[i]) == firstPos.end()) {
            firstPos[s[i]] = i;
        }
    }

    // Store unique characters
    std::vector<char> chars;
    for (auto &p : freq) {
        chars.push_back(p.first);
    }

    // Sort based on frequency descending
    // If frequency same, earlier occurrence first
    std::sort(chars.begin(), chars.end(),
        [&](char a, char b) {
            if (freq[a] != freq[b])
                return freq[a] > freq[b];

            return firstPos[a] < firstPos[b];
        });

    // Build result string
    std::string result;

    for (char c : chars) {
        result.append(freq[c], c);
    }

    s = result;
}

int main() {
    std::string s;
    std::getline(std::cin, s);

    frequency_sort(s);

    std::cout << s << std::endl;

    return 0;
}