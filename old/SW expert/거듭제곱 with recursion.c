#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>


int recur(int num1, int num2){

    if(num2 == 1){
        return num1;
    }
    else{
        return num1*recur(num1,num2-1);
    }
}



int main()
{
    int i, num1, num2, cntnum;
    int T = 10;

    while(T>0)
    {
        scanf("%d",&cntnum);
        scanf("%d %d",&num1,&num2);


        printf("#%d %d\n",cntnum,recur(num1,num2));
        T--;
    }


    return 0;
}

// input
// 1
// 9 8
// 2
// 2 8
// 3
// 6 5
// 4
// 10 7
// 5
// 6 7
// 6
// 7 2
// 7
// 9 8
// 8
// 3 2
// 9
// 4 8
// 10
// 8 6
