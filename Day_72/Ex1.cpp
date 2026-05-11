#include <bits/stdc++.h>
using namespace std;

// Function to calculate the markings and convert them into a decimal value
int calculateMarkings(const string& barcode) {
    string marking = "";
    marking += barcode[0]; // The first item's marking is the same as its barcode last digit

    // Determine the markings for the rest of the barcodes
    for (size_t i = 1; i < barcode.size(); ++i) {
        if (barcode[i] != marking.back()) { // Compare with the last marking
            marking += '1'; // Different, so mark as 1
        } else {
            marking += '0'; // Same, so mark as 0
        }
    }

    // Check if the resultant marking matches the input barcode
    if (marking == barcode) {
        return -1; // If same, return -1 as per the problem statement
    }

    // Convert the binary marking string into a decimal number
    return stoi(marking, nullptr, 2);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string barcode;
        cin >> barcode;

        // Process each barcode and calculate the result
        cout << calculateMarkings(barcode) << endl;
    }
    return 0;
}