#include <cstdio>
#include <algorithm>

using namespace std;

int X[3005], T[3005];

int main(void){
    int N;
    int i, j;
    scanf("%d", &N);
    for(i = 1;i <= N;i++) scanf("%d", &X[i]);
    for(i = 1;i <= N;i++) scanf("%d", &T[i]);

    long long ans = X[N];
    for(i = N;i >= 1;i--){
        if(ans < T[i]) ans = T[i];
        ans += (X[i] - X[i - 1]);
    }
    printf("%lld", ans);
    return 0;
}