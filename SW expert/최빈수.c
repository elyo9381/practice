#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>


using namespace std;
int main(){
    int T,i,j,testnum;
    int Sarr[1000];
    int num;
    int count[100];


    scanf("%d",&T);

    for(int i=0; i<T; i++)
    {   
        scanf("%d",&num);

        int max = 0, maxIndex = 0;
        for(int i = 0;i<100;i++){
            count[i]= 0;
         }

        for(int j = 0; j < 1000 ;j++){
            scanf("%d ",&Sarr[j]);

            count[Sarr[j]]++;
        }

        // printf("%d\n",Sarr[i]);
        for(int i = 0; i<100; i++){
            if(max < count[i]){
                max=count[i];
                maxIndex = i;
            }
            else if(i > maxIndex && count[i] == max){
                maxIndex = i;
            }





        }

        printf("#%d %d\n",num,maxIndex);


    }

    return 0;
}