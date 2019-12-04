#include <assert.h>
#include <stdio.h>

int sel_min(int ary[][5])
{   int min=0;
    int minX=0,minY=0;
    min =ary[0][0];
    for(int i =0;i <5;i++)
        for(int j=0;j <5;j++)
            if(min >ary[i][j]){
                min =ary[i][j];
                minX =i;
                minY =j;
            }
            ary[minX][minY]=26;
            return min;}

int main(){
    int ary[][5]={{9,20,2,18,11},{19,1,25,3,21},{8,24,10,17,7},{15,4,16,5,6},{12,13,22,23,14}};
    int sorted_ary[5][5]={0};
    int cur_min =-1;
    int X,Y;
    int newX=0,newY=0;
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    int dir_stat =0;
    for(int i=0;i <25;i++){
        cur_min =sel_min(ary);
        // printf("%d\n",cur_min);
        X =newX;
        Y =newY;
        sorted_ary[Y][X]=cur_min;
        newX = X +dx[dir_stat];
        newY = Y +dy[dir_stat];
          printf("< y> < x> %d %d\n ",Y,X);
        printf("<new y> <new x> %d %d\n ",newY,newX);
        if(sorted_ary[newY][newX]!=0||newY >4||newX >4){
             // printf("<new y> <new x> %d %d\n ",newY,newX);
            dir_stat =(dir_stat +1)%4;
            newX =X +dx[dir_stat];
            newY =Y +dy[dir_stat];
        }
    }
    for(int i =0;i <5;i++){
        for(int j=0;j <5;j++)
            printf("%3d",sorted_ary[i][j]);printf("\n");
    }
}