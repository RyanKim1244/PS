#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, T;
    cin >> T;
    while(T--){
        int L, R, S; cin >> L >> R >> S;
        cout << min((R - S) * 2, (S - L) * 2 + 1) << "\n";
    }
    return 0;
}