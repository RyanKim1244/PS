#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, T;
    cin >> T;
    while(T--){
        cin >> n >> s;
        
        int idx;
        for(i = n - 1;i >= 0;i--){
            if(s[i] == '1') idx = i;
        }

        int streak = 0, MAX = 0;
        for(i = 0;i < n;i++){
            int now = (idx + i) % n;
            if(s[now] == '0') streak++;
            else MAX = max(MAX, streak), streak = 0;

            MAX = max(MAX, streak);
        }
        cout << MAX << "\n";
    }
    return 0;
}