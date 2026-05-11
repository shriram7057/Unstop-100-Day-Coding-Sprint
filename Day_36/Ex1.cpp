#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n ;
    int arr[n];
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int sum;
    cin >> sum;
    int dp[sum + 5] = {0,};
    dp[0] = 0;
    for (int i = 1; i <= sum ; i++) {
        dp[i] = 1e7;
        for(int j = 0; j < n ; j++) {
            if (i >= arr[j]) {
                dp[i] = min(dp[i],  1 + dp[i - arr[j]]);
            } else break;
        }
    }
    cout << (dp[sum] == 1e7 ? -1 : dp[sum]);


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}