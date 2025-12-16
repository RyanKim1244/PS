#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXM = 305, INF = 1e18 + 5;
ll M, L;
ll arr[2 * MAXM], use[2 * MAXM], dp[4 * MAXM * MAXM];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> M >> L;
    for(i = 0;i <= 2 * M;i++) cin >> arr[i];

    ll sum = 0, cnt = 0;
    for(i = 0;i <= M * 2;i++) sum += (arr[i] * (i - M)), cnt += arr[i];

    if(sum < L){
        for(i = 0;i <= M;i++) swap(arr[i], arr[2 * M - i]);
        L = -L;
    }

    ll ans = 0;
    sum = 0;
    for(i = 0;i < M;i++) {
        sum += (arr[i]) * (i - M), ans += arr[i];
        use[i] = arr[i]; arr[i] = 0;
    }
    for(i = M + 1;i <= M * 2;i++) {
        if(i == M) continue;
        if(sum + arr[i] * (i - M) >= L){
            ll delta = L - sum;

            if(delta <= 0) continue;
            
            ll A = (delta - 1) / (i - M);
            arr[i] -= A; use[i] = A;
            sum += ((i - M) * A); ans += A;
            break;
        }
        else {
            sum += arr[i] * (i - M), ans += arr[i];
            use[i] = arr[i]; arr[i] = 0;
        }
    }
    for(i = 0;i <= 2 * M * M;i++) dp[i] = -INF;
    dp[M * M] = 0;

    vector<pair<ll, ll>> v;
    for(i = 0;i <= M * 2;i++) {
        if(i == M) continue;
        for(j = 1;arr[i] > 0;j *= 2){
            ll T = min(arr[i], j);
            v.push_back({T, (i - M) * T});
            arr[i] -= T;
        }
        for(j = 1;use[i] > 0;j *= 2){
            ll T = min(use[i], j);
            v.push_back({-T, -(i - M) * T});
            use[i] -= T;
        }
    }

    for(auto x : v){
        if(x.second > 0){
            for(i = 2 * M * M;i >= x.second;i--){
                if(dp[i - x.second] != -INF) dp[i] = max(dp[i], dp[i - x.second] + x.first);
            }
        }else{
            for(i = 0;i <= 2 * M * M + x.second;i++){
                if(dp[i - x.second] != -INF) dp[i] = max(dp[i], dp[i - x.second] + x.first);
            }
        }
    }

    ll DELTA = L - sum;
    if(DELTA < -M * M || M * M < DELTA) cout << "impossible";
    else if(dp[M * M + DELTA] == -INF) cout << "impossible";
    else cout << ans + dp[M * M + DELTA] + arr[M];
    return 0;
}