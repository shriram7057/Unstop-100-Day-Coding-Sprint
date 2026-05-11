#include <bits/stdc++.h>
using namespace std;

int minimumOperationsBit(int n, int res) {

    if(n == 0) return res;

    int b =1;
    while((b << 1) <= n) b = b<<1;

    return minimumOperationsBit((b>>1)^b ^n, res + b);
}

int sieveOfEratosthenes(int n) {

    bool prime[n + 1];
    for(int i=0; i<=n; i++) {
        prime[i] = true;
    }


    for(int p=2; p*p<=n; p++) {
        if(prime[p] == true) {
            for(int i=p*p; i<=n; i+=p)
                prime[i] = false;
        }
    }

    int count=0;
    for(int i=2; i<=n; i++) {
        if(prime[i] == true) count++;
    }
    return count;
}

int main() {
    
    int n;
    cin>>n;

    int ans = minimumOperationsBit(n, 0);
    cout<<sieveOfEratosthenes(ans)<<endl; 
    return 0;
}