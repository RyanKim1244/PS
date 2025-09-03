#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[15][15], A1[15][15], A2[15][15], B[15][15];

int main(void)
{
	int i, j;

	int ans = 21e8, cnt = 0;
	cin >> N;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			cin >> A[i][j];
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			cin >> B[i][j];
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			cnt += abs(A[i][j] - B[i][j]);
		}
	}

	ans = min(ans, cnt), cnt = 0;

	int x = N, y = 1;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			cnt += abs(A[x][y] - B[i][j]);
			A1[i][j] = A[x][y];
			x--, y--;
		}
		x = N, y = i + 1;
	}

	ans = min(ans, cnt), cnt = 0;

	x = N, y = N;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			cnt += abs(A[x][y] - B[i][j]);
			A2[i][j] = A[x][y];
			x++;
		}
		x = N - i, y = N - i;
	}

	ans = min(ans, cnt), cnt = 0;

	int cnt1 = 0, cnt2 = 0, cnt3 = 0;

	x = 1, y = 1;
	for (i = 1; i <= N; i++) {
		x = i, y = 1;
		for (j = i; j >= 1; j--) {
			cnt1 += abs(A[i][j] - B[x][y]);
			cnt2 += abs(A1[i][j] - B[x][y]);
			cnt3 += abs(A2[i][j] - B[x][y]);
			y++;
		}
	}

	ans = min(ans, min(cnt1, min(cnt2, cnt3)));

	cout << ans;
	return 0;
}