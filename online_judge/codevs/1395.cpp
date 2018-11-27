/*************************************************************************
 > File Name: 1395.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月24日 星期六 15时46分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int n, cnt = 0;
	scanf("%d", &n);
	if(n == 0){
		printf("1\n");
		return 0;
	}
	for(; n != 0; ){
		n /= 10;
		++cnt;
	}
	printf("%d\n", cnt);

	return 0;
}

