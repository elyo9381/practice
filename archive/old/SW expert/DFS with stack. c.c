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

// 스택에 push하고 v노드에 방문했는지를 알려줌
void push(int v)
{
    printf("<push>%d\n",v);
    stack[++top] =v;
    visited[v] =1;
    return ;

}

//top --
void pop(){
    top--;
    return ;
}

void dfs(int v){
    push(v);

    // top 하나 줄이면서 다시 탐색하는 방법으로 노드를 재탐색 하는 방법 
    while(top >=0){
        for(int i =1; i<=7;i++){
            // 방문여부와 arr[stack[top][i]]는 배열에 방문할 노드가 표시되어 있는데
            // top이 계속 바뀌면서 노드를 재탐색한다. 이러한 방법으로 하게 되면 매우 비효율적일거같다.
            // 배열을 계속 재탐색한다.
            if(visited[i] == 0 && arr[stack[top]][i]==1)
            {
                // printf("<if i >%d\n",i);

                push(i);
                i =1;
            }
            printf("<top>%d <stack %d> %d \n",top,i,stack[i]);
        }


        pop();
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