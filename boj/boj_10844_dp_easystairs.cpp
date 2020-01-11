#include <bits/stdc++.h>

using namespace std;

int d[101][10];

int main()
{
    int n;
    cin >> n;

    //n이 1일 때 결과가 9이므로 해주는 초기화
    for(int i =1;i<=9; i++)
    {
        d[1][i] = 1;
    }

    for(int i =2; i<=n; i++)
    {
        for(int j=0; j<=9; j++)
        {
            if(j==0)
                d[i][j] = d[i-1][j+1];
            else if( j==9)
                d[i][j] = d[i-1][j-1];
            else
                d[i][j] = d[i-1][j-1] + d[i-1][j+1];

            d[i][j] %= 1000000000;
        }
    }

    long long sum = 0;

    for(int i=0; i<=9; i++)
    {
        sum+=d[n][i];
    }

    cout<< sum% 1000000000<<endl;
}