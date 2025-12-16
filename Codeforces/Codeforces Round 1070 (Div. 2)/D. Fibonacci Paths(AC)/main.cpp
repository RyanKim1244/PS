#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2e5 + 5, mod = 998244353;
ll N, M;
ll cost[MAXN];

struct EDGE{
    ll x, y;

    bool operator<(const EDGE&r)const{
        return (cost[x] + cost[y]) > (cost[r.x] + cost[r.y]);
    }
}edge[MAXN];

void solve(){
    ll i, j;
    cin >> N >> M;
    for(i = 1;i <= N;i++) cin >> cost[i];
    for(i = 1;i <= M;i++){
        ll a, b; cin >> a >> b;

        edge[i] = {a, b};
    }
    sort(edge + 1, edge + M + 1);

    vector<map<ll, ll>> dp(N + 1);

    ll ans = 0;
    for(i = 1;i <= M;i++){
        ll x = edge[i].x, y = edge[i].y;

        dp[x][cost[y]] += (1 + dp[y][cost[x] + cost[y]]) % mod; dp[x][cost[y]] %= mod;
        ans += (1 + dp[y][cost[x] + cost[y]]) % mod; ans %= mod;
    }
    cout << ans << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j, T;
    cin >> T;

    while(T--){
        solve();
    }
    return 0;
}