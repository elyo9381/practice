#include<iostream>
 
#define endl "\n"
#define MAX 5
using namespace std;
 
int Arr[MAX];
int Select[MAX];
 
void DFS(int Idx, int Cnt)
{
    if (Cnt == 3)
    {
        cout << " { ";
        for (int i = 0; i < 3; i++)
        {
            cout << Select[i] << " ";
        }
        cout << "} " << endl;
        return;
    }
 
    for (int i = Idx; i < MAX; i++)
    {
        Select[Cnt] = Arr[i];
        DFS(i, Cnt + 1);
    }
}
 
int main(void)
{
    for (int i = 0; i < MAX; i++) 
        Arr[i] = i + 1;
    
    DFS(0, 0);
}
