/*************************************************************************
 > File Name: 2246.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月16日 星期五 10时06分35秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main(){

	int n, m;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i){
		scanf("%d", &m);
		for(int j = 0; j < 10; ++j){
			if((m+j)%10 == 0){
				printf("%d ", j);
				break;
			}
		}
	}
	printf("\n");

	return 0;
	
}

