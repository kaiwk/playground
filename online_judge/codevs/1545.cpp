/*************************************************************************
 > File Name: 1545.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月24日 星期六 16时52分22秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){

	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	for(int i = 0; i < n; ++i){
		printf("%d\n", a[i]);
	}

	return 0;
}

