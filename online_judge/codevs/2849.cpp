/*************************************************************************
 > File Name: 2849.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月19日 星期一 18时41分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 2; i < n; ++i){
		if(n%i == 0){
			printf("composite\n");
			return 0;
		}
	}
	printf("prime\n");

	return 0;
}

