/*************************************************************************
 > File Name: 1449.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月24日 星期六 14时51分52秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int func(int product, int n){
	if(n == 0 || n == 1) return product;
	else return func(n*product, n-1);
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", func(1, n));

	return 0;
}

