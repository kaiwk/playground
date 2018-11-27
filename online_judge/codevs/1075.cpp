/*************************************************************************
 > File Name: 1075.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月14日 星期三 21时20分22秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int N;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	int a[N];
	for(int i = 0; i < N; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a+N);
	for(int i = 1; i < N; ++i){
		if(a[i-1] == a[i]){
			for(int j = i; j < N; ++j){
				a[j-1] = a[j];
			}
			--i;
			--N;
		}
	}
	printf("%d\n", N);
	printf("%d", a[0]);
	for(int i = 1; i < N; ++i){
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}

