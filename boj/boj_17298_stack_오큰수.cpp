#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//스택을 통해서 인덱스를 저장하는 방법을 잘생각해라 
/*수열을 입력받아 오큰수를 찾는 문제 
오큰수는 i번쨰 수열이 i+1번보다 작을때 i오른쪽 수열에서 가장 왼쪽에 있는수이다. 
이것을 구할때는 수를 비교하기 위해서 스택을 사용한다. 
스택에 인덱스를 집어넣고 스택과 v[i]를 비교한다. i번째 반복할때 스택에 i인덱스를 푸시하고 
반복문안에서 스택이 비어있지 안을때 v[s.top()]<v[i]를 비교하여  ans배열에 집어 넣는다. */

int main() {
    //C++입출력을 빨리해준다.
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    //testcase 변수
    int t;
    vector<int> v;
    stack<int> s;
    
    cin>>t;
    // 입력버퍼에 있는 것을 무시한다. 
    cin.ignore();

    for(int i =0; i<t;i++)
    {
        int num;
        cin>> num;
        v.push_back(num);
    }

    
    vector<int> ans(v.size(), -1); 
 
    for (int i = 0; i < v.size(); i++) { 
        while (!s.empty() && v[s.top()] < v[i]) { 
            ans[s.top()] = v[i]; 
            s.pop(); 
        } 
        s.push(i); 
    } 
 
    for (int x : ans) {
        cout << x << " ";
    }
    
    return 0;
}
