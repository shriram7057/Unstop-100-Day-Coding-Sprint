#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), result(N);
    vector<bool> occupied(N, false);  // Track seat occupancy

    // Read preferred seat numbers
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;  // Convert 1-based to 0-based index
    }

    for (int i = 0; i < N; i++) {
        int seat = A[i];  // Preferred seat
        while (occupied[seat]) {
            seat = (seat + 1) % N;  // Move circularly
        }
        occupied[seat] = true;
        result[i] = seat + 1;  // Convert back to 1-based index
    }

    // Print the final seating arrangement
    for (int seat : result) {
        cout << seat << " ";
    }
    cout << endl;

    return 0;
}