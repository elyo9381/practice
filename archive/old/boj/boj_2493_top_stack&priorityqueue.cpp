
#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define endl '\n'
#define MAXN 100001
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;

/*
    a,b가 주어졌을때 a가 b 의 앞에 서야한다는 의미는
    a<-b 그래프의 의미이다. 
    정점 b가 정점 a에 들어가는 의미이고 이때 
    위상정렬을 이용하여 풀수있다. 

    위상정렬은 그래프로 받고 동시에 indeg[b]++;을 선언해서 
    배열입력을 받는다. 
    내보내는 간선이 있으면 indeg배열의 인덱스를 ++한다.
    그리고 indeg[i] == 0이면 모두 큐에 넣는다. 
    indeg를 하나식지우면고 indeg 0이되면 그정점을 큐에 추가한다. 
    위의내용 반복
    -사이클존재시 그냥 리턴 & 함수내부에서 결과 출력
*/

int n,k;
stack<pair<int, int>> st;


void Input()
{   

   
    cin>>n;

    for(int i =1; i<=n; i++){
        cin >> k;
        while(!st.empty()){
            if(st.top().second> k){
                cout << st.top().first <<' ';
                break;
            }
            st.pop();
        }
        if(st.empty()) cout<< "0 ";
        st.push(make_pair(i,k));
    }



}


void Solution()
{  
  
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

// //괄호 체크 
// bool check(string str){
//     int len = (int)str.length();
//     stack<char> st;

//     for(int i  = 0 ; i<len;  i++){
//         char c = str[i];
//         if(c=='(')
//         {
//             st.push(str[i]);
//         }else{
//             if(!st.empty()){
//                 st.pop();
//             }else{
//                 return false;
//             }
//         }
//     }
//     return st.emtpy();
// }

// //쇠막대기

// stack<char> st;

// string str;
// getline(cin,str);

// int sum = 0, cnt=0;
// int size  = str.size();
// for(int i=0; i<size; i++){
//     if(str[i] == '(')
//     {
//         cnt++;

//     }else
//     {
//         if(str[i-1] == '('){
//             cnt--;
//             sum+=cnt;

//         }
//         else
//         {
//             cnt--;
//             sum++;
//         }
//     }

//     cout<< sum << "\n";
//     return 0;
// }

// //괄호 

// char arr[32];
// stack<char> st;

// int tmp =1; sum =0;
// bool wrong = false;

// cin >> arr;

// for(int i  = 0; arr[i]; i++){
//     if(arr[i] == '('){
//         tmp*=2;
//         st.push('(');
//     }
//     else if( arr[i] =='('){
//         if(arr[i-1] == '(');
//             sum+=tmp;
//         if(st.empty()){
//             wrong = true;
//             break;
//         }
//         if( st.top() =='(')
//             st.pop();
//         tmp /=2;
//     }
//     else {
//         if( arr[i-1] == ']')
//             sum+=tmp;
//         if(st.empty())
//         {
//             wrong = true;
//             break;
//         }
//         if(st.top() == '[')
//             st.pop();
//         tmp/=3;
//     }

// }
//     if(wrong || !st.empty())
//         cout<< 0;
//     else
//         cout << sum;


// //탑 
// int n,k;
// stack<pair<int,int> > st;

// int main(){
//     scanf("%d",&n);

//     for(int i =1; i<=n; i++){
//         scanf("%d", &k);
//         while(!st.emtpy()){
//             if(st.top().second> k){
//                 printf("%d ", st.top().first);
//                 break;
//             }
//             st.pop();
//         }
//         if(st.emtpy()) printf("0 ");
//         st.push(make_pair(i,k));
//     }
// }
// // 우선순위큐를 이용한 풀이 (탑)

const int MAX = 500000 + 1;

int height[MAX];
int result[MAX];

int main(void)
{

    ios_base::sync_with_stdio();
    cin.tie(0);
    int N;

    cin >> N;

    for(int i =1; i<=N; i++)
        cin >> height[i];

    //minHeap
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int >>> pq;
    pq.push({height[N], N});
    for(int i = N-1; i>=1; i--){
        while(1)
        {
            if(pq.empty()) break;


            pair<int, int> cur = pq.top();
            bool popped = false;

            if(cur.first <= height[i])
            {
                pq.pop();
                result[cur.second] = i;
                popped = true;
            }


            if(!popped) break;
        }
        pq.push({height[i], i});
    }

    for(int i =1; i<=N; i++)
        cout<< result<< " ";
    cout<< "\n";
    return 0;
}
