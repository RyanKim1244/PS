#include <bits/stdc++.h>

using namespace std;

string s;
vector<long long> v;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long i, j;
    cin >> s;
    for(auto x : s) v.push_back(x - '0');

    long long A = 0;
    for(i = 0;i < s.size();i++){
        for(j = i;j < s.size();j++){
            long long ans = 0;
            for(long long k = i;k <= j;k++) ans += v[k], ans *= 10;
            ans /= 10;

            //cout << ans << " " << max(1, ((1 << i)) - 1) * max(1, ((1 << (s.size() - j - 1)) - 1)) << "\n";

            A += ans * max(1LL, ((1LL << (max(0LL, (long long)(i - 1))))) * max(1LL, ((1LL << max(0LL, (long long)(s.size() - j - 2))))));
        }
    }
    cout << A;
    return 0;
}