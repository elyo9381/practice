#include <stdio.h>
int arr_1[100] = { 0, 0, };
int arr_2[100] = { 0, 0, };
int flag = 0;
 
void DFS(int x)
{
    //printf("%d  ", x);
 
    if (arr_1[x] == 99 || arr_2[x] == 99)
    {
        if (arr_1[x] == 99)
        {
    //      printf("1    %d  ", arr_1[x]);
 
         
        }
        else
        {
        //printf("2    %d", arr_2[x]);
        }
     
        flag = 1;
        return;
    }
 
    if (flag==0)
    {
        if (arr_1[x] != 0)
        {
            flag = 0;
 
            DFS(arr_1[x]);
            arr_1[x] = 0;
        }
    }
    if (flag == 0)
    {
        if (arr_2[x] != 0)
        {
            flag = 0;
            DFS(arr_2[x]);
            arr_2[x] = 0;
        }
    }
 
}
 
 
 
 
 
 
 
 
int main()
{
    int a = 0, b = 0, c = 0, d = 0, testcase = 0, case_a = 0, x = 0, y = 0, num = 0, res = 0;
    for (case_a = 1; case_a < 11; case_a++)
    {
        scanf("%d %d", &testcase, &num);
        flag = 0;
        for (a = 0; a < num; a++)
        {
            scanf("%d %d", &b, &c);
 
            if (case_a == 4)
            {
                case_a = case_a;
            }
 
            if (arr_1[b] != 0 && arr_2[b] == 0)
            {
                arr_2[b] = c;
            }
            if (arr_1[b] == 0 && arr_2[b] == 0)
            {
                arr_1[b] = c;
            }
        }
 
        DFS(arr_1[0]);
    //  printf("\n", x);
        if (flag == 1)
        {
 
 
        }
        else
        {
            DFS(arr_2[0]);
        }
    //  printf("\n", x);
        printf("#%d %d\n", case_a, flag);
 
        for (a = 0; a < num; a++)
        {
             
                arr_2[a] = 0;
             
                arr_1[a] = 0;
         
        }
    }
 
 
 
 
}