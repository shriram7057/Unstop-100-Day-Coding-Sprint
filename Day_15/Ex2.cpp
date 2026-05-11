void interpret(const std::string& s) {
    std::string result;
    int i = 0, n = s.size();

    while (i < n) {
        if (s[i] == 'S') {
            result += "send";
            i++;
        } 
        else if (i + 1 < n && s[i] == '[' && s[i + 1] == ']') {
            result += "the";
            i += 2;
        } 
        else if (i + 4 < n && s.substr(i, 5) == "[sps]") {
            result += "ships";
            i += 5;
        }

        // Add space if not at end
        if (i < n) result += " ";
    }

    std::cout << result;
}