#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        long long X;
        cin >> N >> X;

        string S;
        cin >> S;

        set<long long> visitedPoints;
        visitedPoints.insert(X);

        for (char command : S) {
            if (command == 'L') {
                X--;
            } else if (command == 'R') {
                X++;
            }
            visitedPoints.insert(X);
        }

        cout << visitedPoints.size() << endl;
    }

    return 0;
}