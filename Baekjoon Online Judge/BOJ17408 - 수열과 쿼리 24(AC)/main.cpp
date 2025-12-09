#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
int N, M;
int arr[MAXN];

struct segment{
    pair<int, int> tree[4 * MAXN];

    void update(int idx, int val, int node = 1, int s = 1, int e = N){
        int mid = (s + e) >> 1;

        if(s == e){
            tree[node] = {val, s};
            return;
        }
        if(idx <= mid) update(idx, val, node * 2, s, mid);
        else update(idx, val, node * 2 + 1, mid + 1, e);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    pair<int, int> query(int l, int r, int node = 1, int s = 1, int e = N){
        int mid = (s + e) >> 1;
        if(l <= s && e <= r) return tree[node];
        if(e < l || r < s || l > r) return {0, 0};

        return max(query(l, r, node * 2, s, mid), query(l, r, node * 2 + 1, mid + 1, e));
    }
}seg;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;
    for(i = 1;i <= N;i++) {
        cin >> arr[i];
        seg.update(i, arr[i]);
    }

    cin >> M;
    while(M--){
        int c; cin >> c;
        if(c == 1){
            int a, b; cin >> a >> b;
            seg.update(a, b);
        }
        else{
            int a, b; cin >> a >> b;

            auto x = seg.query(a, b);
            auto y = seg.query(a, x.second - 1), z = seg.query(x.second + 1, b);

            cout << x.first + max(y.first, z.first) << "\n";
        }
    }
    return 0;
}