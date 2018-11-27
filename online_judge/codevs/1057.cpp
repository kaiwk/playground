/*************************************************************************
 > File Name: 1057.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月14日 星期三 20时49分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int budget, give = 0, mum = 0, hold = 0;
	freopen("input.txt", "r", stdin);
	for(int i = 1; i <= 12; ++i, give = 0){
		scanf("%d", &budget);
		hold = hold + 300 - budget;

		if(hold < 0){
			printf("%d\n", -i);
			return 0;
		}

		give += hold/100 * 100;
		mum += give;
		hold -= give;
	}
	hold += mum * 1.2;
	printf("%d\n", hold);

	return 0;
}

