#include <bits/stdc++.h>

using namespace std;

long double x1, y, x2, y2;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> x1 >> y >> x2 >> y2;

    if(x1 > x2) swap(x1, x2);
    if(y > y2) swap(y, y2);
    
    long long X1 = (long long)(ceil(x1));
    long long Y1 = (long long)(ceil(y));
    long long X2 = (long long)(floor(x2));
    long long Y2 = (long long)(floor(y2));

    cout << (X2 - X1 + 1) * (Y2 - Y1 + 1);
    return 0;
}