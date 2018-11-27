/*************************************************************************
 > File Name: 1017.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月16日 星期五 10时17分43秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n = 0, k = 0;
char a[50] = {'\0'};

//dp[i][j] means 前i位中进行j次划分所得到的最大乘积
long long dp[50][50] = {{0, 0}};

long long str2num(int x, int y){
	long long num = 0;
	for (int i = x; i <= y; ++i) {
		num = num*10 + a[i] - '0';
	}
	return num;
}

int main(){

	/* freopen("input.txt", "r", stdin); */
	scanf("%d %d", &n, &k);
	scanf("%s", a);

	for (int i = 0; i < n; ++i) {
		dp[i][0] = str2num(0, i);
	}

	for(int i = 0; i < n; ++i){
		for(int j = 1; j <= k; ++j){
			for (int s = 0; s < i; ++s) {
				dp[i][j] = max(dp[i][j], dp[s][j-1] * str2num(s+1, i));
			}
		}
	}

	printf("%lld\n", dp[n-1][k]);

	return 0;
}

