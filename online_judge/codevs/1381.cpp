/*************************************************************************
 > File Name: 1381.cpp
 > Author: Kermit
 > Email: kermitwang95@gmail.com
 > Created Time: 2015年10月20日 星期二 20时21分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef struct X{
	char name[14];
	int give;
	int ac;
	int f;
}P;

int main(){
	int n;
	P p[10];

	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", p[i].name);
		p[i].give = 0;
		p[i].ac = 0;
		p[i].f = 0;
	}

	int give;
	for(int i = 0; i < n; ++i){
		char name[14];
		scanf("%s", name);
		for(int m = 0; m < n; ++m){
			if(strcmp(name, p[m].name) == 0){
				scanf("%d %d", &p[m].give, &p[m].f);

				if(p[m].f == 0){
					break;
				}

				give = p[m].give/p[m].f;
				p[m].ac += p[m].give - give*p[m].f;
				for(int j = 0; j < p[m].f; ++j){
					char fri[14];
					scanf("%s", fri);
					for(int k = 0; k < n; ++k){
						if(strcmp(fri, p[k].name) == 0){
							p[k].ac += give;
						}
					}
				}
			}
		}
	}

	for(int i = 0; i < n; ++i){
		printf("%s %d\n", p[i].name, p[i].ac-p[i].give);
	}

	return 0;
}

