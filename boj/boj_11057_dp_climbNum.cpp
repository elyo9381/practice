// #include <bits/stdc++.h>
// using namespace std;



// /* 오름차순을 이루는 수 
//  D[N][L]  "길이 N이 주어졌을때 오르막수 총 갯수
//  11192 이런건 오름차순 수가 아니고 
//  0부터 시작가능하다. "*/



// const int mod =10007;
// const int maxn = 1000;

// int d[maxn+1][10];

// int climbnum(int n)
// {
//     for(int i=0; i< 10; i++)
//     {
//         d[1][i] = 1;
//     }

//     for( int i=2; i<=n;i++)
//     {
//         for(int j=0; j<10; j++)
//         {
//             for(int k=j; k<10; k++)
//             {
//                 d[i][j] += d[i-1][k] % mod;
//             }
//         }

//     }

//     int sum =0;
//     for(int i =0; i< 10;i++)
//         sum  = (sum+ d[n][i])%mod;

//     return sum;
// }

// int main()
// {
//     int n;
//     cin >> n;


//     cout<< climbnum(n)<<endl;
// }

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

// 메모리를 적게 사용하는 koosaga 코드
// 배열 참조 방법을 참신하게 하여 for문 한번 줄임
// 2차원 배열에서 가로세로 0번 인덱스를 사용안하고 1~11번까지만 사용함
// 그리고 리턴받는수도 
int bino[1002][12];

int main(){
    bino[0][0] = 1;
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n+10; i++){
        bino[i][0] = 1;
        for(int j=1; j<10; j++){
            bino[i][j] = bino[i-1][j] + bino[i-1][j-1];
            bino[i][j] %= 10007;
        }
    }
    printf("%d",bino[n+9][9]);
}