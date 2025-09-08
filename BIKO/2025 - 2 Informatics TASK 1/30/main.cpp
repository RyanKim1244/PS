#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, K, flag, cnt, FLAG, ans = 21e8;
ll arr[55][55], chk[55][55];

ll fx, fy, ex, ey, X = -1, Y = -1, BEFORE;

void DFS(ll x, ll y, ll before, ll c, ll cost){
    if(c == 0 && FLAG) chk[x][y] = 1;

    if (c == 0 && x == N && y == N) {
        if (before == 1 && arr[x][y] == 5) {
            if (FLAG && K == 1 && cost + 1 == N * N) {
                cout << -1;
                exit(0);
            }
            ans = min(ans, cost + 1);
            return;
        }
        if (before == 2 && arr[x][y] == 2) {
            if (FLAG && K == 1 && cost + 1 == N * N) {
                cout << -1;
                exit(0);
            }
            ans = min(ans, cost + 1);
            return;
        }

        fx = x, fy = y;
        return;
    }

    int fa = 0;
    if(arr[x][y] == 0){
        if(before == 0 && y + 1 <= N) DFS(x, y + 1, 1, c, cost + 1), fa = 1;
        else if(before == 3 && x + 1 <= N) DFS(x + 1, y, 2, c, cost + 1), fa = 1;
    } else if(arr[x][y] == 1) {
        if(before == 1 && x <= N - 1) DFS(x + 1, y, 2, c, cost + 1), fa = 1;
        else if(before == 0 && y >= 2) DFS(x, y - 1, 3, c, cost + 1), fa = 1;
    } else if(arr[x][y] == 2) {
        if(before == 2 && y <= N - 1) DFS(x, y + 1, 1, c, cost + 1), fa = 1;
        else if(before == 3 && x > 1) DFS(x - 1, y, 0, c, cost + 1), fa = 1;
    } else if(arr[x][y] == 3) {
        if(before == 2 && y > 1) DFS(x, y - 1, 3, c, cost + 1), fa = 1;
        else if(before == 1 && x > 1) DFS(x - 1, y, 0, c, cost + 1), fa = 1;
    } else if(arr[x][y] == 4) {
        if(before == 0 && x > 1) DFS(x - 1, y, 0, c, cost + 1), fa = 1;
        else if(before == 2 && x < N) DFS(x + 1, y, 2, c, cost + 1), fa = 1;
    } else if(arr[x][y] == 5) {
        if(before == 1 && y < N) DFS(x, y + 1, 1, c, cost + 1), fa = 1;
        else if(before == 3 && y > 1) DFS(x, y - 1, 3, c, cost + 1), fa = 1;
    }


    if(fa == 0 && c == 0) fx = x, fy = y;
    if(fa == 0 && c == 1) ex = x, ey = y;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> K;

    for(i = 0;i < 55;i++){
        for(j = 0;j < 55;j++){
            arr[i][j] = -1;
        }
    }

    for(i = 1;i <= N;i++){
        for(j = 1;j <= N;j++){
            cin >> arr[i][j];
        }
    }

    FLAG = 1; chk[1][0] = 1;
    DFS(1, 1, 1, 0, 0); FLAG = 0;
    DFS(N, N, 3, 1, 0);

    if (K == 0) {
        if (ans == 21e8) cout << -1;
        else cout << ans;
        return 0;
    }

    int now = arr[fx][fy];

    int FX = fx, FY = fy;
    for(i = 0;i < 6;i++) {
        arr[FX][FY] = i;

        DFS(1, 1, 1, 0, 0);
    }
    arr[FX][FY] = now;

    int EX = ex, EY = ey;
    for(i = 0;i < 6;i++){
        arr[EX][EY] = i;
        DFS(1, 1, 1, 0, 0);
    }

    if(ans == 21e8) cout << -1;
    else cout << ans;
    return 0;
}