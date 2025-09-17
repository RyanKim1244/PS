#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
int N;
int deg[MAXN];
pair<int, int> arr[MAXN];

vector<int> v[MAXN];
unordered_map<int, int> m;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;

    for(i = 1;i <= N;i++) cin >> arr[i].first >> arr[i].second, m[arr[i].first] = i;

    sort(arr + 1, arr + N + 1);

    int flag = 0;
    for(i = 2;i <= N;i++){
        if(arr[i].second < arr[i - 1].second) flag = 1;

        if(arr[i].first < arr[i - 1].second) v[i].push_back(i - 1), deg[i - 1]++;
        if(arr[i].second < arr[i - 1].first) v[i - 1].push_back(i), deg[i]++;
    }

    if(flag){
        cout << "No";
        return 0;
    }

    queue<int> q;
    for(i = 1;i <= N;i++) {
        if(deg[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()){
        int x = q.front(); ans.push_back(m[arr[x].first]); q.pop();

        for(auto t : v[x]) {
            deg[t]--;
            if(deg[t] == 0) q.push(t);
        }
    }

    if(ans.size() < N) cout << "No";
    else{
        cout << "Yes" << "\n";
        for(auto x : ans) cout << x << " ";
    }
    return 0;
}