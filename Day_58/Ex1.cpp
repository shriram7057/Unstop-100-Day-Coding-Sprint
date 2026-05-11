#include <iostream>
#include <string>
using namespace std;

string user_logic(int a, int b, int c, int d) {
    int total = a + b + c + d;

    // If total sum is odd, equal partition is impossible
    if (total % 2 != 0)
        return "NO";

    int target = total / 2;

    // Check all possible subsets
    if (a == target || b == target || c == target || d == target ||
        a + b == target || a + c == target || a + d == target ||
        b + c == target || b + d == target || c + d == target)
        return "YES";

    return "NO";
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    // Call user logic function and print the output
    string result = user_logic(a, b, c, d);
    cout << result << endl;
    return 0;
}