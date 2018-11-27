/*************************************************************************
 > File Name: 2283.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月24日 星期六 17时16分42秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char a[10000];
	bool is_killing;
	int cnt = 0;
	scanf("%s", a);
	for(int i = 0; i < n; ++i){
		if(a[i] == 'K'){
		   	++cnt;
		}
		if(a[i] == 'D') {
			cnt = 0;
		}
	}

	return 0;
}

