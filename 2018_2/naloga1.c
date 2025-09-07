
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    int n;
    scanf("%d", &n);


    char buff[n+1];
    scanf("%s", buff);

    int i= 0;
    int skupno = 0;
    int curr = 0;
    int count = 0;

    while (i < n) {
    
        if (buff[i] == '+') count++;
        if (count == 0) {
            i++;
            continue;
        }

        if (count >= 1 && buff[i] == '-') {
            curr++;
        } else if (buff[i] == '+') {
            
            skupno += (curr+1);

            curr = 0;
        }

        i++;
    }


    printf("%d\n", (skupno-1)/(count-1));

        
}



































































/*

    int n;
    scanf("%d",&n);

    char* znaki = malloc (2000*sizeof(char));
    int* distances = malloc (1000*sizeof(int));

    scanf("%s",znaki);

    int distance = 0;
    int checked = 0;

    int sum = 0;
    int distancesCount = 0;

    for (int i=0; znaki[i]!='\0'; i++){
        distance=0;
        if (znaki[i]=='+'){
            i++;
            distance++;
            while(znaki[i]=='-'){
                distance++;
                i++;
            }

            // printf("%d",distance);
        }
        if (znaki[i]=='+' && znaki[i-1]!='+'){
            i--;
        }

        if (distance!=0){
            sum+=distance;
            distancesCount+=1;
        }
    }

    printf("%d",(sum/distancesCount));


*/