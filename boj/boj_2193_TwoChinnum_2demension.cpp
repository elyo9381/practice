#include <bits/stdc++.h>

using namespace std;

/* 1차원 배열과 2차원 배열의 점화식이 있다. 
1차원 배열의 점화심은 뒤에서 0,1을 기준으로 
n의 맨뒤에 위치 할 수가 0일떄 N-1에는 0,1이 올수있다
n의 맨뒤에 위치 할 수가 1일때는 N-1에는 1은 올수 없으니 
0만 올수 있고 01이 하나의 세트라고 봤을때는 n-2에 1이 올수있다.
그래서 점화식은 d[n] = d[n-1] + d[n-2] 가 되며
반복자 3이상일 때부터 가능하다.*/



typedef long long ll;
// ll d[91] = {0};


// top down 방식
// ll getTwoChinNum(int n)
// {
//     d[1] =1;
//     d[2] =1;


//     if( n<=2)
//         return d[n];

//     else if (d[n] > 0)
//         return d[n];

//     else
//         d[n]=getTwoChinNum(n-1)+getTwoChinNum(n-2);
//         return d[n];
// }



// // bottom-up방식
// ll getTwoChinNum(int n)
// {
//     d[1] = 1;
//     d[2] = 1;

//     if(n<=2)
//         return d[n];

//     else if (d[n] > 0)
//         return d[n];

//     else
//     {
//         for(int i= 3; i<=n; i++)
//         {
//             d[i] = d[i-1] + d[i-2];
//         }
//         return d[n];
//     }
// }
// int main()
// {   
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int tc;
//     cin>>tc;

//     cout<< getTwoChinNum(tc)<<endl;

//     return 0;
// }

/*2차원배열을 통해서 점화식을 구할때
D[N][L] = 마지막 자리가 L이고 길이가 N인 이친수의개수 
라고한다면 N자리 일때 L에 0과 1이 올수있다.
D[N][0] = 마지막 자리가 0이고 길이가 N인 이친수의개수
D[N][0] = 마지막 자리가 1이고 길이가 N인 이친수의 개수

D[N][L] = D[N][0] + D[N][1];

case1)
D[N][0] = D[N-1][0] + D[N-2][1]
N번째 자리에는 0이 오는 이친수의 경우
N-1번째에는 0,1 모두 올수 있다.


case2)
D[N][1] = D[N-1][0]

인자가 이렇게 많고 복잡할땐 bottom-up방식이 편하다 
재귀함수버전은 나중에 생각해보자 
*/


int main()
{
    int n;
    cin>>n;

    ll d[91][2]={0};

    d[2][0] = 1;

    if( n<=2)
        cout<<1<<"\n";
    else{


    for(int i =3; i<=n; i++)
    {
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }

    cout<< d[n][0] + d[n][1] <<endl;
        
    }


}
