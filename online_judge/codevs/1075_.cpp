/*************************************************************************
 > File Name: 1075_.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月14日 星期三 21时42分31秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int N, temp, cnt = 0;
	int a[1001] = {0};
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &temp);
		if(a[temp] == 0){
			++cnt;
			++a[temp];
		}
	}
	printf("%d\n", cnt);
	for(int i = 0; i < 1001; ++i){
		if(a[i] != 0)
			printf("%d ", i);
	}
	printf("\n");

	return 0;
}
