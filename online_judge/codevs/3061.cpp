/*************************************************************************
 > File Name: 3061.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月24日 星期六 16时37分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	long a, b, c;
	char x;
	scanf("%ld %ld", &a, &b);
	scanf(" %c", &x);
	if(x == '+') c = a+b;
	else if(x == '-') c = a-b;
	else if(x == '*') c = a*b;
	else if(x == '/') c = a/b;
	printf("%ld\n", c);

	return 0;
}

