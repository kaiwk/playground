/*************************************************************************
 > File Name: 1466.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月24日 星期六 15时52分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int y;
	scanf("%d", &y);
	if(y%400 == 0|| y%4 == 0 && y%100 != 0) printf("366\n");
	else printf("365\n");

	return 0;
}
