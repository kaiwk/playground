/*************************************************************************
 > File Name: 1385.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月21日 星期三 12时36分38秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<climits>
using namespace std;

int a[1000000];
int s = INT_MAX, e = INT_MIN, l, r;
int cnt_no = 0, no = 0;
int cnt_has = 0, has = 0;

int main(){
	int n;
//	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &l, &r);
		s = min(s, l);
		e = max(e, r);
		for(int i = l; i < r; ++i) ++a[i];
	}

	for(int i = s; i <= e; ++i){

		if(a[i] == 0) ++cnt_no;
		else{
			no = max(cnt_no, no);
			cnt_no = 0;
		}

		if(a[i] >= 1) ++cnt_has;
		else{
			has = max(cnt_has, has);
			cnt_has = 0;
		}
	}
	printf("%d %d\n", has, no);

	return 0;
}

