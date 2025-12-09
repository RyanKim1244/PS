#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2e5 + 5;
ll N, Q;
ll D[MAXN], A[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> Q;
    for(i = 1;i <= N;i++) A[i] = D[i] = 1;
    for(i = 1;i <= Q;i++){
        ll a, b; cin >> a >> b;
        A[a] += b;

        D[a] = max(D[a], (A[a] - A[a + 1]) + 1);
        D[a - 1] = max(D[a - 1], (A[a - 1] - A[a]) + 1);
    }

    ll a = 1, ans = 0;
    for(i = 1;i <= N;i++) {
        ans += a, a += D[i];
    }
    cout << ans;
    return 0;
}