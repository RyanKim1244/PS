#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, ans = 0;
    cin >> n;
    if (n & 1){
        for (int i = 1; i <= n; i += 2)
            ans += 4 * i;
    }
    else{
        ans++;
        for (int i = 2; i <= n; i += 2)
            ans += 4 * i;
    }
    cout << ans;
    return 0;
}