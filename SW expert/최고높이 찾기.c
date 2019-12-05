#include <stdio.h>

int dump(int data[10],int dumpCount){
    int max = 0;
    int min = 0;

    int maxIndex=0, minIndex=0;

    
    while(dumpCount != 0)
    {
        max = data[0];
        min = data[0];
        maxIndex= 0;
        minIndex = 0;
   
  
        
    for (int i =1; i<10 ; i++){
    if(max <data[i])
    {
        max  = data[i];
        maxIndex = i;
    }

    if(min > data[i])
    {
        min = data[i];
        minIndex  =  i;
    }
    }

    data[maxIndex]  = data[maxIndex] -1;
    data[minIndex]  = data[minIndex] +1;
    dumpCount  = dumpCount -1;

     printf("%d",max);
     printf("%d",min);
        
    }





    // for(int i=1; i<10; i++)
    // {
    //     if(max <data[i])
    //     {
    //         max  =data[i];
    //     }

    //     if(min <data[i])
    //     {
    //         min  = data[i];
    //     }
    // }
    return max-min;
}

int main(){
    int dumpCount;
    int data[10];

    for(int i =0; i<1; i++){
    scanf("%d",&dumpCount);


        for(int j=0; j<10; j++){
            scanf("%d",&data[j]);
        }
       
   // for(int q=0; q<10; q++){
   //      printf("%d",data[q]);
   //  }

    printf("#1 %d %d",i+1,dump(data,dumpCount));

    }
}