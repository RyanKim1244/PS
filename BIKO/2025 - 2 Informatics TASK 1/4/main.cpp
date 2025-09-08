#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2010, INF = 1e18;

ll N, p1, p2, p3, p4;
ll dp[MAXN][MAXN];
string s1, s2;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N;
    cin >> s1 >> s2;
    cin >> p1 >> p2 >> p3 >> p4;

    for(i = 1;i <= 10;i++) s1.push_back('0'), s2.push_back('0');

    for(i = 0;i < MAXN;i++) for(j = 0;j < MAXN;j++) dp[i][j] = INF;

    dp[0][0] = 0;
    for(i = 1;i <= N + 5;i++) {
        if(i >= 1) {
            dp[i][0] = dp[i - 1][0] + p1;
            dp[0][i] = dp[0][i - 1] + p1;
        }
        if(i >= 3) {
            dp[i][0] = min(dp[i][0], dp[i - 3][0] + p2);
            dp[0][i] = min(dp[0][i], dp[0][i - 3] + p2);
        }
        if(i >= 5) {
            dp[i][0] = min(dp[i][0], dp[i - 5][0] + p3);
            dp[0][i] = min(dp[0][i], dp[0][i - 5] + p3);
        }
        if(s1[i - 1] == '0') dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if(s2[i - 1] == '0') dp[0][i] = min(dp[0][i], dp[0][i - 1]);
    }

    for(i = 1;i <= N + 5;i++){
        for(j = 1;j <= N + 5;j++){
            dp[i][j] = min({dp[i - 1][j] + p1, dp[i][j - 1] + p1, dp[i][j]});
            if(i >= 3) dp[i][j] = min(dp[i][j], dp[i - 3][j] + p2);
            if(j >= 3) dp[i][j] = min(dp[i][j], dp[i][j - 3] + p2);
            if(i >= 5) dp[i][j] = min(dp[i][j], dp[i - 5][j] + p3);
            if(j >= 5) dp[i][j] = min(dp[i][j], dp[i][j - 5] + p3);

            if(i == j && i >= 4) dp[i][j] = min(dp[i][j], dp[i - 4][j - 4] + p4);

            if(s1[i - 1] == '0') dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if(s2[j - 1] == '0') dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }

    ll ans = INF;
    for(i = N;i <= N + 5;i++){
        for(j = N;j <= N + 5;j++) {
            ans = min(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}