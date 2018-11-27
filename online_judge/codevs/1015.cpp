/*************************************************************************
 > File Name: 1015.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月14日 星期三 18时51分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool is_int(char a){
	return a >= '0' && a <= '9';
}

bool is_alpha(char a){
	return a >= 'a' && a <= 'z';
}

int main(){
	char e[1000];
	double n = 0;                 //记录所有数字
	double m = 0;                 //记录系数
	double k = 0;                 //记录常数
	char x;                       //记录未知数
	bool is_minus, pass_equal = false;

	freopen("input.txt", "r", stdin);
	scanf("%s", e);

	for(int i = 0; i < strlen(e); ++i, n=0){

		if(e[i] == '='){
			pass_equal = true;
		}

		is_minus = false;
		if(i > 0 && e[i-1] == '-'){
			is_minus = true;
		}

		if(is_int(e[i])){

			int j;

			for(j = i; is_int(e[j]); ++j){
				n = n*10 + (e[j]-'0');
				++i;
			}
			--i;

			if(is_minus){
				n = -n;
			}

			if(is_alpha(e[j])){
				x = e[j];
				if(!pass_equal) m += n;
				else m -= n;
			}
			else{
				if(!pass_equal) k += n;
				else k -= n;
			}
		}
	}

	//结果取负，因为运算过程中都把等号左边视为正
	printf("%c=%.3lf\n", x, k == 0?0:-k/m);

	return 0;
}

