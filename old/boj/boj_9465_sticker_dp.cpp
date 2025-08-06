#include <bits/stdc++.h>
using namespace std;


// 방법1은 시간은 더빠른데 메모리를 많이 잡아먹음    3935kb/88ms
// 방법2는 메모리는 덜 잡아먹는데 시간이 1.5배 느림  3538kb/136ms


//방법 1
 /* 점화식 세우는법
 N번째에 올것을 생각한다. 
 N번째에는 n-1번째하고 3가지 경우가 올수있다.
 아무것도 안오거나 
 0번 행만 뜯기건나
 1번 행만 뜯기거나 총 3가지 경우이고 

 아무것도 안뜯겼을땐 
 N-1번째에서 가장 큰것을 골라서 d[n][0]에 입력

 0번 행만 뜯겼을때 
 n-1 번째에서 아무것도 안뜯긴거랑, 1번행만 뜯겼을때중 가장큰것을 고른다.

 1번 행만 뜯겼을때 
 n-1 번째에서 아무것도 안뜯긴거랑, 0번행만 뜯겼을때중 가장 큰값을 고른다.

 모든 경우의수에서 가장 큰값을 반환한다. */

const int mod =10007;
const int maxn = 100000;

int d[maxn+1][3] = {0,};
int arr[maxn+1][2] ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int T;
    cin>>T;

    for(int testcase = 0; testcase<T; testcase++){
    
    int n;
    cin >> n;

    for(int i = 1; i<=n; i++)
        cin >> arr[i][0];

    for(int i = 1; i<=n; i++)
        cin >> arr[i][1];

    for(int i=1; i<=n; i++)
    {
        d[i][0] = max(max(d[i-1][0], d[i-1][1]), d[i-1][2]);
        d[i][1] = max(d[i-1][0], d[i-1][2]) + arr[i][0];
        d[i][2] = max(d[i-1][0], d[i-1][1]) + arr[i][1];
    }

    cout<< max(max(d[n][0],d[n][1]),d[n][2])<<"\n";
    }



    // cout<< climbnum(n)<<endl;
}

//방법2

/*방법1은 N번쨰 올 모든 경우의 수를 생각하여 점화식을 발견하였다면
방법2는 N번째에 더해질 d[i]에 대한 값을 비교하여 점화식을 세웠다.*/
// int d[2][maxn+1];
// int arr[2][maxn+1];

// int max(int a, int b) { if (a > b) return a; return b; }


// int bottomUp(int n)
// {
//     for(int i = 0 ; i< n; i++)
//         scanf("%d", &arr[0][i]);

//     for(int i =0 ; i<n; i++)
//         scanf("%d", &arr[1][i]);

//     d[0][0] = arr[0][0];
//     d[1][0] = arr[1][0];

//     d[0][1] = arr[0][1] + d[1][0];
//     d[1][1] = arr[1][1] + d[0][0];

//     for(int i =2; i<n ; i++)
//     {
//         d[0][i] = arr[0][i] + max(d[1][i-1],d[1][i-2]);
//         d[1][i] = arr[1][i] + max(d[0][i-1], d[0][i-2]);
//     }


//     return max(d[0][n-1], d[1][n-1]);


// }


// int main()
// {
//     int t,n;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%d", &n);
//         printf("%d\n",bottomUp(n));
//     }
// }
