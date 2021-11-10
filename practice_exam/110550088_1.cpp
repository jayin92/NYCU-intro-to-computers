#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	int m, n, p;
	int a[35][35];
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };
	dx[0] = 0; dx[1] = 1; dx[2] = 0; dx[3] = -1;
	dy[0] = 1; dy[1] = 0; dy[2] = -1; dy[3] = 0;
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 35; j++) {
			a[i][j] = 0;
		}
	}
	

	
	printf("Please input M: ");
	scanf("%d", &m);
	printf("Please input N: ");
	scanf("%d", &n);
	printf("Please input P: ");
	scanf("%d", &p);

	for (int i = 0; i <= m; i++) {
		a[i][0] = a[i][n + 1] = -1;
	}
	for (int j = 0; j <= n; j++) {
		a[0][j] = a[m + 1][j] = -1;
	}

	int x = 1;
	int y = 1;
	int dir = 0;
	for (int i = 1; i <= m * n; i++) {
		// printf("%d, %d\n", x, y);
		a[x][y] = i;

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (a[nx][ny] != 0) {
			dir++;
			dir %= 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		} 
		x = nx;
		y = ny;
	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	if (p > m * n) {
		printf("P is out of range\n");
		system("PAUSE");
		return 0;
	}

	for (int i = 1; i < 35; i++) {
		for (int j = 1; j < 35; j++) {
			if (a[i][j] == p) {
				printf("The location of %d is:(%d,%d)\n", p, i, j);
				system("PAUSE");
				return 0;
			}
		}
	}




	return 0;
}