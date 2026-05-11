#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c = 0, C = 0;

    // Count occurrences of "pqr" and replace them with '?'
    size_t pos = s.find("pqr");
    while (pos != string::npos) {
        s.replace(pos, 3, "?");
        pos = s.find("pqr");
    }

    // Count occurrences of "pq" and replace them with '?'
    pos = s.find("pq");
    while (pos != string::npos) {
        C++;
        s.replace(pos, 2, "?");
        pos = s.find("pq");
    }

    // Count occurrences of "qr" and replace them with '?'
    pos = s.find("qr");
    while (pos != string::npos) {
        C++;
        s.replace(pos, 2, "?");
        pos = s.find("qr");
    }

    // Count occurrences of "pr" and replace them with '?'
    pos = s.find("pr");
    while (pos != string::npos) {
        C++;
        s.replace(pos, 2, "?");
        pos = s.find("pr");
    }

    // Count the number of 'p', 'q', and 'r' and calculate additional replacements
    c = count(s.begin(), s.end(), 'p') + count(s.begin(), s.end(), 'q') + count(s.begin(), s.end(), 'r');
    C += 2 * c;

    cout << C << endl;

    return 0;
}