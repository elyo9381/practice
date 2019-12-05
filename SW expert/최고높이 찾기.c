#include <stdio.h>

// 배열,dumpCount를 입력받아서 최대와 최소 길이를 찾고 그것의 차를 구하는 함수
int dump(int data[10],int dumpCount){
    int max = 0;
    int min = 0;

    int maxIndex=0, minIndex=0;

    //카운트가 내려갈때마다 초기화 
    while(dumpCount != 0)
    {
        max = data[0];
        min = data[0];
        maxIndex= 0;
        minIndex = 0;
   
  
    // 첫 인덱스는 지정되어있으므로 배열의 1번부터 시작하여 최고와 최소를 찾는다.
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

    // 찾은 최고.소와 의 인덱스를 줄이고 늘린다. 각각 
    data[maxIndex]  = data[maxIndex] -1;
    data[minIndex]  = data[minIndex] +1;
    dumpCount  = dumpCount -1;

     printf("%d",max);
     printf("%d",min);
        
    }




    // 내상각에 필요없다.
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