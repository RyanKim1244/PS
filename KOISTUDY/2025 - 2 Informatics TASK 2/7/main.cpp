#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, W;
int dp[1005][1005];

vector<int> list;
pair<int, int> arr[1005];

int dist(int x, int y){
    if(x == 0) return abs(arr[y].first - 1) + abs(arr[y].second - 1);
    else if(y == 0) return abs(arr[x].first - N) + abs(arr[x].second - N);
    else return abs(arr[x].first - arr[y].first) + abs(arr[x].second - arr[y].second);
}

int main(void){
    int i, j;
    scanf("%d %d", &N, &W);
    
    for(i = 1;i <= W;i++){
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    
    for(i = 0;i <= W;i++) dp[i][W] = dp[W][i] = 0;
    
    for(i = W - 1;i >= 0;i--){
        for(j = 0;j < i;j++){
            int now = max(i, j);
            dp[i][j] = min(dp[now + 1][j] + dist(i, now + 1), dp[i][now + 1] + dist(now + 1, j));
            dp[j][i] = min(dp[now + 1][i] + dist(j, now + 1), dp[j][now + 1] + dist(now + 1, i));
        }
    }
    
    dp[0][0] = min(dp[1][0] + dist(0, 1), dp[0][1] + dist(1, 0));
    
    int now_x = 0, now_y = 0;
    
    while(1){
        int now = max(now_x, now_y);
        if(now == W) break;
        if(dp[now_x][now_y] - dist(now_x, now + 1) == dp[now + 1][now_y]){
            now_x = now + 1, list.push_back(1);
        }
        else if(dp[now_x][now_y] - dist(now + 1, now_y) == dp[now_x][now + 1]){
            now_y = now + 1, list.push_back(2);
        }
    }
    
    printf("%d\n", dp[0][0]);
    return 0;
}
