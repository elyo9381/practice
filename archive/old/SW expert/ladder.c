#include <assert.h>
#include <stdio.h>

int search(int Map[102][102],intstart){
int y =100,x =start;
while(y !=1){
if(Map[y][x -1]==1)// 좌측사다리가있으면
{while(Map[y][x -1]!=0){
x--;
}
y--;
}elseif(Map[y][x +1]==1){
while(Map[y][x +1]!=0)// 우측사다리가있으면
{x++;}y--;}else{y--;}}
return x;}
int testCase,t;
int i,j;
int main(){
int Map[102][102];
int num_of_testcase;
int target;
scanf("%d",&testCase);
for(t =0;t <testCase;t++){
scanf("%d",&num_of_testcase);// 사다리초기화
for(i =0;i <102;i++)
for(j =0;j <102;j++)Map[i][j]=0;

for(i =1;i <101;i++)
for(j =1;j <101;j++)
scanf("%d",&Map[i][j]);//도착지점찾기

for(i =0;i <102;i++){
if(Map[100][i]==2){
target =i;break;
}
}
printf("%d\n",search(Map,target)-1);
}return 0;}

