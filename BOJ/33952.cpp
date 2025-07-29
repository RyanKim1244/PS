#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;
int N;
int p[MAXN], c[MAXN];

string s;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N; cin >> s;
    
    int C = 0, P = 0;

    for(i = 0;i < N;i++){
        if(s[i] == 'C') C++;
        else P++;

        p[i] = P; c[i] = C;
    }

    if(C * 2 != P) {
        cout << "NO";
        return 0;
    }

    if(s[0] == 'C' || s[N - 1] == 'C'){
        cout << "YES";
        return 0;
    }

    int cnt = 0;
    for(i = 0;i < N - 1;i++){
        if(s[i] == 'C' && s[i + 1] == 'C'){
            if(c[i] * 2 == p[i]) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
