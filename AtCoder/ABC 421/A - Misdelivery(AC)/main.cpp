#include <bits/stdc++.h>

using namespace std;

string s[105];

int main(void){
    int N; cin >> N;
    for(int i = 1;i <= N;i++) cin >> s[i];

    int x; string y;
    cin >> x >> y;
    if(s[x] == y) cout << "Yes";
    else cout << "No";
    return 0;
}