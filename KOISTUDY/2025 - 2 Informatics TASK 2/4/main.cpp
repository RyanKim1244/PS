#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, T, idx = 0, last; cin >> T;
    while(T--){
        int ans = 0;
        ++idx; last = 0;

        int a, b, c; cin >> a >> b >> c; // 3 11 4 last = 0
        for(i = 1;i <= a;i++){
            if(c - last >= b) {
                ans++; last += b; last %= c; 
            }else{
                int bb = b;
                bb -= (c - last); ans++;

                ans += (bb + c - 1) / c;
                last += b; last %= c;
            }
        }
        cout << "Case #" << idx << ": " << ans << "\n";
    }   
    return 0;
}