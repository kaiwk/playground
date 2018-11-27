/*************************************************************************
 > File Name: 1045.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月19日 星期一 22时08分59秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int a[10000];

bool is_palindromic(int n){
	int len;
	for(int i = 0; n != 0; ++i){
		a[i] = n%10;
		n /= 10;
		len = i;
	}
	for(int i = 0, j = len; i <= j; ++i, --j){
		if(a[i] != a[j])
			return false;
	}
	return true;
}


int main(){
	int n;
	char m[1000];
	scanf("%d", &n);
	scanf("%s", m);
	for(int i = 0; i < strlen(m); ++i){
	
	}

	return 0;
}

