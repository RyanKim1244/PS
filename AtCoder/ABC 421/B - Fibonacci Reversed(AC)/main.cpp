#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll X, Y, n;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> X >> Y;
    for(i = 1;i <= 8;i++){
        ll Z = X + Y;

        ll z = 0;
        while(Z){
            z += (Z % 10);
            if(Z / 10 == 0) break;
            z *= 10; Z /= 10;
        }
        X = Y; Y = z;
    }
    cout << Y;
    return 0;
}