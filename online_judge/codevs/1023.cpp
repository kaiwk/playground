/*************************************************************************
 > File Name: 1023.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月14日 星期三 20时36分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	double sn = 0, sum = 0, c, g;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%lf %lf", &c, &g);
		sn += c*g;
		sum += c;
	}
	printf("%.2lf\n", sn/sum);
	return 0;
}

