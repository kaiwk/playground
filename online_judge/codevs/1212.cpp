/*************************************************************************
 > File Name:       1212.cpp
 > Author:        Kermit
 > Email:         kermitwang95@gmail.com
 > homepage:      http://kermit95.github.io
 > Created Time:  六  4/ 2 22:05:56 2016
 ************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;

long gcd(long a, long b){
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

long a, b;

int main(){

	scanf("%ld %ld", &a, &b);

	printf("%ld\n", gcd(a, b));

	return 0;
}
