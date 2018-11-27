/*************************************************************************
 > File Name: 1426.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月24日 星期六 15时55分59秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

bool is_prime(long n){
	if(n == 0 || n == 1) return false;
	if(n == 2) return true;
	for(int i = 2; i*i < n+1; ++i){
		if(n%i == 0) return false;
	}
	return true;
}

int main(){
	long l, r;
	scanf("%ld %ld", &l, &r);
	if(l > r) swap(l, r);

	long sum = 0;
	for(long i = l+1; i < r; ++i){
		if(is_prime(i)) sum += i;
	}
	printf("%ld\n", sum);
	
	return 0;
}

