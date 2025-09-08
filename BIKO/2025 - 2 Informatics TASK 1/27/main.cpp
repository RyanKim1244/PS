#include <bits/stdc++.h>

using namespace std;

string S, T;
vector<int> pos[30];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> S >> T;

    int T_size = T.size();
    for(i = 0;i < T_size;i++){
        pos[T[i] - 'a'].push_back(i);
    }

    int S_size = S.size(), last = -1, ans = 1;
    for(i = 0;i < S_size;i++){
        int now = S[i] - 'a';

        if(pos[now].empty()){
            cout << -1;
            return 0;
        }

        while(1){
            auto I = lower_bound(pos[now].begin(), pos[now].end(), last + 1);
            if(I == pos[now].end()) last = -1, ans++;
            else { last = *I; break; }
        }
    }
    cout << ans;
    return 0;
}