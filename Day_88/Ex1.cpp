#include <iostream>
#include <vector>

using namespace std;

int binaryToDecimal(vector<int>& binaryList) {
    int decimalValue = 0;
    
    for (int bit : binaryList) {
        decimalValue = decimalValue * 2 + bit; // Left shift and add the bit
    }

    return decimalValue;
}

int main() {
    int n;
    cin >> n; // Read number of nodes
    
    vector<int> binaryList(n);
    for (int i = 0; i < n; i++) {
        cin >> binaryList[i]; // Read the binary digits
    }

    cout << binaryToDecimal(binaryList) << endl; // Print decimal equivalent

    return 0;
}