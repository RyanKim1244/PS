#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;
int N;
int h[MAXN], dp[MAXN][MAXN], pos[MAXN][MAXN], B[MAXN][MAXN], S[MAXN][MAXN], D[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;
    for(i = 1;i <= N;i++) {
        cin >> h[i], pos[1][h[i]] = i;
    }

    for(i = 2;i <= N;i++){
        int P = pos[i - 1][i - 1];
        for(j = 1;j <= N;j++) {
            if(j < i) continue;
            if(pos[i - 1][j] > P) pos[i][j] = pos[i - 1][j];
            else if(pos[i - 1][j] < P) pos[i][j] = pos[i - 1][j] + 1;
        }
    }

    for(i = 1;i <= N;i++){
        for(j = i + 1;j <= N;j++) B[h[i]][h[j]]++;
    }

    for(i = 1;i <= N;i++) {
        for(j = 1;j <= N;j++) {
            S[i][j] = S[i][j - 1] + B[i][j];
        }
    }
    

    for(i = 1;i <= N;i++){
        for(j = i;j <= N;j++){
            // j ~ i, j 배치
            dp[i][j] = dp[i][j - 1] + abs(i - pos[i][j]) - (S[j][j - 1] - S[j][i - 1]);
        }
    }

    for(i = 1;i <= N;i++){
        D[i] = 21e8;
        for(j = i;j >= 1;j--){
            D[i] = min(D[i], D[j - 1] + dp[j][i]);
        }
    }
    cout << D[N];
    return 0;
}