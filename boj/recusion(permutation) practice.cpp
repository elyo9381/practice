#include<iostream>
#include<vector>
 
#define MAX 5
using namespace std;
 
int Arr[MAX];
bool Select[MAX];
vector<int> V;
 
void Print()
{
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }
    cout << endl;
}
 
void DFS(int Cnt)
{
    if (Cnt == 3)
    {
        Print();
        return;
    }
 
    for (int i = 0; i < MAX; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        V.push_back(Arr[i]);
        DFS(Cnt + 1);
        V.pop_back();
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
 
    DFS(0);
}
