#include <iostream>
#include <vector>
#include <string>
bool pudding(const std::string& n) {
    // Check if last character is '0'
    return n.back() != '0';
}

int main() {
    int T;
    std::cin >> T;
    std::vector<bool> results(T);
    std::string n;

    for (int i = 0; i < T; ++i) {
        std::cin >> n;
        results[i] = pudding(n);
    }

    for (bool result : results) {
        std::cout << (result ? 1 : 0) << std::endl;
    }

    return 0;
}