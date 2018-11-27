/*************************************************************************
 > File Name: 1336.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月19日 星期一 21时00分13秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int a[40][50000];
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i][0]);
		for(int j = 1; j <= a[i][0]; ++j){
			scanf("%d", &a[i][j]);
		}
		sort(a[i]+1, a[i]+a[i][0]+1);
	}
	int mid, t, key;
	for(int i = 0; i < n; ++i){
		key = (a[i][0]+1)/2;
		mid = a[i][key];
		t = 0;
		for(int j = 1; j <= a[i][0]; ++j){
			t += abs(a[i][j]-mid);
		}
		printf("%d %d\n", mid, t);
	}
	return 0;
}

