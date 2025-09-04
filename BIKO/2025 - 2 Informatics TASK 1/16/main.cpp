#include <cstdio>

int main(void)
{
	int a, b, c, students;
	scanf("%d %d %d %d", &a, &b, &c, &students);
	int students1, students2, students3, students4;
	students1 = students;
	for (int i = 0; i <= students / c; i++) {
		students2 = students1 - c * i;
		if (students2 < 0) break;
		for (int j = 0; j <= students / b; j++) {
			students3 = students2 - b * j;
			if (students3 < 0) break;
			for (int k = 0; k <= students / a; k++) {
				if (students3 % a == 0) {
					printf("1");
					return 0;
				}
			}
		}
	}
	printf("0");
	return 0;
}