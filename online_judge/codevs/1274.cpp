/*************************************************************************
 > File Name: 1274.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月15日 星期四 22时01分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int fine(int diff){
		if(diff >= 1 && diff <= 20) return 100;
		if(diff >= 21 && diff <= 30) return 270;
		if(diff >= 31) return 500;
}

int main(){

	int set, record;
	printf("Enter the speed limit: ");
	scanf("%d", &set);
	printf("Enter the recorded speed of the car: ");
	scanf("%d", &record);
	if(record - set <= 0) printf("Congratulations, you are within the speed limit\n");
	else printf("You are speeding and your fine is $ %d\n", fine(record-set));

	return 0;
}
