/*************************************************************************
 > File Name: 1508.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月24日 星期六 16时59分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	char a[6];
	char b[6];
	int m = 1;
	int n = 1;
	scanf("%s", a);
	scanf("%s", b);
	for(int i = 0; i < strlen(a); ++i){
		m *= (a[i] - 64);
	}
	for(int i = 0; i < strlen(b); ++i){
		n *= (b[i] - 64);
	}
	if(m%47 == n%47) printf("GO\n");
	else printf("STAY\n");
	
	return 0;
}

