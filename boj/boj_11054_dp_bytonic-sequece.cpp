#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/* */
const int mod =10007;
const int maxn = 1000;

// int dp[maxn+1] = {0,};
// int buf[maxn+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin>> T;
    

    vector<int> dp1(T);
    vector<int> dp2(T);
    vector<int> buf(T);


    for(int i =0; i<T; i++)
    {
        cin >> buf[i];
    }

    for(int i =0; i<T;i++)
    {

        dp1[i] = 1;
        for(int j = 0; j<i; j++)
        {
            if(buf[j]<buf[i] && dp1[j] + 1 > dp1[i])
            {
                dp1[i]= dp1[j]+1;
            }
        }
    }


    for(int i =T-1 ;i>=0; i--)
    {
        dp2[i] =1;
        for(int j =T-1; j>i; j--)
        {
            if(buf[j]< buf[i] && dp2[j] +1 > dp2[i])
            {
                dp2[i] = dp2[j]+1;
            }
        }
    }
   
    int ans = dp1[0] + dp2[0] - 1;

    for (int i = 0; i < T; i++)
    {
        if (ans < dp1[i] + dp2[i] - 1)
            ans = dp1[i] + dp2[i] - 1;
    }

    cout << ans << "\n";

}

/*배열중에 가장 긴 순열을 구하고 
역순으로 가장 긴 순열 을 구하여 
두 dp를 더하고 -1을 뺴줘서 결과값이 가장 큰것을 선택한다. */
//koosaga code

// #include <cstdio>
// #include <algorithm>
// using namespace std;

// int n;
// int a[1005], dp[1005], dp2[1005];

// int main(){
//     scanf("%d",&n); 
//     for(int i=1; i<=n; i++){
//         scanf("%d",&a[i]);
//     }
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<i; j++){
//             if(a[j] < a[i]) dp[i] = max(dp[i], dp[j]);
//         }
//         dp[i]++;
//     }
//     reverse(a+1, a+n+1);
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<i; j++){
//             if(a[j] < a[i]) dp2[i] = max(dp2[i], dp2[j]);
//         }
//         dp2[i]++;
//     }
//     reverse(dp2+1, dp2+n+1);
//     int ret = 0;
//     for(int i=1; i<=n; i++){
//         ret = max(ret, dp[i] + dp2[i] - 1);
//     }
//     printf("%d",ret);
// }
