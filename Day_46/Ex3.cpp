#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;


void precomputePrimes(vector<int> &isPrime, int maxNum) {
    isPrime[0] = isPrime[1] = 0; 
    for (int i = 2; i <= maxNum; ++i) {
        isPrime[i] = 1; 
    }
    for (int i = 2; i * i <= maxNum; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxNum; j += i) {
                isPrime[j] = 0; 
            }
        }
    }
}

int main() {
    int Q;
    cin >> Q;
    vector<int> A(Q);
    int maxNum = 0;
    
    for (int i = 0; i < Q; ++i) {
        cin >> A[i];
        if (A[i] > maxNum) {
            maxNum = A[i];
        }
    }
    

    vector<int> isPrime(maxNum + 1);
    precomputePrimes(isPrime, maxNum);
  
    string result = "";
    for (int i = 0; i < Q; ++i) {
        result += to_string(isPrime[A[i]]);
    }
    
    cout << result << endl;
    return 0;
}