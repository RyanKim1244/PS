#include <bits/stdc++.h>

using namespace std;

int N;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;

    int x = N - 2013;

    cout << char((5 + (x + 2880) % 12) % 12 + 65) << (9 + ((x + 10000) % 10)) % 10;
    return 0;
}