/*************************************************************************
 > File Name: 1439.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月24日 星期六 15时40分42秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

bool is_prime(int n){
	if(n == 0 || n == 1) return false;
	if(n == 2) return true;
	for(int i = 2; i < n; ++i){
		if(n%i == 0) return false; 
	}
	return true;
}

int main(){
	int l, r, cnt = 0;
	scanf("%d %d", &l, &r);
	for(int i = l; i <= r; ++i){
		if(is_prime(i)) ++cnt;
	}
	printf("%d\n", cnt);

	return 0;
}

