#include <cstdio>

struct students {
	int s, y;
}arr[1005];

int room[10][3];

int main(void)
{
	int n, k, ans = 0;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i].s, &arr[i].y);
	}
	for (int i = 1; i <= n; i++) {
		room[arr[i].y][arr[i].s]++;
	}
	for (int i = 1; i <= 6; i++) {
		ans += room[i][0] / k + (room[i][0] % k != 0?1:0);
		ans += room[i][1] / k + (room[i][1] % k != 0 ? 1 : 0);
	}
	printf("%d", ans);
	return 0;
}