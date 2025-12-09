#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int last[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> a >> b >> c;

    int B = b;
    while(1){
        //cout << a << " " << b << " " << c << "\n";
        c += 7;
        if(a % 400 == 0 || (a % 4 == 0 && a % 100 != 0)) {
            if(b == 2 && c > 29) c %= 29, b++; 
            if(c > last[b]) c %= last[b++];
        }else{
            if(c > last[b]) c %= last[b++];
        }
        if(b == 13) a++, b = 1;

        if((B + 2) % 12 == b) {
            cout << a << " " << b << " " << c;
            break;
        }
    }
    return 0;
}