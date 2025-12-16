#include <cstdio>
#include <algorithm>

using namespace std;

long long fact[4000005];
int N, K;
int mod = 1000000007;

long long Pow(long long a, long long b){
    if(b == 0) return 1;
    if(b == 1) return a;
    
    if(b % 2 == 0){
        long long X = Pow(a, b / 2);
        return (X * X) % mod;
    }
    else{
        long long X = Pow(a, b - 1);
        return (X * a) % mod;
    }
}

int main(void){
    int T;
    int i, j;
    scanf("%d", &T);
    
    fact[0] = 1;
    for(i = 1;i <= 4000000;i++){
        fact[i] = ((fact[i - 1]%mod) * (i%mod))%mod;
    }
    
    while(T--){
        scanf("%d %d", &N, &K);
        printf("%lld\n", fact[N] * Pow((fact[K] * fact[N-K]) % mod, mod - 2) % mod);
    }
    return 0;
}
