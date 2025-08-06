#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>


int stack[10] = {0,};
int top =-1;
int visited[8] ={0,};
int arr[8][8]= {0,};


void dfs(int v){
    printf("<push>%d\n",v);
    visited[v] =1;


    for(int i=1; i<=7; i++){
        if(visited[i] == 0 && arr[v][i] ==1 ){
            dfs(i);
        }
    }
    
}

using namespace std;
int main()
{
    int a,b;
    for(int i =0; i<7; i++)
    {
        scanf("%d %d", &a, &b);
        arr[a][b] =1;
        arr[b][a] =1;;

    }

    dfs(1);



    return 0;
}