#include <bits/stdc++.h>
#define INF 21e8

using namespace std;
typedef long long LL;
typedef pair<int, int> pi;

int N, K;
int x[55], y[55];

int dist(int i, int j, int k) {
	int ans = 0;
	for (int l = 1; l <= N; l++) {
		ans = max(ans, min({ abs(x[i] - x[l]) + abs(y[i] - y[l]), abs(x[j] - x[l]) + abs(y[j] - y[l]), abs(x[k] - x[l]) + abs(y[k] - y[l]) }));
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int i, j, k;
	cin >> N >> K;

	for (i = 1; i <= N; i++) {
		cin >> x[i] >> y[i];
	}

	int ans = 21e8;

	if (K == 1) {
		for (i = 1; i <= N; i++) ans = min(ans, dist(i, i, i));
	}
	else if (K == 2) {
		for (i = 1; i <= N; i++) {
			for (j = i; j <= N; j++) {
				ans = min(ans, dist(i, j, j));
			}
		}
	}
	else {
		for (i = 1; i <= N; i++) {
			for (j = i; j <= N; j++) {
				for (k = j; k <= N; k++) {
					ans = min(ans, dist(i, j, k));
				}
			}
		}
	}
	cout << ans;
	return 0;
}