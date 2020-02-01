#include <bits/stdc++.h>

#define endl "\n"
#define MAXN 100

using namespace std;

int cup[4] = {0,1,2,3};

void swap(int x, int y)
{
    int temp;
    temp = cup[x];
    cup[x] = cup[y];
    cup[y] = temp;
    return ; 
}


int main(void)
{
    int N,x,y;

    cin >> N;

    for(int i = 0 ; i < N ; i++){
        cin >> x >> y;
        swap(x,y);
    }

    for(int i =1;i<=3; i++){
        if(cup[i] == 1) cout << i << endl;
    }
    return 0;
}