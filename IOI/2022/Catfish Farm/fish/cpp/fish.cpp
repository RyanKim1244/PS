#include "fish.h"

#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 5, MAXM = 3e5 + 5;
ll DP[MAXN], Top[MAXN], Down[MAXM], Up[MAXM];

struct Data{
  int y, cost, idx;
  bool operator<(const Data&r)const{
    return y < r.y;
  }
};

struct segment{
  ll tree[4 * MAXN];

  void init(int node, int s, int e){
    int mid = (s + e) >> 1;
    tree[node] = -1e18;
    if(s == e) return;
    init(node * 2, s, mid); init(node * 2 + 1, mid + 1, e);
  }

  void update(int node, int s, int e, int k, ll val){
    int mid = (s + e) >> 1;
    if(s == e){
      tree[node] = max(tree[node], val);
      return;
    }
    if(k <= mid) update(node * 2, s, mid, k, val);
    else update(node * 2 + 1, mid + 1, e, k, val);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
  }

  ll query(int node, int s, int e, int l, int r){
    int mid = (s + e) >> 1;
    if(e < l || r < s) return -1e18;
    if(l <= s && e <= r) return tree[node];
    return max(query(node * 2, s, mid, l, r), query(node * 2 + 1, mid + 1, e, l, r));
  }
}seg1, seg2;

vector<Data> V[MAXN];

long long max_weights(int N, int M, std::vector<int> X, std::vector<int> Y, std::vector<int> W) {
  int i, j;
  for(i = 0;i < M;i++) V[X[i]].push_back({Y[i], W[i], i});
  seg1.init(1, 0, MAXN - 1); seg2.init(1, 1, MAXN);

  for(i = 0;i < N;i++){
    sort(V[i].begin(), V[i].end());
    for(auto &x : V[i]){
      Up[x.idx] = seg1.query(1, 0, MAXN - 1, 0, x.y - 1);
      if(i > 0) Up[x.idx] = max(Up[x.idx], DP[i - 1]);
      else Up[x.idx] = max(Up[x.idx], 0ll);
      Up[x.idx] += x.cost;
      seg1.update(1, 0, MAXN - 1, x.y, Up[x.idx]);
    }
    reverse(V[i].begin(), V[i].end());
    for(auto &x : V[i]){
      Down[x.idx] = seg2.query(1, 0, MAXN - 1, x.y + 1, N - 1);
      if(i > 1) Down[x.idx] = max(Down[x.idx], Top[i - 2]);
      else if(i == 1) Down[x.idx] = max(Down[x.idx], 0ll);
      Down[x.idx] += x.cost;
      seg2.update(1, 0, MAXN - 1, x.y, Down[x.idx]);
    }
    if(i > 0) DP[i] = DP[i - 1];
    DP[i] = max(DP[i], seg2.query(1, 0, MAXN - 1, 0, N - 1));
    if(i > 1) Top[i] = Top[i - 2];
    
    ll Sum = 0;
    for(auto &x : V[i]) Sum += x.cost;
    Top[i] += Sum; Top[i] = max(Top[i], seg1.query(1, 0, MAXN - 1, 0, N - 1));

    if(i > 0) DP[i] = max(DP[i], Top[i - 1]); 
  }
  return DP[N - 1];
}