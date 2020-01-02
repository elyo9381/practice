#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
using namespace std;

/*[1] 1부터 n까지의 수를 스택에 넣었다가 뽑아
 늘어 놓음으로써 하나의 수열을 만들수있다.
 -이말은 stack에 오름차순으로 스택에 쌓으며 
 수열을 만들수있다는말-
 [2] 임의이 수열이 주어졌을때 스택을 이용해 
 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로
 push와 pop연산을 수행해야하는지 알아낼수있다.
 -오름차순으로 스택이 존재할때 임의의 배열을 스택으로 구현
 가능한지 묻는것인데 임의의 수열은 백터에 저장하고 itertor를
 통해서 비교하여 구현-
 [3] 비교하여 스택이 안비워진것이면
 임의의순열은 존재할수없는것! NO출력*/

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    vector<int> v;
    stack<int> s;
    vector<char> d;

    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; ++i)
    {
        int k;
        cin>> k;
        v.push_back(k);
    }


    vector<int>::iterator it;
    it = v.begin();
    for(int i = 1; i<=n ;i++)
    {
        s.push(i);
        d.push_back('+');
        while(!s.empty())
        {
            if(*it !=s.top()) break;
            else{
                s.pop();
                d.push_back('-');
                ++it;
            }
        }
    }

    if(s.empty())
    {
        for(int i =0;i<d.size();i++)
        {
            cout<<d[i]<<"\n";
        }
    }
    else cout<< "NO";

    
       
}


//test case 
// 8
// 4
// 3
// 6
// 8
// 7
// 5
// 2
// 1
//test case 
// 5
// 1
// 2
// 5
// 3
// 4
