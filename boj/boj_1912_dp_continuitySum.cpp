#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/* */
const int mod =10007;
const int maxn = 1000;

int dp[maxn+1] = {0,};
int buf[maxn+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin>> T;

    vector<int> buf(T);
    vector<int> dp(T);


    for(int i = 0; i<T;i++)
        cin >> buf[i];


    dp[0] = buf[0];

    for(int i =1; i< T; i++)
    {
        dp[i] = max(dp[i-1]+buf[i],buf[i]);
    }



    cout <<  *max_element(dp.begin(),dp.end()) << "\n";

}

/*바크리 소스코드 재귀함수를 이용했다 
2차원 배열을 생성하여 0,1로 구분하고 0은 더한값 1은 */

// #include <iostream>
// #include <stdio.h>
// #include <string.h>

// using namespace std;

// typedef int LL;
// int N;
// LL arr[100000];
// LL cache[100000][2];
// // index부터 시작한 최대 연속합 
// //0계속 뽑을꺼
// //1그만 뽑을꺼 
// LL search(int index,int mode)
// {
//     // cout<<index<<endl;
//     if(index==N)
//         return 0;
//     if(mode==1)
//         return 0; 
    
//     LL &ret=cache[index][mode];
//     if(ret!=-(1e9*2))
//         return ret;
    
//     ret=search(index+1,0)+arr[index];
//     ret=max(ret,search(index+1,1)+arr[index]);
//     cout<< ret <<"    "<<cache[index][1]<<endl;
//     return ret;

// }

// int main()
// {
// //  freopen("sample.txt","r",stdin);
//     cin>>N;
//     for(int i=0;i<N;i++)
//         scanf("%d",&arr[i]);
//     for(int i=0;i<N;i++)
//         for(int j=0;j<2;j++)
//             cache[i][j]=-(1e9*2);
//     LL ans=-(1e9*2);
//     for(int i=N-1;i>=0;i--)
//     {
//         LL temp=search(i,0);
//         if(ans<temp)
//             ans=temp;
//     }
//     printf("%d\n",ans); 
// //  while(true);
//     return 0;
// }