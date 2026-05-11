#include <iostream>
#include <vector>
#include <string>

int check_word_break(std::string goal, std::vector<std::string> target_words) {
    int n = goal.length();

    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        if (!dp[i]) continue;

        for (std::string word : target_words) {
            int len = word.length();

            if (i + len <= n && goal.substr(i, len) == word) {
                dp[i + len] = 1;
            }
        }
    }

    return dp[n];
}
int main() {
    int n;
    std::cin >> n;
    std::string goal;
    std::cin >> goal;
    std::vector<std::string> target_words(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> target_words[i];
    }
    int result = check_word_break(goal, target_words);
    std::cout << result << std::endl;
    return 0;
}