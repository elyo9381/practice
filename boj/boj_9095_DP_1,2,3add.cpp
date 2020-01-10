#include <bits/stdc++.h>

using namespace std;

/* 정수 1,2,3, 을 으로 N을 표현하는 dp문제이다.
4는 1,2,3을 더한수들로 7가지 방법으로 표현가능하고
점화식은 마지막에 더한수가 1일때 2일때 3일때를 생각하여
d[N} = d[n-1] + d[n-2] + d[n-3} 으로 표현가능하다.*/

int d[1000000] = {0};

// //bottom-up

// int intaddDP(int n)
// {
//     d[0] =1; 
//     d[1] =1;
//     d[2] =2;

//     if( n <= 2)
//         return d[n];

//     else if (d[n] > 0)
//         return d[n];

//     else
//     {
//         for(int i =3 ; i<=n ; i++)
//         {
//             d[i] = d[i-1] + d[i-2] + d[i-3];
//         }

//         return d[n];
//     }
// }

// top-down 방식

int intaddDP(int n)
{
    d[0] =1;
    d[1] =1;
    d[2] =2;

    if(n <= 2)
        return d[n];

    else if( d[n] > 0)
        return d[n];

    else
    {
        d[n] = intaddDP(n-1) + intaddDP(n-2)+ intaddDP(n-3);

        return d[n];
    }

}

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    while(tc--)
    {
        int num; 
        cin>> num;
        cout<<intaddDP(num)<<endl;
    }

    return 0;
}
