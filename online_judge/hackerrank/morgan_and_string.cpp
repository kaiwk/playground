#include <cstdio>
#include <stack>
#include <cstring>

int T;
char s[20][1000000] = {0};
char res[2000000] = {0};

void merge_s(char *res, const char *a, const char *b){

    int a_len = strlen(a)-1, b_len = strlen(b)-1;
    int a_i = 0, b_i = 0;
    int i = 0;

    for( ; a_i < a_len && b_i < b_len; ++i){
        if(a[a_i] < b[b_i]){ res[i] = a[a_i]; ++a_i; }
        else if(a[a_i] > b[b_i]){ res[i] = b[b_i]; ++b_i; }
        else{
            if(strcmp(a+a_i, b+b_i) >= 0) { res[i] = b[b_i]; ++b_i; }
            else { res[i] = a[a_i]; ++a_i; }
        }
    }

    if(a_i == a_len){ for( ; b_i < b_len; ++b_i, ++i){ res[i] = b[b_i]; } }
    else if(b_i == b_len){ for( ; a_i < a_len; ++a_i, ++i){ res[i] = a[a_i]; } }
}

int main(){

    scanf("%d", &T);
    for(int i = 0; i < 2*T; ++i){
        scanf("%s", s[i]);
    }

    for(int i = 0; i < 2*T; i += 2){

        s[i][strlen(s[i])] = s[i+1][strlen(s[i+1])] = 'z';

        merge_s(res, s[i], s[i+1]);
        printf("%s\n", res);
        res[strlen(res)-1] = '\0';
        memset(res, 0, 2000000 * sizeof(char));
    }

    return 0;
}
