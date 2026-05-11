#include <iostream>
#include <string>
void make_me_lucky(const std::string &S, const std::string &U) {
    std::string result;
    int m = U.length();

    for(char ch : S) {
        result += ch;

        // Check if the end of result matches U
        if(result.length() >= m &&
           result.substr(result.length() - m) == U) {
            result.erase(result.length() - m);
        }
    }

    std::cout << result;
}

int main() {
    std::string S, U;
    std::cin >> S >> U;
    make_me_lucky(S, U);
    return 0;
}