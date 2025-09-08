#include <bits/stdc++.h>

using namespace std;

int N, K;
int cnt[2][3];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N >> K;
    for(i = 1;i <= N;i++){
        int a, b; cin >> a >> b;
        cnt[a][(b - 1) / 2]++;
    }

    int ans = 0;
    for(i = 0;i < 2;i++){
        for(j = 1;j < 3;j++){
            ans += (cnt[i][j] + K - 1) / K;
        }
    }
    cout << ans + (cnt[0][0] + cnt[1][0] + K - 1) / K;
    return 0;
}