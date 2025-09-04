#include <bits/stdc++.h>

using namespace std;

int A[5], B[5];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    int T; cin >> T;
    while(T--){
        int a; cin >> a;
        for(i = 1;i <= a;i++) {
            int x; cin >> x;
            A[x]++;
        }

        int b; cin >> b;
        for(i = 1;i <= b;i++){
            int y; cin >> y;
            B[y]++;
        }

        if(A[4] > B[4]) cout << "A\n";
        else if(A[4] < B[4]) cout << "B\n";
        else{
            if(A[3] > B[3]) cout << "A\n";
            else if(A[3] < B[3]) cout << "B\n";
            else{
                if(A[2] > B[2]) cout << "A\n";
                else if(A[2] < B[2]) cout << "B\n";
                else{
                    if(A[1] > B[1]) cout << "A\n";
                    else if(A[1] < B[1]) cout << "B\n";
                    else{
                        cout << "D\n";
                    }
                }
            }
        }

        for(i = 1;i <= 4;i++) A[i] = B[i] = 0;
    }
    return 0;
}