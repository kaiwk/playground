/*************************************************************************
 > File Name: 2559.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月24日 星期六 17时11分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	int h = x/20 + y;
	if(h >= 8) printf("YES\n");
	else printf("No\n");

	return 0;
}

