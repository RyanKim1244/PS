#include <bits/stdc++.h>

using namespace std;

const int MAXN = 305, MAX = 1e5 + 5;
int N, S;
int arr[MAXN];

bool chk[MAX], temp[MAX];
bool dp[MAXN][MAX];
queue<int> q[MAX];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;
    for(i = 1;i <= N;i++) {
        cin >> arr[i];
        S += arr[i]; q[arr[i]].push(i);
    }
    
    sort(arr + 1, arr + N + 1);

    temp[0] = true;
    int ans = 0, idx_i, idx_j;
    for(i = N;i >= 1;i--){
        for(j = 0;j < MAX - arr[i];j++){
            if(temp[j]) {
                chk[j] = chk[j + arr[i]] = true;
                dp[i][j] = 0; dp[i][j + arr[i]] = 1;
            }
        }

        for(j = 0;j < MAX;j++){
            if(chk[j] == 0) continue;

            if(j - arr[i] <= S / 2 && ans < j) {
                idx_i = i, idx_j = j; ans = j;
            }
        }
        for(j = 0;j < MAX;j++) {
            temp[j] = chk[j], chk[j] = false;
        }
    }

    vector<int> v;
    while(idx_i <= N){
        if(dp[idx_i][idx_j]) {
            v.push_back(arr[idx_i]);
            idx_j -= arr[idx_i];
        }
        idx_i++;
    }

    vector<int> A;
    for(auto x : v){
        if(x == 0) continue;
        A.push_back(q[x].front()); q[x].pop();
    }

    cout << A.size() << "\n";
    for(auto x : A) cout << x << " ";
    return 0;
}