#include <bits/stdc++.h>

#define endl "\n"
#define MX 100
using namespace std;

/*
    자기자신을 다시호출할 때에는 현재 함수에서의 입력값보다
    더 작은 값을 인자로 넘겨주어야 합니다.

    함수의 입력값이 일정 크기 이하일 때에는 더 이상
    자기 자신을 호출하지 말고 값을 바로 반환해야 합니다. 
    이러한 하위 문제를 base condition이라고 부릅니다. 

    Z문제는 리커전이 필요하고  
    사이즈는 2^n으로 들어오고 사이즈가 들어오면
    각각 사분면에 size/2로 사분면이 시작 된다. 
    (0,0) (0,1)
    (1,0) (1,1) 
    일때 cnt++이 진행된다.


*/
int N, R, C, cnt;

void Z(int size, int x, int y)
{
    if(size == 2)
    {
        if(x == R && y == C){
            cout<< cnt << endl;
            return ;
        }
        cnt++;
        if(x == R && y +1 ==C)
        {
            cout<< cnt<< endl;
            return ;
        }cnt++;
        if(x +1 ==R && y == C){
            cout<< cnt <<endl;
            return ;
        }cnt++;
        if(x + 1 == R && y + 1 == C){
            cout << cnt <<endl;
            return ;
        }cnt++;

        return;
    }

    Z(size/2, x, y);
    Z(size/2, x ,y + size/2);
    Z(size/2, x + size/2, y );
    Z(size/2 ,x + size/2, y+size/2);
}

int main()
{
    cin >> N >> R >>C;

    Z(1 << N, 0 ,0);
    return 0;
}