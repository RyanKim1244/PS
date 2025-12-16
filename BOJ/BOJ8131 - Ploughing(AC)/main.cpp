#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2005, INF = 21e8;
ll K, M, N;
ll arr[MAXN][MAXN], brr[MAXN][MAXN], S[MAXN][MAXN];

ll SUM(ll x, ll X, ll y, ll Y){
    return S[X][Y] - S[x - 1][Y] - S[X][y - 1] + S[x - 1][y - 1];
}

ll check(ll l, ll r){
    ll k = (r - l + 1);
    ll a = 1, b = N, c = 1, d = M;

    for(ll i = 0;i < N + M - k - 1;i++){
        if(b - a + 1 > 1 && SUM(a, a, c, d) <= K) { a++; continue; }
        if(b - a + 1 > 1 && SUM(b, b, c, d) <= K) { b--; continue; }
        if(c < l && SUM(a, b, c, c) <= K) { c++; continue; }
        if(d > r && SUM(a, b, d, d) <= K) { d--; continue; }
        return 0;
    }
    if(SUM(a, b, c, d) <= K) return 1;
    return 0;
}

ll solve(){
    ll i, j;
    ll l = 1, r = 1;
    ll ans = INF;

    for(i = 1;i <= N;i++){
        for(j = 1;j <= M;j++){
            S[i][j] = arr[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];  
        }
    }

    while(1){
        ll chk = check(l, r);
        if(chk) ans = min(ans, N + M - (r - l + 1));

        if(l == M && r == M) break;
        if(r == M) l++;
        else if(l == r || chk) r++;
        else l++;
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> K >> M >> N;

    for(i = 1;i <= N;i++){
        for(j = 1;j <= M;j++){
            cin >> arr[i][j]; brr[i][j] = arr[i][j];
        }
    }

    ll ans1 = solve();
    for(i = 1;i <= M;i++){
        for(j = 1;j <= N;j++){
            arr[i][j] = brr[N - j + 1][i];
        }
    }
    swap(N, M);

    ll ans2 = solve();
    cout << min(ans1, ans2);
    return 0;
}