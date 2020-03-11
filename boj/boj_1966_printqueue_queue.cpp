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
   프린트 큐는 몇 번째로 인쇄되었는지 궁금한 문서가 
   현재 queue의 어떤 위치에 있는지를 알려주는 M을 잘 이해해야한다. 
   나는 이해하지 못해서 매우 불편했었다.... 
   조건1은 지목한 pos를 가르키는것이었고 조건 2,3은 양방향 입력삭제였다.
   이때 조건 2,3 실행시 최소값으로 실행되는것인데 
   조건 2,3이 실행되고 나선 result값이 하나식 늘어나야 하며
   배열에서 빠선탰되어 빠졌으면 삭제 되어야한다. 
   이것을 잊지말것!
   


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
            
            cout << *iter << ' ';
            if(*iter == idx)
                break;
            cur++;
        }
        cout << endl;
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
                result++; // 옮긴횟구가 더해진다. 
            }
            dq.pop_front(); // pop 한번 더하는 이유는 left는 2번 됫는데 pop은 
                            // 한번만 되어서 그렇다 

        }
        else
        {
            for(int j = 1; j<=right; j++) // 위와동일 하지만 right
            {
                int num = dq.back();
                dq.pop_back();
                dq.push_front(num);
                result++;
            }
            dq.pop_front();
        }
    }
    cout << result <<endl;   //결과를q반환한다. 
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

