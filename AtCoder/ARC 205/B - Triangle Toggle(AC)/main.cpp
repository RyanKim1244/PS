#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2e5 + 5;
ll N, M;
ll deg[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> M;
    for(i = 1;i <= M;i++){
        ll a, b; cin >> a >> b;

        deg[a]++; deg[b]++;
    }

    ll ans = 0;
    for(i = 1;i <= N;i++){
        if((N - 1 - deg[i]) & 1) ans += (N - 2);
        else ans += (N - 1);
    }
    cout << ans / 2;
    return 0;
}