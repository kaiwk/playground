#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef struct Vertice_{
    int n;
    int vis;
    int dist;
    int adj[1001];
} Vertice;

Vertice v[1001];

int T;
int N, M;
int S;
queue<Vertice> q;


void bfs(){

    v[S].vis = 1;
    q.push(v[S]);

    while(!q.empty()){

        Vertice x = q.front();
        q.pop();

        for(int i = 1; i <= N; ++i){
            if(x.adj[i] && !v[i].vis){
                v[i].vis = 1;
                v[i].dist = x.dist + 1;
                q.push(v[i]);
            }
        }
    }
}



int main(){

    scanf("%d", &T);
    for(int t = 0; t < T; ++t){

        memset(v, 0, (N+1) * sizeof(Vertice));

        scanf("%d %d", &N, &M);
        for(int i = 1; i <= N; ++i){
            v[i].n = i;
            v[i].dist = -1;
        }

        for(int i = 1; i <= M; ++i){
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            v[n1].adj[n2] = 1;
            v[n2].adj[n1] = 1;
        }

        scanf("%d", &S);
        v[S].dist = 0;

        bfs();
        for(int i = 1; i <= N; ++i){
            if(v[i].dist != 0){
                if(v[i].dist == -1){
                    printf("-1 ");
                }else printf("%d ", v[i].dist * 6);
            }
        }
        printf("\n");
    }


    return 0;
}
