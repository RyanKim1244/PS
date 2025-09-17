#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
int N, Q;

int A[MAXN][MAXN], S[MAXN][MAXN];
char arr[MAXN][MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N >> Q;
    for(i = 1;i <= N;i++){
        for(j = 1;j <= N;j++) {
            cin >> arr[i][j];
        }
    }

    for(i = 1;i < N;i++){
        for(j = 1;j < N;j++){
            int cnt = 0;
            if(arr[i][j] == '.' && arr[i + 1][j] == '.' && arr[i][j + 1] == '.' && arr[i + 1][j + 1] == '.') cnt++;
            A[i][j] = cnt;
        }
    }

    for(i = 1;i <= N;i++){
        for(j = 1;j <= N;j++){
            S[i][j] = S[i][j - 1] + S[i - 1][j] - S[i - 1][j - 1] + A[i][j];
        }
    }

    while(Q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << S[b - 1][d - 1] - S[a - 1][d - 1] - S[b - 1][c - 1] + S[a - 1][c - 1] << "\n";
    }
    return 0;
}