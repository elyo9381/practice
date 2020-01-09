#include <bits/stdc++.h>

using namespace std;

/*2XN 직사각형 DP문제이다. 
1X2,2X1 직사각형을 통해서 2XN직사각형을 구성하여야하고 
N이 주어질때 타일로 채우는 방법의수를 구하는 문제
재귀 를 통해서 점화식을 확인할것 
why? d[0]와 d[1]이 1이야 하는지 ?? */

//bottom-up 방식
// int d[1001] = {1, 1};   // d[0] = 1, d[1] = 1, d[0~99] = 0

// d[0] = 1; 이 문제에서 점화식이 정상적으로 작동하려면 d[0]이 1이어야함.
// d[1] = 1; 원래 d[1]은 1이라서.

// N을 1로 만드는데 필요한 최소 연산횟수를 반환하는 함수
// int getAllCombiCount(int n)
// {
//     if (n <= 1)
//         return d[n];
    
//     else if (d[n] > 0)  // n >= 2 경우, d[n] > 0 이면 이미 계산된 결과가 있음을 의미하므로 바로 결과반환
//         return d[n];
    
//     else
//     {
//         for(int i=2; i <= n; i++)
//         {
//             // 이렇게 해주면 d[i]에는 10007 미만의 수만 들어가게 된다.
//             d[i] = (d[i-1] + d[i-2])% 10007;
//         }
//         return d[n];
    }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     cout << getAllCombiCount(n);
// }
int d[1000000] = {0};

int squareNdp(int n)
{
    d[0] =1;
    d[1] =1;
    if(n<=1)
        return d[n];

    else if(d[n] > 0)
        return d[n];

    else
    {
        d[n] = (squreNdp(n-1) + squreNdp(n-2))%10007;
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