#include <iostream>

#include <string>

using namespace std;

 /*
    본 코드 26-34
    디폴트 true일떄 
    예를들어서 전체가 1이면 zero는 false가 되게 설정하여서
    one 일때는 1을 출력시킨다 0일때도 마찬가지이다.
    하지만 둘다 false가 되버리면
    이제 분할 정복을 들어간다 

 */

const int MAX = 64;
int N;
int arr[MAX][MAX];

void compress(int n, int y, int x)
{

        //기저 사례
        if (n == 1)
        {
                 cout << arr[y][x];
                 return;
        }
 

        bool zero = true, one = true;
        for (int i = y; i < y + n; i++)
                 for (int j = x; j < x + n; j++)
                         if (arr[i][j])
                                 zero = false;
                         else
                                 one = false;
 
        if (zero)  cout << 0; 
        else if(one) cout << 1;
        else
        {
                 cout << "(";
                 compress(n / 2, y, x); //2사분
                 compress(n / 2, y, x + n / 2); //1사분면
                 compress(n / 2, y + n / 2, x); //3사분면
                 compress(n / 2, y + n / 2, x + n / 2); //4사분면
                 cout << ")";
        }
        return;
} 

int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin >> N;

        bool zero = true, one = true;
        for (int i = 0; i < N; i++)
        {
                 string s;
                 cin >> s;

                 for (int j = 0; j < N; j++)
                         arr[i][j] = s[j] - '0';
        } 

        compress(N, 0, 0);
        cout << "\n";
        return 0;
}

/*
        0에서 n-1까지 입력을 받고 
        파라미터를 0,n-1로 넘겨준다
        같을 때라는 표시를 
          if(a[p][q]!=a[i][j])
          로 매번 확인하여서 다르면 
        분할재귀 방법으로 풀었다 

*/

// 구사가 코드 분석 하자
// #include <stdio.h>
// int a[1024][1024];
// int s(int i,int e,int j,int f){
//     for (int p=i; p<=e; p++) {
//         for (int q=j; q<=f; q++) {
//             if(a[p][q]!=a[i][j]){
//                 printf("(");
//                 s(i,(i+e)>>1,j,(j+f)>>1);
//                 s(i,(i+e)>>1,((j+f)>>1)+1,f);
//                 s(1+((i+e)>>1),e,j,(j+f)>>1);
//                 s(1+((i+e)>>1),e,((j+f)>>1)+1,f);
//                 printf(")");
//                 return 0;
//             }
//         }
//     }
//     printf(a[i][j]?"1":"0");
//     return 0;
// }
// int main(){
//     int n,i,j;
//     scanf("%d",&n);
//     for (i=0; i<n; i++) {
//         for (j=0; j<n; j++) {
//             scanf("%1d",&a[i][j]);
//         }
//     }
//     s(0,n-1,0,n-1);
// }