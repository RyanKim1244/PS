#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2e5 + 5;
ll N, M, Q;
ll sum1, sum2, sum3;
ll A[MAXN], B[MAXN];
vector<ll> v;
multiset<ll> s1, s2, s3;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> M >> Q;
    for(i = 1;i <= N;i++) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    for(i = 1;i <= M;i++) {
        cin >> B[i];
        v.push_back(B[i]);
    }
    sort(v.begin(), v.end());

    for(i = 0;i < N / 2;i++) s1.insert(v[i]), sum1 += v[i];
    for(i = N / 2;i < N / 2 + M;i++) s2.insert(v[i]), sum2 += v[i];
    for(i = N / 2 + M;i < N + M;i++) s3.insert(v[i]), sum3 += v[i];

    while(Q--){
        ll c, a, b; cin >> c >> a >> b;

        ll E, P;
        if(c == 1) E = A[a], A[a] = b;
        else E = B[a], B[a] = b;

        P = b; 
        if(*prev(s1.end()) >= E) {
            auto iter = s1.lower_bound(E);
            s1.erase(iter); sum1 -= E;
        }
        else if(*prev(s2.end()) >= E){
            auto iter = s2.lower_bound(E);
            s2.erase(iter); sum2 -= E;
        }
        else{
            auto iter = s3.lower_bound(E);
            s3.erase(iter); sum3 -= E;
        }

        if(s3.size() && *s3.begin() <= P) {
            s3.insert(P);
            sum3 += P;
        }
        else if(s2.size() && *s2.begin() <= P){
            s2.insert(P);
            sum2 += P;
        }
        else{
            s1.insert(P);
            sum1 += P;
        }

        if(s1.size() < N / 2){
            s1.insert(*s2.begin()); sum1 += *s2.begin();
            sum2 -= *s2.begin();
            auto iter = s2.lower_bound(*s2.begin()); s2.erase(iter);
        }else if(s1.size() > N / 2){
            ll A = *prev(s1.end()); sum1 -= A; sum2 += A;
            auto iter = s1.lower_bound(A); s1.erase(iter);
            s2.insert(A);
        } // 3 8 2

        if(s2.size() < M){
            s2.insert(*s3.begin()); sum2 += *s3.begin();
            sum3 -= *s3.begin();
            auto iter = s3.lower_bound(*s3.begin()); s3.erase(iter);
        }else if(s2.size() > M){
            ll A = *prev(s2.end()); sum2 -= A; sum3 += A;
            auto iter = s2.lower_bound(A); s2.erase(iter);
            s3.insert(A);
        }

        cout << sum1 + sum3 << "\n";
    }
    return 0;
}