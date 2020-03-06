#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


   char arr[32];
   stack<char> st;
   int tmp =1, sum =0;
   bool wrong =false;

   cin >> arr;

   // int len= strlen(arr);
   // cout<<len<<endl;
   // 증감식에 arr[i]를 넣게 되면 배열안의 데이터 사이즈만큼
   // 돌아가게 된다. 


   for(int i =0; arr[i]; i++){
    if(arr[i] == '('){
        tmp *=2;
        st.push('(');
    }
    else if( arr[i] =='['){
        tmp *=3;
        st.push('[');
    }
    else if( arr[i] == ')'){
        if( arr[i -1] =='(')
            sum+=tmp;
        if(st.empty())
        {
            wrong= true;
            break;
        }
        if( st.top() == '(')
            st.pop();
        tmp /=2;
    }
    else{
        if(arr[i-1] ==']')
            sum+=tmp;
        if(st.empty())
        {
            wrong=true;
            break;
        }
        if(st.top() =='[')
            st.pop();
        tmp/=3;
    }

   }

    if(wrong || !st.empty())
        cout<< 0;
    else 
        cout<< sum;
}


//dp로 품 내가푼거 아니고 박트리
// 지리네
// /////////////////////////////////////////////////////
// #ifdef _DEBUG
// #include "bits_stdc++.h"
// #else
// #include "bits/stdc++.h"
// #endif
// using namespace std;
// typedef pair<int, int> pii;
// typedef vector<vector<pii > > Edge;
// typedef unsigned long long llu;
// typedef long long ll;
// typedef priority_queue<pii > Pq;
// typedef vector<int>::iterator It;
// #define INF 0x3f3f3f3f
// #define UINF 0xffffffffu
// #define LINF 0x3f3f3f3f3f3f3f3fll
// #define MOD 1000000007
// #define EOD 1e-9
// #define all(x) x.begin(),x.end()
// const double PI = acos(0.0)*2.0;
// /////////////////////////////////////////////////////
// string str;
// int cache[100][100];

// int solve(int le,int ri) {
//     if (le == ri + 1)
//         return 1;
//     if (le >= ri)
//         return 0;
//     int &ret = cache[le][ri];
//     if (ret != -1)
//         return ret;
//     ret = 0;
//     if (str[le] == '('&&str[ri] == ')')
//         ret = max(ret, solve(le + 1, ri - 1)*2);
//     if (str[le] == '['&&str[ri] == ']')
//         ret = max(ret, solve(le + 1, ri - 1)*3);
//     for (int i = le; i < ri; i++) {
//         int a = solve(le, i);
//         int b = solve(i + 1, ri);
//         if(a!=0&&b!=0)
//             ret = max(ret, a + b);
//     }
//     return ret;
// }

// int main() {
//     memset(cache, -1, sizeof(cache));
//     cin >> str;
//     cout<<str.size()-1<<endl;
//     printf("%d\n", solve(0,str.size()-1));
//     return 0;
// }