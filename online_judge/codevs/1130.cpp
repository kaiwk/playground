/*************************************************************************
 > File Name: 1130.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月15日 星期四 22时30分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


int main(){
	long long N;
	bool is_begin;
	scanf("%lld", &N);

	if(N < 0){
		N = -N;
		printf("-");
	}
	is_begin = true;
	while(N != 0){
		if(N%10 == 0 && is_begin) {
			N /= 10;
			continue;
		}
		printf("%lld", N%10);
		is_begin = false;
		N /= 10;
	}
	printf("\n");

	return 0;
}

