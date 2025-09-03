#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

const ll MAXN = 3e5 + 5;
ll L, N, K;
ll arr[MAXN];

vector<ll> v, ans;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> L >> N >> K;
    for(i = 1;i <= N;i++) cin >> arr[i];

    sort(arr + 1, arr + N + 1);

    for(i = 2;i <= N;i++) v.push_back(arr[i] - arr[i - 1] - 1);

    sort(v.begin(), v.end());
    for(i = 1;i <= N;i++) ans.push_back(0);
    ll idx = 1, sz = v.size();

    if(N == 1) {
        while(1){
            if(arr[1] >= idx) ans.push_back(idx);
            if(arr[1] <= L - idx) ans.push_back(idx);
            idx++;

            if(ans.size() >= K) break;
        }
        ll S = ans.size();
        for(i = 0;i < K;i++) cout << ans[i] << "\n";
        return 0;
    }

    if(arr[1] >= idx) ans.push_back(1);
    if(arr[N] <= L - idx) ans.push_back(1);

    for(i = 0;i < sz;i++){
        if(ans.size() >= K) break;
        if(v[i] < 2 * idx - 1) continue;
        if(v[i] == 2 * idx - 1) { ans.push_back(idx); continue; }
        while(v[i] >= 2 * idx) {
            if(ans.size() >= K) break;
            for(j = 1;j <= (sz - i) * 2;j++) ans.push_back(idx);
            idx++;
            if(arr[1] >= idx) ans.push_back(idx);
            if(arr[N] <= L - idx) ans.push_back(idx);
        }
        i--;
    }
    while(1){
            idx++;
            if(arr[1] >= idx) ans.push_back(idx);
            if(arr[N] <= L - idx) ans.push_back(idx);

            if(ans.size() >= K) break;
        }
    for(i = 0;i < K;i++) cout << ans[i] << "\n";
    return 0;
}