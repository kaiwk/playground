/*************************************************************************
 > File Name: 1313.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月19日 星期一 19时46分31秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	long a;
	scanf("%ld", &a);
	for(int i = 2; i < a; ++i){
		if(a%i == 0){
			printf("%ld\n", a/i);
			break;
		}
	}

	return 0;
}

