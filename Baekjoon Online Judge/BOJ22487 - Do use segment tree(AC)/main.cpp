#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2e5 + 5, INF = 1e15;
ll N, M, idx, lca;
ll w[MAXN], parent[MAXN], subT[MAXN], top[MAXN], in[MAXN], out[MAXN], depth[MAXN];

vector<ll> graph[MAXN], edge[MAXN];

struct Node{
    ll sum, left_max, right_max, Max, max_val;
    bool is_empty;
};

Node Union(Node a, Node b){
    Node ret = {0, -INF, -INF, -INF, -INF, false};

    if(a.is_empty) return b;
    else if(b.is_empty) return a;

    ret.sum = a.sum + b.sum;
    ret.left_max = max(a.left_max, a.sum + b.left_max);
    ret.right_max = max(b.right_max, a.right_max + b.sum);
    ret.Max = max({a.Max, b.Max, a.right_max + b.left_max});
    ret.max_val = max(a.max_val, b.max_val);
    ret.is_empty = false;
    return ret;
}

struct segment{
    Node tree[4 * MAXN];
    ll lazy[4 * MAXN];

    void Lazy(ll node, ll s, ll e){
        if(lazy[node] != INF){
            tree[node].sum = (e - s + 1) * lazy[node];
            if(lazy[node] > 0) tree[node].left_max = tree[node].right_max = tree[node].Max = (e - s + 1) * lazy[node];
            else tree[node].left_max = tree[node].right_max = tree[node].Max = 0LL;
            tree[node].max_val = lazy[node]; tree[node].is_empty = false;
            
            if(s != e){
                lazy[node * 2] = lazy[node];
                lazy[node * 2 + 1] = lazy[node];
            }
            lazy[node] = INF;
        }
    }

    void update(ll node, ll s, ll e, ll k, ll val){
        ll mid = (s + e) >> 1;
        
        if(s == e){
            tree[node].sum = val;
            tree[node].left_max = tree[node].right_max = tree[node].Max = max(0LL, val);
            tree[node].max_val = val; tree[node].is_empty = false;
            return;
        }

        if(k <= mid) update(node * 2, s, mid, k, val);
        else update(node * 2 + 1, mid + 1, e, k, val);

        tree[node] = Union(tree[node * 2], tree[node * 2 + 1]);
    }

    void range_update(ll node, ll s, ll e, ll l, ll r, ll c){
        ll mid = (s + e) >> 1; Lazy(node, s, e);
        if(e < l || r < s || l > r) return;
        if(l <= s && e <= r){
            lazy[node] = c;
            Lazy(node, s, e);
            return;
        }
        range_update(node * 2, s, mid, l, r, c);
        range_update(node * 2 + 1, mid + 1, e, l, r, c);

        tree[node] = Union(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(ll node, ll s, ll e, ll l, ll r){
        ll mid = (s + e) >> 1; Lazy(node, s, e);
        if(e < l || r < s || l > r) {
            Node ret = {0, -INF, -INF, -INF, -INF, true};
            return ret;
        }
        if(l <= s && e <= r) return tree[node];
        return Union(query(node * 2, s, mid, l, r), query(node * 2 + 1, mid + 1, e, l, r));
    }
}seg;

void DFS1(ll node, ll before){
    parent[node] = before;
    for(auto x : graph[node]){
        if(x == before) continue;
        depth[x] = depth[node] + 1;
        DFS1(x, node); subT[node] += subT[x];
    }
    subT[node]++;
}

void DFS2(ll node, ll before){
    for(auto &x : edge[node]){
        if(subT[x] > subT[edge[node][0]]) swap(x, edge[node][0]);
    }
    for(auto x : edge[node]) {
        DFS2(x, node);
    }
}

void DFS3(ll node, ll before){
    in[node] = ++idx;
    for(auto x : edge[node]){
        if(x == edge[node][0]) top[x] = top[node];
        else top[x] = x;
        DFS3(x, node);
    }
    out[node] = idx;
}

ll LCA(ll a, ll b){
    while(top[a] != top[b]){
        if(depth[top[a]] > depth[top[b]]) a = parent[top[a]];
        else b = parent[top[b]];
    }
    return depth[a] < depth[b] ? a : b;
}

void UPDATE(ll a, ll b, ll cost){
    while(top[a] != top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        seg.range_update(1, 1, N, in[top[a]], in[a], cost);
        a = parent[top[a]];
    }
    if(depth[a] > depth[b]) swap(a, b);
    seg.range_update(1, 1, N, in[a], in[b], cost);
}

Node QUERY(ll a, ll b){
    Node ret1 = {0, -INF, -INF, -INF, -INF, true};
    while(top[a] != top[lca]){
        Node A = seg.query(1, 1, N, in[top[a]], in[a]);
        ret1 = Union(A, ret1);

        a = parent[top[a]];
    }
    if(in[a] > in[lca]) {
        Node A = seg.query(1, 1, N, in[lca] + 1, in[a]);
        ret1 = Union(A, ret1);
    }
    swap(ret1.left_max, ret1.right_max);

    Node ret2 = seg.query(1, 1, N, in[lca], in[lca]);

    Node ret3 = {0, -INF, -INF, -INF, -INF, true};
    while(top[b] != top[lca]){
        Node A = seg.query(1, 1, N, in[top[b]], in[b]);
        ret3 = Union(A, ret3);
        b = parent[top[b]];
    }
    if(in[b] > in[lca]) {
        Node A = seg.query(1, 1, N, in[lca] + 1, in[b]);
        ret3 = Union(A, ret3);
    }
    Node res = Union(ret1, ret2);
    res = Union(res, ret3);
    return res;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> M;
    for(i = 1;i <= N;i++) cin >> w[i];
    for(i = 0;i < 4 * MAXN;i++) seg.lazy[i] = INF, seg.tree[i] = {0, -INF, -INF, -INF, -INF, true};
    
    for(i = 1;i < N;i++){
        ll a, b; cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    top[1] = 1;
    DFS1(1, 0);
    
    for(i = 1;i <= N;i++){
        for(auto x : graph[i]){
            if(x == parent[i]) continue;
            edge[i].push_back(x);
        }
    }
    
    DFS2(1, 0); DFS3(1, 0);

    for(i = 1;i <= N;i++) seg.update(1, 1, N, in[i], w[i]);

    ll n = 0;
    while(M--){
        n++;
        ll t, a, b, c; cin >> t >> a >> b >> c;

        if(t == 1){
            lca = LCA(a, b);
            UPDATE(a, b, c);
        }else{
            lca = LCA(a, b);
            Node A = QUERY(a, b);

            if(A.max_val < 0) cout << A.max_val << "\n";
            else cout << A.Max << "\n";
        }
    }
    return 0;
}