#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>


int stack[100] = {0,};
int top =-1;

void push(int item)
{
    if(top>= 99) return;
    else stack[++top] = item;
}

int pop()
{
    if(top == -1)
    {
        printf("stakc is empty! \n");
        return 0;
    }
    else return stack[top--];
}

using namespace std;
int main()
{
    int item;

    push(1);
    push(2);
    push(3);

    item = pop();
    printf("pop item => %d\n",item);
    item = pop();
    printf("pop item => %d\n",item);
    item = pop();
    printf("pop item => %d\n",item);

    pop();



    return 0;
}