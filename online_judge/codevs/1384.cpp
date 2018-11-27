/*************************************************************************
 > File Name: 1384.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月20日 星期二 22时26分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

bool is_leap(int y){
	if((y%4 == 0 && y%100 != 0) || y%400 == 0)
		return true;
	return false;
}

int main(){
	int a[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int res[7] = {0};
	int n;
	scanf("%d", &n);
	if(n == 0){
		for(int i = 0; i < 7; ++i){
			printf("%d ", res[i]);
		}
		printf("\n");
		return 0;
	}
	else{
		int days = 12;
		for(int i = 0; i < n; ++i){
			if(is_leap(i+1900)) a[1] = 29;
			else a[1] = 28;
			for(int j = 0; j < 12; ++j){
				++res[days%7];
				days += a[j];
			}
		}
	}

	printf("%d %d", res[5], res[6]);
	for(int i = 0; i < 5; ++i){
		printf(" %d", res[i]);
	}
	printf("\n");

	return 0;
}

