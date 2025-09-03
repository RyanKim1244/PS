#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N, cnt = 0;
    cin >> N;
    for(int i = 1;i <= N;i++){
        int X = i, flag = 0;
        while(X > 0){
            if(X % 10 == 3 || X % 10 == 6 || X % 10 == 9) {
                cnt++;
            }
            X /= 10;
        }
        if(flag) cnt++;
    }
    cout << cnt;
    return 0;
}
