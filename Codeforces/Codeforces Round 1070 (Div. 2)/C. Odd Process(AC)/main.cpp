#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
ll arr[200005], ans[200005];

vector<ll> odd, even;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j, T;
    cin >> T;
    while(T--){
        cin >> n;
        for(i = 1;i <= n;i++) {
            cin >> arr[i];

            if(arr[i] & 1) odd.push_back(arr[i]);
            else even.push_back(arr[i]);
        }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        for(i = 1;i <= n;i++){
            if(odd.size() == 0 || (i == n && odd.size() % 2 == 0)) cout << 0 << " ";
            else{
                if(i - 1 <= even.size()){
                    if(i == 1) ans[i] = odd[odd.size() - 1];
                    else ans[i] = ans[i - 1] + even[even.size() - i + 1];
                }
                else ans[i] = ans[i - 2];
                cout << ans[i] << " ";
            }
        }
        cout << "\n";
        odd.clear(), even.clear();
    }
    return 0;
}