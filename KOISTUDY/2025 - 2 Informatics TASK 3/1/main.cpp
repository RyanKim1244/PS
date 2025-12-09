#include <bits/stdc++.h>

using namespace std;

int N, M, K, X, Y, ans;
int chk[405][405];

void f(int x, int y, int c){
    if(x <= 0 || x > N || y <= 0 || y > M || chk[x - X + 200][y - Y + 200]) return;

    chk[x - X + 200][y - Y + 200] = 1;
    ans++;

    if(c >= K) return;

    f(x + 2, y - 1, c + 1);
    f(x + 2, y + 1, c + 1);
    f(x + 1, y - 2, c + 1);
    f(x + 1, y + 2, c + 1);
    f(x - 1, y - 2, c + 1);
    f(x - 1, y + 2, c + 1);
    f(x - 2, y - 1, c + 1);
    f(x - 2, y + 1, c + 1);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N >> M;
    cin >> X >> Y;

    cin >> K;

    f(X, Y, 0);

    cout << N * M - ans;
    return 0;
}