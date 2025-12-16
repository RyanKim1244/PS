#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    int a, b, c, d; cin >> a >> b >> c >> d;

    cout << min(max(a, c) * 2 + 2 * (b + d), max(b, d) * 2 + 2 * (a + c));
}