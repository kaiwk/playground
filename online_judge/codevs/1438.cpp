/*************************************************************************
 > File Name: 1438.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月22日 星期四 13时42分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

void prt_(int n){
	printf("/");
	for(int i = 0; i < n; ++i) printf("__");
	printf("\\");
}

int main(){
	int n;
	scanf("%d", &n);
	int k = n-2;
	for(int i = 0; i < n; ++i, --k){
		for(int j = k; j >=0; --j){
			printf(" ");
		}
		prt_(i);
		for(int j = k; j >=0; --j){
			printf(" ");
		}
		printf("\n");
	}

	return 0;
}

