#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 5, MAXM = 1e6 + 5;
int N, M;
int ind[MAXN], sp[MAXN], ep[MAXN], erase_list[MAXN];

queue<int> q;
priority_queue<int> pq1, pq2;
vector<int> edge[MAXN], rev_edge[MAXN], topo;

struct segment{
    int cnt[4 * MAXN], mx[4 * MAXN];

    void update(int node, int s, int e, int k, int val){
        int mid = (s + e) >> 1;
        
        if(s == e){
            cnt[node] += val;
            if(cnt[node]) mx[node] = s;
            else mx[node] = 0;
            return;
        }
        if(k <= mid) update(node * 2, s, mid, k, val);
        else update(node * 2 + 1, mid + 1, e, k, val);

        cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
        mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
    }
}seg;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N >> M;
    for(i = 1;i <= M;i++){
        int a, b; cin >> a >> b;

        edge[a].push_back(b);
        rev_edge[b].push_back(a);
        ind[b]++;
    }

    for(i = 1;i <= N;i++) {
        if(ind[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int a = q.front(); q.pop();
        topo.push_back(a);

        for(auto x : edge[a]) {
            ind[x]--;
            if(ind[x] == 0) q.push(x);
        }
    }

    for(i = 0;i < N;i++){
        for(auto x : edge[topo[i]]) {
            ep[x] = max(ep[x], ep[topo[i]] + 1);
        }
    }

    for(i = N - 1;i >= 0;i--){
        for(auto x : rev_edge[topo[i]]){
            sp[x] = max(sp[x], sp[topo[i]] + 1);
        }
    }

    int ans = 21e8, idx;
    for(i = 1;i <= N;i++) pq1.push(sp[i]);
    for(i = 0;i < N;i++){
        int now = topo[i];

        erase_list[sp[now]]++;
        for(auto x : rev_edge[now]) erase_list[ep[x] + sp[now] + 1]++;

        while(1){
            int A = pq1.top();
            if(erase_list[A]) { pq1.pop(); erase_list[A]--; }
            else break;
        }

        int X = 0, Y = 0;
        if(!pq1.empty()) X = pq1.top();
        if(!pq2.empty()) Y = pq2.top();

        if(ans > max(X, Y)) ans = max(X, Y), idx = now;
        pq1.push(ep[now]);
        for(auto x : edge[now]) pq1.push(ep[now] + sp[x] + 1);
    }
    cout << idx << " " << ans;
    return 0;
}