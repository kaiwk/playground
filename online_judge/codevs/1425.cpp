/*************************************************************************
 > File Name: 1425.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月16日 星期五 09时50分19秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

//最长公共字串暴力
struct Max_sub{
	char res[1000];
	int s;
	int e;
	int len;
}max_sub;


void find(char a[], char b[]){
	int m, n, len = 0;
	max_sub.len = -1;
	//b is shorter
	for(int i = 0; i < strlen(a); ++i){
		for(int j = 0; j < strlen(b); ++j){
			m = i;
			n = j;
			while(a[m] == b[n]){
				++m;
				++n;
				++len;
			}
			if(len > max_sub.len){
				max_sub.s = j;
				max_sub.e = n-1;
				max_sub.len = len;
			}
			len = 0;
		}
	}
	for(int i = max_sub.s, j = 0; i <= max_sub.e; ++i, ++j){
		max_sub.res[j] = b[i]; 
	}
	for(int i = max_sub.e+1; max_sub.res[i] != '\0'; ++i){
		max_sub.res[i] = '\0';
	}
}

int main(){
	int N;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	char a[21][1000];
	for(int i = 0; i < N; ++i){
		scanf("%s", a[i]);
	}

	for(int i = 1; i < N; ++i){
		if(i == 1) {
			if(strlen(a[i-1]) >= strlen(a[i])){
				find(a[i-1], a[i]);
			}
			else{
				find(a[i], a[i-1]);
			}
		}
		find(a[i], max_sub.res);
	}
	printf("%s\n", max_sub.res);
	return 0;
}
