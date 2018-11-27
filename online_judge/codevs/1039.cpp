/*************************************************************************
 > File Name:       1039.cpp
 > Author:        Kermit
 > Email:         kermitwang95@gmail.com
 > homepage:      http://kermit95.github.io
 > Created Time:  一  4/ 4 15:39:45 2016
 ************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;

//f[n][k] = f[n-1][k-1] + f[n-k][k]
int n = 0, k = 0;
int f[201][7] = {{0, 0}};

int main(){

	scanf("%d %d", &n, &k);

	for (int i = 0; i <= n; ++i) {
		f[i][1] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k && j <= i; ++j) {
			f[i][j] = f[i-1][j-1] + f[i-j][j];
		}
	}

	printf("%d\n", f[n][k]);

	return 0;
}
