#include <iostream>
#include <algorithm>

using namespace std;

int N, K, P;
int arr[2505];

int main(void) {
	int i, j;
	int cnt = 0, ans = 0, idx = 1;
	cin >> N >> K >> P;
	for (i = 1; i <= N * K; i++) {
		cin >> arr[i];
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= K; j++) {
			if (arr[idx++] == 0) cnt++;
		}
		if (cnt < P) ans++;
		cnt = 0;
	}
	cout << ans;
	return 0;
}