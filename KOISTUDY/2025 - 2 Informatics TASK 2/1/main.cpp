#include <bits/stdc++.h>

using namespace std;

int main(void){
    int a, b, c, d, e, f, x = 3;
    while(x--){
        cin >> a >> b >> c >> d >> e >> f;
    
        int A = 3600 * a + 60 * b + c;
        int B = 3600 * d + 60 * e + f;
    
        cout << (B - A) / 3600 << " " << ((B - A) % 3600) / 60 << " " << ((B - A) % 3600) % 60 << "\n";
    }
}