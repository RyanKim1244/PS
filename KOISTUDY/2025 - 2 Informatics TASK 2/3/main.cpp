#include <bits/stdc++.h>

using namespace std;

int main(void){
    int i, j;
    int T; scanf("%d", &T);
    while(T--){
        int a, b; scanf("%d %d", &a, &b);

        int X = 0, Y = 0;
        while(1){
            X += a; Y += b; X += 60; Y += 60;
            X %= 1440; Y %= 1440;

            if(X == Y){
                printf("%02d:%02d\n", X / 60, X % 60);
                break;
            }
        }
    }
    return 0;
}