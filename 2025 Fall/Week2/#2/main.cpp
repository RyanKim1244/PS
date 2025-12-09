#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 1e5 + 5;
ll N;
ll A[2 * MAXN];
pair<ll, ll> arr[MAXN];

vector<ll> v;
vector<pair<ll, ll>> Query;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j, T; cin >> T;
    while(T--){
        cin >> N;
        for(i = 1;i <= N;i++){
            cin >> arr[i].first >> arr[i].second;

            v.push_back(arr[i].first);
            v.push_back(arr[i].second);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        for(i = 1;i <= N;i++){
            arr[i].first = (lower_bound(v.begin(), v.end(), arr[i].first) - v.begin()) + 1;
            arr[i].second = (lower_bound(v.begin(), v.end(), arr[i].second) - v.begin()) + 1;

            Query.push_back({arr[i].first, 1});
            Query.push_back({arr[i].second, -1});
        }
        sort(Query.begin(), Query.end());

        ll cnt = 0, mx = 0;
        for(i = 0;i < 2 * N;i++){
            cnt += Query[i].second;
            A[Query[i].first - 1] = cnt;
            mx = max(mx, cnt);
        }

        ll sz = v.size(), idx1, idx2;
        for(i = 0;i < sz;i++) {
            if(A[i] == mx) {
                idx1 = i;
                break;
            }
        }

        for(i = sz - 1;i >= 0;i--){
            if(A[i] == mx) {
                idx2 = i + 1;
                break;
            }
        }

        ll ans = 0, MX = 0;
        for(i = 0;i < sz - 1;i++){
            MX = max(MX, A[i]);
            if(MX == mx) break;
            ans += (v[i + 1] - v[i]) * MX;
        }

        MX = 0;
        for(i = sz - 1;i >= 0;i--){
            MX = max(MX, A[i - 1]);
            if(MX == mx) break;
            ans += (v[i] - v[i - 1]) * MX;
        }
        cout << mx << " " << ans + (v[idx2] - v[idx1]) * mx << "\n";

        v.clear(); Query.clear();
        for(i = 0;i < 2 * MAXN;i++) A[i] = 0;
    }
    return 0;
}