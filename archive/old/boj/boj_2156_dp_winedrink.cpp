// #include <bits/stdc++.h>
// using namespace std;

// /* 

// dp는 반복적인 사용으로 memoization이 사용가능한 해결방법이다.
// 점화식 작성법 
// 경우의 수를 구해서 하자 .
// 1. 어떤값을 저장할것인지 문장으로 정의해줘야한다.
// 2. D[n]의 값을 어떻게하면 찾을 수 있을지 점화식을 생각한다. 


// */
// const int mod =10007;
// const int maxn = 100000;

// int dp[maxn+1][3]={0,};
// int buf[maxn+1];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int T,n;

//     cin>>T;
//     n=T;
//     for(int testcase =1; testcase<= T; testcase++)
//     {
//         cin >> buf[testcase];
//     }


//     dp[1][1] = buf[1];
    
//     dp[2][0] = buf[1];
//     dp[2][1] = buf[2];
//     dp[2][2] = dp[1][1] + buf[2];


//     for(int i = 3; i<=T; i++)
//     {
//         dp[i][0] = max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
//         dp[i][1] = dp[i-1][0] + buf[i];
//         dp[i][2] = dp[i-1][1] + buf[i];
//     }

//     cout<<max(max(dp[n][0],dp[n][1]),dp[n][2])<<endl;

// }


//방법2

/*n번째에 마시지 않았을때 :dp[n-1]
  n번째에 마시고 , n-1에 마시지 안았을때 dp[n-2] + p[n]
  n번째에 마시고, n-1에도 마셨을때 dp[n-3]+p[n]+p[n-1]*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000;

int p[MAXN+1] = {0,};
int dp[MAXN +1]  = {0,};

int max(int a, int b, int c)
{
    return a > b ? (a > c) ? a : c : (b > c) ? b : c;
}


int bottomUp(int n)
{
    dp[0] = p[0];
    dp[1] = p[0] +p[1];

    for(int i = 2; i<n; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2]+p[i], dp[i-3]+p[i] + p[i-1]);
    }

    return dp[n-1];
}

int main()
{
    int n;
    scanf("%d",&n);

    for (int i =0; i<n; i++)
    {
        scanf("%d",&p[i]);
    }

    printf("%d\n",bottomUp(n));

    return 0;
}