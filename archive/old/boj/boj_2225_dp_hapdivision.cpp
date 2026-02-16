
#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/* 합분해는 3 2입력받아 k번더해서 N이 나오는경우인데 
나는 k번더해서 n이되는 경우가 이해가 안됬었다.
이것을 k번에 집중하여서 바라보게 되었고
k가 2일떄 k + k-1을 해야하므로 i번 에 j번마다 더해주면 
해당 인덱스가 올라가서 k번에 n번 더하여 n이 나온 효과가 나온다.
*/
const int mod =10007;
const int maxn = 200;

long long dp[maxn+1][maxn+1]= {0,};

int buf[maxn+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K,mod=1000000000;
    cin>>N>>K;

    for(int n=0;n<=N;n++){
        dp[1][n]=1; //0,1,2,3,...N
    }


    for(int k = 2; k<=K; k++){
        for(int n=0;n<=N;n++){
            for(int l=0;l<=n;l++){
                dp[k][n]+=dp[k-1][l];
            }
            dp[k][n]%=mod;
        }
    }

     cout<<dp[K][N]<<endl;

     
    // for(int i = 1; i <= k; i++){  
    //     for(int j = 0; j <= n; j++){
    //         for(int l = 0; l <= j; l++){
    //                 d[i][j] += d[i-1][j-l];
    //                 d[i][j] %= 1000000000;
    //             }
    //     }
    // }
}


