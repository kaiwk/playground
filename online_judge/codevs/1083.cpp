/*************************************************************************
 > File Name: 1083.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月22日 星期四 12时28分40秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main(){

	int n, x = 1;
	scanf("%d", &n);
	for(; n - x > 0;){
		n -= x;
		++x;
	}
	int m, d;
	if(x%2 == 0){
		m = n;
		d = x;
	}
	else{
		m = x-n+1;
		d = n;
	}
	printf("%d/%d\n", m, d);

	return 0;
}
