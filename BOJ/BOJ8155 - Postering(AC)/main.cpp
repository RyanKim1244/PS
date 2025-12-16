#include <bits/stdc++.h>

using namespace std;

const int MAXN = 250005;
int N, ans;
int arr[MAXN], chk[MAXN];

vector<int> v, s;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;
    for(i = 1;i <= N;i++){
        int a, b; cin >> a >> b;
        arr[i] = b;

        v.push_back(b);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(i = 1;i <= N;i++){
        arr[i] = (lower_bound(v.begin(), v.end(), arr[i]) - v.begin()) + 1;
    }

    for(i = 1;i <= N;i++){
        if(s.size() == 0) ans++, chk[arr[i]] = 1, s.push_back(arr[i]);
        else{
            while(1){
                if(s.size() == 0) break;

                if(s.back() > arr[i]) chk[s.back()] = 0, s.pop_back();
                else break;
            }
            if(chk[arr[i]]) continue;
            else chk[arr[i]] = 1, ans++, s.push_back(arr[i]);
        }
    }
    cout << ans;
    return 0;
}