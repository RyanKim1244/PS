#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6 + 5, mod = 1e9 + 7;
int N, K;

struct segment{
    pair<int, int> tree[4 * MAXN], lazy[4 * MAXN];

    void Lazy(int node, int s, int e){
        if(lazy[node].second == -1) return;

        if(lazy[node].first == 1){
            tree[node].first = max(tree[node].first, lazy[node].second);
            tree[node].second = max(tree[node].second, lazy[node].second);
        }else{
            tree[node].first = min(tree[node].first, lazy[node].second);
            tree[node].second = min(tree[node].second, lazy[node].second);
        }
        if(s != e){
            int mid = (s + e) >> 1;
            Lazy(node * 2, s, mid);
            Lazy(node * 2 + 1, mid + 1, e);

            if(lazy[node * 2].first == lazy[node].first) {
                if(lazy[node * 2].first == 1) lazy[node * 2].second = max(lazy[node].second, lazy[node * 2].second);
                if(lazy[node * 2].first == 2) lazy[node * 2].second = min(lazy[node].second, lazy[node * 2].second);
            }else{
                lazy[node * 2] = lazy[node];
            }

            if(lazy[node * 2 + 1].first == lazy[node].first){
                if(lazy[node * 2 + 1].first == 1) lazy[node * 2 + 1].second = max(lazy[node].second, lazy[node * 2 + 1].second);
                if(lazy[node * 2 + 1].first == 2) lazy[node * 2 + 1].second = min(lazy[node].second, lazy[node * 2 + 1].second);
            }else{
                lazy[node * 2 + 1] = lazy[node];
            }
        }
        lazy[node] = {0, -1};
    }

    void update(int node, int s, int e, int l, int r, int h, int op){
        int mid = (s + e) >> 1;

        Lazy(node, s, e);
        if(e < l || r < s) return;

        if(l <= s && e <= r){
            lazy[node] = {op, h};
            Lazy(node, s, e);
            return;
        }

        update(node * 2, s, mid, l, r, h, op);
        update(node * 2 + 1, mid + 1, e, l, r, h, op);

        tree[node].first = min(tree[node * 2].first, tree[node * 2 + 1].first);
        tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
    }

    int query(int node, int s, int e, int k){
        int mid = (s + e) >> 1;
        Lazy(node, s, e);

        if(s == e) return tree[node].first;

        if(k <= mid) return query(node * 2, s, mid, k);
        else return query(node * 2 + 1, mid + 1, e, k);
    }
}seg;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N >> K;
    while(K--){
        int op, l, r, h;
        cin >> op >> l >> r >> h; l++; r++;

        seg.update(1, 1, N, l, r, h, op);

        //for(i = 1;i <= N;i++) cout << seg.query(1, 1, N, i) << " ";
        //cout << "\n";
    }
    for(i = 1;i <= N;i++) cout << seg.query(1, 1, N, i) << "\n";
    return 0;
}

// 더하기 query는 A[i] = max(A[i], X);
// 빼기 query는 A[i] = min(A[i], X);