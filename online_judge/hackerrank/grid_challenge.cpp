#include<cstdio>
#include<algorithm>

using namespace std;

int t;
int N;
char g[100][100];

int main(){

    freopen("input", "r", stdin);
    scanf("%d", &t);
    for(int i = 0; i < t; ++i){

        scanf("%d", &N);
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < N; ++k){
                scanf(" %c", &g[j][k]);
            }
        }

        for(int j = 0; j < N; ++j){
            sort(g[j], g[j]+N);
        }

        int ok = 1;
        for(int k = 0; k < N; ++k){
            for(int j = 0; j < N-1; ++j){
                if(g[j][k] > g[j+1][k]){
                    ok = 0;
                    break;
                }
            }
        }

        if(ok){ printf("YES\n"); }
        else { printf("NO\n"); }
    }

    return 0;
}
