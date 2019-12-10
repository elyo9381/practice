#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>

#define QUEUE_SIZE 10001
#define MAX_VERTEX_COUNT 10001

#define TRUE 1
#define FALSE 0

#define IS_VISITED 1
#define NOT_VISITED 0

int queue[QUEUE_SIZE];
int front;
int rear;

int isEmpty()
int isFull()
void enQueue(int item)
int deQueue()
void createQueue()
int Qpeek()


int t;

int n;
int m;
int i,j;
int a,b;

int adjacent[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT];
int visited[MAX_VERTEX_COUNT];
int visitingVertex;

int main()
{
    scanf("%d", &t);

    while(t--)
    {
        for(i =1; i<=n;i++)
        {
            visited[i] = NOT_VISITED;
            for(j =1 ; j<=n; j++){
                adjacent[i][j] = FALSE;
            }
        }


        scanf("%d %d", &n, &m);


        for(i = 0; i <m ; i++){
            scanf("%d %d", &a, &b){
                adjacent[a][b] = TRUE;
                adjacent[b][a] = TRUE;
            }
        }


        createQueue();

        enQueue(1);
        visited[1] = IS_VISTED;

        while(isEmpty() == FALSE){
            visitingVertex = deQueue();
            printf("%d ", visitingVertex);

            for(i = 1; i<=n; i++){
                if(adjacent[visitingvertex][i] == TRUE && visited[i] == FALSE){
                    enQueue(i);
                    visited[i] = IS_VISTED;
                }
            }
        }

        printf("\n");
    }

    return 0;
}

