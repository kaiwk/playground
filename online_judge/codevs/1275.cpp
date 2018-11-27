/*************************************************************************
 > File Name: 1275.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月19日 星期一 18时54分42秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a[4];
	bool is_rising = false, is_diving = false, is_constant = false, no_fish = false;
	for(int i = 0; i < 4; ++i){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i < 4; ++i){
		if(a[i-1] < a[i]){
			is_rising = true;
		}
		else if(a[i-1] > a[i]){
			is_diving = true;
		}
		else if(a[i-1] == a[i]){
			is_constant = true;
		}

		if(is_rising && is_diving || is_constant && is_rising || is_constant && is_diving){
			printf("No Fish\n");
			return 0;
		}
	}
	if(is_rising) printf("Fish Rising\n");
	else if(is_diving) printf("Fish Diving\n");
	else if(is_constant) printf("Fish At Constant Depth\n");

	return 0;
}

