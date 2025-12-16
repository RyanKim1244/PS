#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 1e6 + 5, INF = 1e18;
ll N, S;
ll t[MAXN], T[MAXN], dp[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> S; T[0] = -1;
    for(i = 1;i <= N;i++) {
        cin >> t[i], dp[i] = INF;
        T[i] = max(T[i - 1] + 1, t[i]);
    }

    for(i = 1;i <= N;i++){
        ll l = 0, r = i - 1;
        while(l < r){
            ll mid = (l + r) >> 1LL;
            if(dp[mid] + (i - mid - 1) >= T[i]) r = mid;
            else l = mid + 1;
        }

        if(T[i] >= (i - l - 1) + dp[l]) dp[i] = T[i] + 2 * S + (i - l - 1);
        else dp[i] = dp[l] + (i - l - 1) * 2 + 2 * S;

        if(l > 0) dp[i] = min(dp[i], T[i] + (i - l) + 2 * S);
    }

    cout << dp[N];
    return 0;
}