/*************************************************************************
 > File Name: 1011.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月14日 星期三 22时27分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

long cnt = 0;

void dfs(int n){
	for(int i = 1; i <= n/2; ++i){
		++cnt;
		dfs(i);
	}
}

int main(){

	int N;

	scanf("%d", &N);
	dfs(N);
	printf("%ld\n", cnt+1);

	return 0;
}

