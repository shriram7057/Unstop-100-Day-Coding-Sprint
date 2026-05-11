#include <iostream>
#include <vector>
using namespace std;

int minSwapsCouples(vector<int>& arr) {
    int n = arr.size();
    vector<int> pos(n);

    // Store positions of each person
    for (int i = 0; i < n; i++) {
        pos[arr[i]] = i;
    }

    int swaps = 0;

    for (int i = 0; i < n; i += 2) {
        int first = arr[i];
        int partner = first ^ 1;

        // If already correct pair, continue
        if (arr[i + 1] == partner) continue;

        // Otherwise swap
        int partnerIndex = pos[partner];

        // Update positions
        pos[arr[i + 1]] = partnerIndex;

        swap(arr[i + 1], arr[partnerIndex]);

        swaps++;
    }

    return swaps;
}

int main() {
    int n;
    cin >> n; // Reading the size of the array

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i]; // Reading the elements of the array
    }

    // Call the user logic function and print the output
    int result = minSwapsCouples(arr);
    cout << result << endl; // Display the minimum number of swaps

    return 0;
}