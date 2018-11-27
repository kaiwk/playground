#include <cstdio>
#include <cstring>

int hh = 0;
char input[20];

int main(){
    scanf("%s", input);


    for(int i = 0; input[i] != ':'; ++i){
        hh = hh*10 + input[i] - '0';
    }


    if(strcmp(&input[8], "PM") == 0){
        if(hh == 12){

            input[8] = '\0';
            printf("%s\n", input);
            return 0;

        }else hh += 12;
    }else{
        if(hh == 12){
            input[8] = '\0';
            printf("00%s\n", &input[2]);
            return 0;
        }
    }

    input[8] = '\0';

    if(hh < 10){
        printf("0%d%s\n", hh, &input[2]);
    }else printf("%d%s\n", hh, &input[2]);


    return 0;
}

