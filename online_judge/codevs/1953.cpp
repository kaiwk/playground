/*************************************************************************
 > File Name: 1953.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月15日 星期四 22时23分11秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

bool is_prime(int n){
	if(n == 2) return true;
	for(int i = 2; i < n; ++i){
		if(n%i == 0) return false;
	}
	return true;
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 2; i <= N; ++i){
		if(is_prime(i)){
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}

