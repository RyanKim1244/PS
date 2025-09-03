#include <bits/stdc++.h>

using namespace std;

int N, X;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, ans = 0;
    cin >> N >> X;

    for(i = 1;i <= N;i++){
        int a, b; cin >> a >> b;

        if(a + b <= X) ans = max(ans, a);
    }
    if(ans == 0) cout << -1;
    else cout << ans;
    return 0;
}