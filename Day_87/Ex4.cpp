#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    // Sort the boxTypes based on unitsPerBox in descending order
    sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] > b[1]; // Sorting by unitsPerBox descending
    });

    int maxUnits = 0;

    for (auto& box : boxTypes) {
        int count = min(truckSize, box[0]); // Take as many boxes as possible
        maxUnits += count * box[1]; // Add total units from these boxes
        truckSize -= count; // Reduce truck capacity
        
        if (truckSize == 0) break; // Stop if the truck is full
    }

    return maxUnits;
}

int main() {
    int N, M;
    cin >> N >> M; // Read the dimensions (M is always 2 in this problem)

    vector<vector<int>> boxTypes(N, vector<int>(2));
    for (int i = 0; i < N; i++) {
        cin >> boxTypes[i][0] >> boxTypes[i][1]; // Read number of boxes and units per box
    }

    int truckSize;
    cin >> truckSize; // Read the truck capacity

    cout << maximumUnits(boxTypes, truckSize) << endl; // Print the result

    return 0;
}