#include <bits/stdc++.h>

using namespace std;

int N, l, r;
int arr[105][105], dx[5] = {-1, 0, 1, 0}, dy[5] = {0, 1, 0, -1};

int BFS(){
    queue<pair<int, int>> q;

    int chk[105][105];
    for(int i = 0;i < 105;i++){
        for(int j = 0;j < 105;j++){
            chk[i][j] = 0;
        }
    }

    q.push({1, 1}); chk[1][1] = 1;
    if(arr[1][1] < l || r < arr[1][1]) return 0;
    while(!q.empty()){
        pair<int, int> now = q.front(); q.pop();

        if(now.first == N && now.second == N) return 1;
        
        for(int i = 0;i < 4;i++){
            int X = now.first + dx[i], Y = now.second + dy[i];
            if(X < 1 || X > N || Y < 1 || Y > N) continue;

            if(chk[now.first + dx[i]][now.second + dy[i]]) continue;

            if(arr[X][Y] < l || r < arr[X][Y]) continue;

            q.push({X, Y}); chk[X][Y] = 1;
        }
    }
    return 0;
}

bool check(int x){
    int i, j, k;
    for(i = 0;i <= 200 - x;i++){
        l = i, r = i + x;

        if(BFS()) return true;
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;
    for(i = 1;i <= N;i++){
        for(j = 1;j <= N;j++){
            cin >> arr[i][j];
        }
    }

    int low = 0, high = 200;
    while(low < high){
        int mid = (low + high) / 2;

        if(check(mid)) high = mid;
        else low = mid + 1;
    }

    cout << low;
    return 0;
}