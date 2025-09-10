#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 3e5 + 5, INF = 1e18;
ll N, D;
ll arr[MAXN], S[MAXN], A[MAXN], edge[MAXN];
pair<ll, ll> sparse[MAXN][25];

struct segment{
    ll tree[4 * MAXN], lazy[4 * MAXN];

    void Lazy(ll node, ll s, ll e){
        if(lazy[node] == -INF) return;

        tree[node] = max(tree[node], lazy[node]);
        if(s != e){
            lazy[node * 2] = max(lazy[node * 2], lazy[node]);
            lazy[node * 2 + 1] = max(lazy[node * 2 + 1], lazy[node]);
        }
        lazy[node] = -INF;
    }

    void update(ll node, ll s, ll e, ll l, ll r, ll val){
        ll mid = (s + e) >> 1;

        Lazy(node, s, e);
        if(e < l || r < s || l > r) return;
        if(l <= s && e <= r){
            tree[node] = max(tree[node], val);
            lazy[node] = val;

            Lazy(node, s, e);
            return;
        }
        update(node * 2, s, mid, l, r, val);
        update(node * 2 + 1, mid + 1, e, l, r, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    ll query(ll node, ll s, ll e, ll k){
        Lazy(node, s, e);

        if (s == e) return tree[node];

        ll mid = (s + e) >> 1;
        if (k <= mid) return query(node * 2, s, mid, k);
        else return query(node * 2 + 1, mid + 1, e, k);
    }
}seg;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> D;

    vector<ll> v;
    for(i = 1;i <= N;i++) {
        cin >> arr[i];
        S[i] = S[i - 1] + arr[i];

        v.push_back(arr[i]);
        A[i] = arr[i];
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(i = 1;i <= N;i++) A[i] = (lower_bound(v.begin(), v.end(), A[i]) - v.begin()) + 1;

    for(i = 0;i < 4 * MAXN;i++) seg.lazy[i] = seg.tree[i] = -INF;

    for(i = 1;i <= N;i++){
        ll B = seg.query(1, 1, N, A[i]);
        if(B == -INF) edge[i] = 0;
        else edge[i] = B;

        seg.update(1, 1, N, A[i] + 1, N, i);
    }

    for(i = 1;i <= N;i++) sparse[i][0] = {edge[i], arr[i] * (i - edge[i])};
    for(i = 1;i <= 20;i++){
        for(j = 1;j <= N;j++){
            sparse[j][i] = {sparse[sparse[j][i - 1].first][i - 1].first, sparse[j][i - 1].second + sparse[sparse[j][i - 1].first][i - 1].second};
        }
    }

    ll Q;
    cin >> Q;
    while(Q--){
        ll l, r; cin >> l >> r;

        ll sum = 0, now = r;
        while(1){
            for(i = 20;i >= 0;i--){
                if(sparse[now][i].first >= l) {
                    sum += sparse[now][i].second, now = sparse[now][i].first;
                    break;
                }
            }
            if(sparse[now][0].first < l){
                sum += arr[now] * (now - l + 1);;
                break;
            }
        }
        cout << S[r] - S[l - 1] - sum << "\n";
    }
    return 0;
}

// observation 1 : D 만큼 빼서 주어진 구간을 오름차순으로 만들어야 함.
// subtask 1 : greedy하게 구간 뒤에서부터 보면서 오름차순이 되도록 적절히 D를 빼면 됨.

// subtask 3 : D = 1, 어떤 지점의 물고기에서 왼쪽에 있는 물고기 중 자신보다 작은 것 중 가장 오른쪽으로 간선을 제작.
// subtask 3 : 각각의 쿼리에 대해 sparse table로 구할 수 있음.

// subtask 4 :