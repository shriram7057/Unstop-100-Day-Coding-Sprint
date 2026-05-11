#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Sort array
    sort(arr.begin(), arr.end());

    // Convert negatives to positives
    for (int i = 0; i < N && K > 0; i++) {
        if (arr[i] < 0) {
            arr[i] = -arr[i];
            K--;
        }
    }

    // Find minimum absolute value
    long long mini = arr[0];
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        sum += arr[i];
        mini = min(mini, abs(arr[i]));
    }

    // If K is odd, flip smallest absolute value
    if (K % 2 == 1) {
        sum -= 2 * mini;
    }

    cout << sum;

    return 0;
}