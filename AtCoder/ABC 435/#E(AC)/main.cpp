#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXQ = 2e5 + 5;
ll N, Q;
pair<ll, ll> arr[MAXQ];
vector<ll> v;
unordered_map<ll, ll> C;

struct segment{
    ll tree[8 * MAXQ], lazy[8 * MAXQ];

    void Lazy(ll node, ll s, ll e){
        if(lazy[node]){
            tree[node] = C[e + 1] - C[s];
            if(s != e){
                lazy[node * 2] = 1;
                lazy[node * 2 + 1] = 1;
            }
        }
        lazy[node] = 0;
    }

    void update(ll node, ll s, ll e, ll l, ll r){
        ll mid = (s + e) >> 1; Lazy(node, s, e);
        if(e < l || r < s || l > r) return;

        if(l <= s && e <= r){
            lazy[node] = 1; Lazy(node, s, e);
            return;
        }

        update(node * 2, s, mid, l, r);
        update(node * 2 + 1, mid + 1, e, l, r);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update1(ll node, ll s, ll e, ll k){
        ll mid = (s + e) >> 1;
        Lazy(node, s, e);
        if(s == e){
            tree[node] = max(tree[node], 1LL);
            return;
        }
        if(k <= mid) update1(node * 2, s, mid, k);
        else update1(node * 2 + 1, mid + 1, e, k);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}seg;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> Q;
    for(i = 1;i <= Q;i++){
        ll a, b; cin >> a >> b;
        arr[i] = {a, b + 1};
        v.push_back(a); v.push_back(b + 1);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(i = 1;i <= Q;i++) {
        ll X = arr[i].first, Y = arr[i].second;
        arr[i].first = (lower_bound(v.begin(), v.end(), arr[i].first) - v.begin()) + 1;
        arr[i].second = (lower_bound(v.begin(), v.end(), arr[i].second) - v.begin()) + 1;

        C[arr[i].first] = X;
        C[arr[i].second] = Y;
    }

    ll sz = v.size();
    for(i = 1;i <= Q;i++){
        seg.update(1, 1, sz, arr[i].first, arr[i].second - 1);
        //seg.update1(1, 1, sz, arr[i].second);

        cout << N - seg.tree[1] << "\n";
    }
    return 0;
}
