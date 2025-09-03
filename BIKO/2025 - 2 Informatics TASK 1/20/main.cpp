#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int N, C;
int dp[MAXN][MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N >> C;

    for(i = 1;i <= C;i++){
        int a, b; cin >> a >> b;

        if (a > b) {
            if (a <= N && (a - 1) - b <= N - (a - 1)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }else if (a < b) {
            if (b <= N && b - a <= N - (b - 1)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }else {
            if (a <= N) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
    return 0;
}