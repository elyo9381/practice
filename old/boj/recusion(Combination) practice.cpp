#include<iostream>
 
#define MAX 5
using namespace std;


/*
    
    Combination make to use recursion ! 
    재귀를 통해서 인자를 2개 받는다 Idx,Cnt인자를 받고 
    Idx는 시작하는 값을 Cnt순열의 갯수를 센다.
    bool Select를 두어서 매번 체크를 하고 
    Select가 true이면 continue를 진행하여 
    조합을 완성한다.
*/
int Arr[MAX];
bool Select[MAX];
 
void Print()
{
    for (int i = 0; i < MAX; i++)
    {
        if (Select[i] == true)
        {
            cout << Arr[i] << " ";
        }
    }
    cout << endl;
 
}
 
void DFS(int Idx, int Cnt)
{
    if (Cnt == 3)
    {
        Print();
        return;
    }
 
    for (int i = Idx; i < MAX; i++)
    {
        cout<< i <<' ' <<Cnt <<endl;
        if (Select[i] == true) continue;
        Select[i] = true;

        DFS(i, Cnt + 1);
        Select[i] = false;
    }
}
 
int main(void)
{
    Arr[0] = 1;
    Arr[1] = 2;
    Arr[2] = 3;
    Arr[3] = 4;
    Arr[4] = 5;
 
    DFS(0, 0);
}