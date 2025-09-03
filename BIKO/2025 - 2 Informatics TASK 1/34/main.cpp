#include <cstdio>
#include <algorithm>

using namespace std;

int arr[500005];

int main(void){
    int N;
    int i, j;
    scanf("%d", &N);
    
    for(i = 1;i <= N;i++) scanf("%d", &arr[i]);
    
    int Max = 0;
    long long sum = 0;
    for(i = N;i >= 1;i--){
        Max = min(Max + 1, arr[i]);
        
        sum += Max;
    }
    
    printf("%lld", sum);
    return 0;
}
