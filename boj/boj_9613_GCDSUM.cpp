#include <iostream>

using namespace std;

 

const int MAX = 100;

/*유클리드 호제법을 통해서 GCD를 구했고
GCD는 recursion을 이용해서 구했다

풀이방법 
전체 testcase를 입력받고 
2 line 첫번쨰 파라미터는 다음에올 변수들의 사이즈를 의미한다. 
그래서 n입력 받은후 사이즈많큼 array에 변수를 담았다
입력받은 array에 i,j번째를 gcd하였다
*/ 

int arr[MAX];

 
int GCD(int a, int b)
{
    if (a%b == 0)
        return b;
    return GCD(b, a%b);
    // int r;
    // while(b!=0)
    // {
    //     r = a%b;
    //     a=b;
    //     b=r;
    // }

    // return 

}

int lcm(int a, int b)
{
    return a*b / GCD(a,b);
}

 

int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int T;
        cin >> T;
 
        cin.ignore();
        for (int t = 0; t < T; t++)
        {
                 int N;
                 cin >> N;
 

                 for (int i = 0; i < N; i++)
                         cin >> arr[i];
 

                 long long sum = 0;
                 for (int i = 0; i < N; i++){
                         for (int j = i + 1; j < N; j++){
                                 sum += GCD(arr[i], arr[j]);
                                }
                            }
        cout<<sum<<endl;
        }
        return 0;
}