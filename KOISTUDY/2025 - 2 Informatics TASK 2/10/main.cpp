#include <bits/stdc++.h>

using namespace std;

int N, M;
int chk[25];
string s;

vector<string> ans;

void f(int now, int c){
    if(c > M) return;
    if(now == N){
        if(c != M) return;

        string em = "";
        for(int i = 0;i < N;i++) {
            if(!chk[i]) em.push_back(s[i]);
        }

        ans.push_back(em);
        return;
    }

    f(now + 1, c);
    chk[now] = 1;
    f(now + 1, c + 1);
    chk[now] = 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N >> M;
    cin >> s;

    f(0, 0);
    sort(ans.begin(), ans.end());

    for(auto x : ans) cout << x << "\n";
    return 0;
}