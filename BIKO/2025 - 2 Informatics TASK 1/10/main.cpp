#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll arr[300000];
ll jisu[300000];

ll getjisu(ll num, ll target)
{
    ll rtn = 0;
    if (num < target){
        while (num < target){
            num *= 2;
            rtn++;
        }
    }
    else{
        while (num >= 2*target){
            target *= 2;
            rtn--;
        }
    }

    return rtn;
}

int main()
{
    ll N; cin>>N;
    for (ll i=1; i<=N; i++) cin>>arr[i];

    for (ll i=2; i<=N; i++){
        jisu[i] = max(0LL, jisu[i-1] + getjisu(arr[i], arr[i-1]));
    }

    ll ans = 0;
    for (ll i=1; i<=N; i++){
        ans += jisu[i];
    }

    cout<<ans<<endl;

    //for (ll i=1; i<=N; i++) cout<<jisu[i]<<' ';

    return 0;
}
