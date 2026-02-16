#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// #define endl '\n'
#define MAXN 51
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;


/*
    회전하는 큐 문제는 주어진 배열에서 
    원하는 수를 뽑아내는 문제인데 
    push_back, push_front가 되어야한다. 
    그러므로 deque(덱)이용하여서 풀이하였다. 

    원하는 수 몇개가 주어지면 이를 최소한의 이동을 통해서 빼내야 한다.
    1~10
    2 9 5
    위와 같은 문제가 있다면 
    꺼낼 위치를 지정하는 cur
    왼쪽으로 혹은 오른쪽으로(back or front)
    push 해서 빼야하는지에 대한 정보 등이 필요하다.

*/

int n,m; // 입력변수

deque<int> dq; // 양쪽입력을 위해 deque를 사용

void Input()
{
    // 1~ n , 꺼내올 수 m
    cin >> n >> m;

    // 주어진 순열을 deque에 입력
    for(int i = 1; i<= n; i++)
        dq.push_back(i);

    
}

void Solution()
{  
    // 최종 결과를 도출할 변수
    int result = 0;


    for(int i = 0; i< m; i++) // 꺼내올수 m 까지
    {
        int idx; // 꺼내올수를 idx로 지정
        cin >> idx;


        int cur = 1; //뽑아 내고하는 수의 위치
        deque<int>::iterator iter;

        // 반복자를 통해서 꺼내올수 즉 idx에 cur를 지정
        for(iter = dq.begin(); iter<dq.end(); iter++){
            
            if(*iter == idx)
                break;
            cur++;
        }

        //왼쪽으로 몇번 쉬프트? cur을 기준으로   
        int left = cur - 1;

        //오른쪽으로 몇번 쉬프트? cur을 기준으로 
        int right = dq.size() - cur + 1;

        // cur을 기준으로 최소의 push를 구해야하므로 
        // 더작은 쪽으로 pop하고 반대쪽에 push하기 위해서 
        if(left < right)
        {
            for( int j = 1; j<= left; j++)
            {
                // 주어진 조건에 의해서 왼쪽은 front 제거하고 back에 푸시
                int num = dq.front();
                dq.pop_front();
                dq.push_back(num);
                result++; // 
            }
            dq.pop_front();
            
        }
        else
        {
            for(int j = 1; j<=right; j++)
            {
                int num = dq.back();
                dq.pop_back();
                dq.push_front(num);
                result++;
            }
            dq.pop_front();
        }
    }
    cout << result <<endl;    
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

