#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    int a, b, c, d; cin >> a >> b >> c >> d;

    int S = a + b + c + d;
    cout << S / 60 << "\n" << S % 60;
    return 0;
}