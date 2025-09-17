#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 5;
int N, A;
int parent[MAXN], D[MAXN], S[MAXN];

vector<int> son[MAXN];

void DFS(int node){
    for(auto x : son[node]) DFS(x), S[node] += S[x];
    S[node]++;
}

void solve(int node){
    vector<int> v;
    for(auto x : son[node]) solve(x), v.push_back(S[x] - 2 * D[x]), D[node] += D[x];

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int l = 0, ans = 0, s = 0;
    int sz = v.size();

    for(int i = 1;i < sz;i++){
        s += v[i];
    }

    if(v.size() <= 1) return;
    if(v[0] > s) D[node] += s, A += s;
    else D[node] += (s + v[0]) / 2; A += (s + v[0]) / 2;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, T; cin >> T;
    while(T--){
        cin >> N;
        for(i = 2;i <= N;i++) {
            cin >> parent[i];

            son[parent[i]].push_back(i);
        }
        DFS(1); solve(1);

        cout << D[1] << "\n";
        A = 0;

        for(i = 1;i <= N;i++) son[i].clear(), D[i] = 0, S[i] = 0;
    }
    return 0;
}