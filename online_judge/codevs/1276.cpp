/*************************************************************************
 > File Name: 1276.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月19日 星期一 19时29分11秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	char a[3][3] = {
		'*', 'x', '*',
		' ', 'x', 'x',
		'*', ' ', '*',
	};
	int k;
	scanf("%d", &k);
	for(int i = 0; i < 3; ++i){
		for(int n = k; n > 0;--n){
			for(int j = 0; j < 3; ++j){
				for(int n = k; n > 0;--n) printf("%c", a[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}

