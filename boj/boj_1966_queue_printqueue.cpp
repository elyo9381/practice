#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// #define endl '\n'
#define MAXN 101
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;

/*
    우선순위가 큰 인덱스가 있으면 그앞에 있는것은 뒤로 보내야한다.
    그렇기 때문에 이를 진행하기 위해서 idx변수를 설정해 
    브루트 포스 방법으로 계속 확인하였다. 

*/

int t,m,n;  // 입력을 받기위한 변수
int priority[MAXN]; // 우선순위 배열
int order[MAXN];    // 각 인덱스에 인쇄 순위를 체크함
bool check[MAXN];   // 우선 순위 체크 배열

queue<int> q;


int Solution()
{  
    // 우선순위가 가장높은게 먼저 인쇄됨
    // 인쇄 랭크를 표현
    int rank = 1;

    // 큐가 차 있다는건 인쇄할것이 있다는뜻
    while(!q.empty())
    {
        // 0번째 pos를 선택하고 큐에서 제거 
        int temp = q.front();
        q.pop();


        // 큐에 다시 넣을것을 생각한 변수 idx
        // 우선순위 비교를 위한 반복자
        int idx = 0;

        // top에 우선순위가 높은 수가 있다면  true이고
        // top 뒤에 우선순위가 높은것이 있다면 false를 진행

        bool top = true;
        
        //큐사이즈로 변환

        while(1)
        {
            //인덱스가 n을 넘어버리면 안되니 제어
            if( idx >= n )
                break;

            // idx == temp를 한이유는 temp는 pos뜻한다.
            // 우선순위를 알수있도록 비교해야하는데 
            // 우선순위를 확인할 idx를 증가 시켜줘야한다.

            // 그리고 check[idx]는 높은 우선순위를 방문했는지의 여부 

            if( idx == temp || check[idx] )
            {
                idx++;
                continue;
            }

            // 높아진 idx를 통해서 우선순위 배열에서 
            // 배열을 비교하여 우선순위가 높은것이 있다면
            // temp즉 pos을 다시 큐에 넣는다. 
            // top 은 front이었으므로 큐에서 가장 앞에 있고 
            // top보다 더 우선순위가 높다면 top false해준다.
            if(priority[temp] < priority[idx])
            {

                q.push(temp);
                top = false;
                break;
            }

            // 위의 어떤 내용에 들어가지 않을때 비교를 위해서 
            // idx하나 증가
            idx++;
        }

        // top에 가장 큰 우선순위가 온것은 첫번째 인쇄이다.
        // 매번 가장큰것 순으로 우선순위가 되면
        // 인쇄를 하게 되는것이고 각각의 pos에 해당하는
        // check 배열과 order배열에 true와 인쇄 랭크를 등록한다.
        if(top)
        {

            check[temp] = true;
            order[temp] = rank++;
        }
    }

    return order[m];
}
    
void Input()
{
    cin >> n >> m;

    //매번 테스트케이스를 초기화 해줘야한다.
    memset(check, false, sizeof(check)); 

    for(int j = 0; j < n; j++)
    {
        // 우선순위를 우선 순위 배열에 입력받는다.
        cin >> priority[j];
        // a,b,c,d와 같이 큐에 입력해야하므로 인덱스를 큐에 입력한다.
        q.push(j);
    }

    cout<< Solution() <<endl;

}

void Solve()
{
    cin >> t;
    while(t--)
    {
        Input();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}