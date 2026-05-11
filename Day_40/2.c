#include <stdio.h>

#define MOD 998244353
#define MAX 600000

long long fact[MAX], invfact[MAX];

long long modpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

void init(){
    fact[0]=1;
    for(int i=1;i<MAX;i++)
        fact[i]=fact[i-1]*i%MOD;

    invfact[MAX-1]=modpow(fact[MAX-1],MOD-2);

    for(int i=MAX-2;i>=0;i--)
        invfact[i]=invfact[i+1]*(i+1)%MOD;
}

long long C(int n,int r){
    if(r<0 || r>n) return 0;
    return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;
}

int user_logic(int N,int M,int K){

    init();

    long long ans=0;

    for(int i=0;i<=N;i++){

        long long shift=(long long)i*(M+1);
        if(shift>K) break;

        long long ways=C(N,i);

        long long remain=K-shift;

        long long sum=0;

        for(int s=0;s<=remain;s++){
            sum=(sum + C(s+N-1,N-1))%MOD;
        }

        if(i%2)
            ans=(ans - ways*sum%MOD + MOD)%MOD;
        else
            ans=(ans + ways*sum%MOD)%MOD;
    }

    return ans;
}

int main(){

    int N,M,K;

    scanf("%d %d %d",&N,&M,&K);

    int result=user_logic(N,M,K);

    printf("%d\n",result);

    return 0;
}