/*************************************************************************
 > File Name: 1007.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月14日 星期三 18时37分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int k, i;
	double sn = 0;
	scanf("%d", &k);
	if(k >= 1 && k <= 15){
		for(i = 1; sn <= k; ++i){
			sn += 1.0/i;
		}
		printf("%d\n", i-1);
	}
	else{
		return 0;
	}

	return 0;
}


