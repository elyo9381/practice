#include <bits/stdc++.h>

using namespace std;

/* 카드 구매 하기 1의 최솟값 버전인데 
최솟값을 설정해주지 않으면 d[1] =0 이므로 계속 0값이 
나온다. 그러므로 topdown은 d[n] == 0 일때 d[n] = p[i] +getMinprice(n-1)을 통해서 
d[1]에 값을 설정하였다.*/

int min(int a, int b)
{
    return a > b ? b : a ;
}
/* */

int d[1001] = {0};
int p[10001] = {0};
// top-down
// int getMinPrice(int n)
// {
//     if( n==0)
//         return d[n];

//     else if(d[n] > 0)
//         return d[n];

//     else
//     {
//         for(int i =1; i<=n; i++)
//         {

//             if( d[n] == 0)
//             {
//                 d[n] = p[i] + getMinPrice(n-i);
//             }
//             else
//             {
//                 d[n] = min(d[n],getMinPrice(n-i) + p[i]);
//             }
//         }

//         return d[n];
//     }

// }


// bottom-up
int getMinPrice(int n)
{

    if(n==0)
        return d[n];

    else if(d[n]> 0)
        return d[n];

    else
    {
    d[0] = 0;
        for (int i = 1; i <= n; i++) 
            d[i] = 10000;
 

        for(int i =1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
            {
                d[i] = min(d[i], d[i-j]+p[j]);
            }
        }
        return d[n];
    }
}


int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    for(int i =1; i<=tc ; i++)
    {
        cin >> p[i];
    }
    
    cout<<getMinPrice(tc)<<endl;

    return 0;
}