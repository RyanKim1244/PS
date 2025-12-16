#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e6;
ll N;
vector<vector<ll>> matrix;

vector<vector<ll>> multiple(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> ret(2, vector<ll>(2, 0));

    int i, j, k;
    for(i = 0;i < 2;i++){
        for(j = 0;j < 2;j++){
            ll S = 0;
            for(k = 0;k < 2;k++) S += (A[i][k] * B[k][j]) % mod;
            ret[i][j] = S % mod;
        }
    }
    return ret;
}

vector<vector<ll>> POW(vector<vector<ll>> A, ll B){
    if(B == 0) return {{1, 0}, {0, 1}};
    if(B == 1) return A;
    if(B & 1){
        auto X = multiple(POW(A, B - 1), A);
        return X;
    }else{
        auto X = POW(A, B / 2);
        return multiple(X, X);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;

    auto MAT = POW({{1, 1}, {1, 0}}, N);
    cout << MAT[0][1];
    return 0;
}