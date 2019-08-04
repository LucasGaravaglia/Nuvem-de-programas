#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ever (;;)
#define ErroLat 17508
#define ErroLongi 23847

void lerarquivo(int* a, int* b){
    FILE *f;
    int temp;
    f = fopen("entrada.txt","r");
    if(f == NULL){
        printf("ERRO\n");
        return NULL;
        }
    fscanf(f,"%d",&temp);
    *a = temp;
    fscanf(f,"%d",&temp);
    *b = temp;
    fclose(f);
}

void DanceCoord(int *lat, int *longi){
    int n1=0;
    int n2=0;
    int temp;
    temp = *lat;
    while(temp != 0){
        temp /= 10;
        n1++;
    }
    temp = *longi;
    while(temp != 0){
        temp /= 10;
        n2++;
    }
    n1 -=7;
    n2 -=7;
    for(int i=0;i<n1;i++)
        (*lat) /= 10;
    for(int i=0;i<n2;i++)
        (*longi) /= 10;

    (*lat) += ErroLat;
    (*lat) *= -1;
    (*longi) += ErroLongi;
    (*longi) *= -1;
}

int main(){
    for ever {
        system("./script.sh");
        int lat, longi;
        lerarquivo(&lat, &longi);
        if(!(lat == -1 || longi == -1)){
            DanceCoord(&lat,&longi);
            printf("Latitude = %d\nLongitude = %d\n",lat,longi);
        }else{
            printf("Erro ao ler GPS.\n");
        }
        getchar();
    }

    return 0;
}