#include <bits/stdc++.h>

using namespace std;

/*2XN 직사각형 DP문제이다. 
1X2,2X1 직사각형을 통해서 2XN직사각형을 구성하여야하고 
N이 주어질때 타일로 채우는 방법의수를 구하는 문제
재귀 를 통해서 점화식을 확인할것 
why? d[0]와 d[1]이 1이야 하는지 ?? */
int d[1000000] = {0};

// //bottom-up
// int squareNdp(int n)
// {
//     d[0] = 1;
//     d[1] = 1;
//     if( n<=1 )
//         return d[n];

//     else if (d[n] > 0)
//         return d[n];

//     else
//     {
//         for(int i =2 ; i <= n; i++)
//         {
//             d[i]= (d[i-1] + 2 * d[i-2])%10007;
//         }

//         return d[n];
//     }
// }

// top-down 방식
int squareNdp(int n)
{
    d[0] = 1;
    d[1] = 1;
    if( n<=1 )
        return d[n];

    else if (d[n] > 0)
        return d[n];

    else
    {
        d[n] = (squareNdp(n-1) + 2*squareNdp(n-2))%10007;
        return d[n];
    }
}

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    cout<<squareNdp(t)<<endl;

}