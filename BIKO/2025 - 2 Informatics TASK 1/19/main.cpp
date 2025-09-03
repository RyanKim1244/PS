#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 21e8;

int ch[105], dp[105][105];

int main(void)
{
    int i, j, k;
    int n, m, a, idx, ans = INF;
    scanf("%d %d", &n, &m);
    for(i = 1;i <= m;i++){
        scanf("%d", &a);
        ch[a] = 1;
    }
    for(i = 1;i <= n;i++) dp[0][i] = INF;
    for(i = 1;i <= n;i++){

        for(j = 0;j <= n;j++){
            dp[i][j] = INF;
            if(ch[i]){
                dp[i][j] = dp[i - 1][j];
                if(j - 1 >= 0 && i - 3 >= 0 && dp[i - 3][j - 1] != INF) dp[i][j] = min(dp[i][j], dp[i - 3][j - 1] + 25000);
                if(j - 2 >= 0 && i - 5 >= 0 && dp[i - 5][j - 2] != INF) dp[i][j] = min(dp[i][j], dp[i - 5][j - 2] + 37000);
            }
            if(j >= 3 && dp[i - 1][j] != INF) dp[i][j - 3] = min(dp[i - 1][j], dp[i][j - 3]);
            if(i - 1 >= 0 && dp[i - 1][j] != INF) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 10000);
            if(j - 1 >= 0 && i - 3 >= 0 && dp[i - 3][j - 1] != INF) dp[i][j] = min(dp[i][j], dp[i - 3][j - 1] + 25000);
            if(j - 2 >= 0 && i - 5 >= 0 && dp[i - 5][j - 2] != INF) dp[i][j] = min(dp[i][j], dp[i - 5][j - 2] + 37000);
        }

    }
    for(i = 0; i <= n;i++) ans = min(dp[n][i], ans);
    printf("%d", ans);
    return 0;
}
