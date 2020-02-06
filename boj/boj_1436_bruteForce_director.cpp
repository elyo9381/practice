#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 10000
using namespace std;

/*
    나는 매우간단하게 2번째이면 2-1'666' 이고 n번째는 n-1 + '666'이라고 생각했다
    하지만 조건에 (N번째로자은 종말의숫자)라는 조건이 있었고 
    N == 7 일때는 6666 으로 종말의 숫자가 안된다. 
    6666보다 작은 종말의수가 6660이 존재한다.
    그렇기 떄문에 initnum(666)을 설정하여서 666부터 
    전부 세어가며 6이 3개 존재하는지 체크를 해야할것같다.  
*/

int M, N;
int num = 666;
int turn =1;

void Input()
{   
   cin >> N;
}
void Solution()
{
    while(1)
    {
        if(turn == N) break;

        num++;
        int copyNum = num;

        int six = 0;
        while(copyNum){
            int temp = copyNum % 10;
            if(temp == 6)
                six++;
            else if(six<3)
                six = 0;
            copyNum /= 10;
        }

        if(six >= 3)
            turn++;
    }

    cout<< num << endl;
}

void Solve()
{
    Input();

    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
} 