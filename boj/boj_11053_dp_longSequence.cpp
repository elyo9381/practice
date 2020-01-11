#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/* 
stl을 사용한 방법 배열을 사용한 방법 두가지로 풀이했으며
배열을 사용한 방법은 
cursor가 존재한다. cur는 i함수마다 0으로 초기화 되고 aj<ai일때만
dp배열에서 커서의 값을 읽어온다. 
cur을 통해서 증가를 알수있다.


*/
// const int mod =10007;
// const int maxn = 1000;

// int dp[maxn+1] = {0,};
// int buf[maxn+1];

// int bottomUp(int n)
// {
//     int ans=0;
//     for(int i=1; i<=n; i++)
//     {
//         scanf("%d",&buf[i]);
//     }


//     for(int i =1 ;i<=n; i++)
//     {
//         int cur = 0; 
//         for( int j = 1; j < i; j++)
//         {
//             if(buf[j]<buf[i])
//             {
//                 cur= max(cur,dp[j]);
//             }
//         }
//         dp[i] = cur + 1;
//         ans = max(ans, dp[i]);
//     }

//     return ans;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     printf("%d\n",bottomUp(n));
//     return 0;
// }

/* dp배열에는 증가를 샐수있는 조건이 있어야하며
그것이 aj<ai와 dp[i]를 i-반복문에서 초기화 되기 때문에
저장할수있다.*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin>> T;
    

    vector<int> dp(T);
    vector<int> buf(T);

    for(int i =0; i<T; i++)
    {
        cin >> buf[i];
    }

    for(int i =0; i<T;i++)
    {
        dp[i] =1;
        for(int j = 0; j<i; j++)
        {
            if(buf[j]<buf[i] && dp[j]+1>dp[i] )
            {
                dp[i] = dp[j]+1;
            }
        }
    }

    cout<< *max_element(dp.begin(), dp.end())<<"\n";

}