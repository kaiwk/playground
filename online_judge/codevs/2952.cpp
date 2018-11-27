/*************************************************************************
 > File Name: 2952.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月17日 星期六 21时56分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

long long a, q, sum;


int main(){

	scanf("%lld %lld", &a, &q);
	sum = pow(2, a);
	printf("%lld ", sum%q);
	sum = 1;
	for(int i = 0; i < a; ++i){
		sum = sum*2%q;
	}
	printf("%lld\n", sum);

	return 0;
}

