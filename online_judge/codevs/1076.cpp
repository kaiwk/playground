/*************************************************************************
 > File Name: 1076.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月15日 星期四 12时13分33秒
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
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

