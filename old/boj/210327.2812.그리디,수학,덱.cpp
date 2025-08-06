#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

/*
    조건
    n자리 숫자가 주어질때, 숫자 k개를 지워서 얻을수 있는 가장 큰수 

    설계
    가장 작은수를 지우면 가장 큰수를 얻는거 아냐? 
    배열 2개만들어서 최소값 비교 >> 시간초과
    가장 작은수를 지우는게 이득이 아닐수도 있다. 

    디버그
    중간에 작은값이 껴있을때 어떻게 뺄것인가?
    덱을 이용해서 입력받으면서 인접한 값의 보다 작으면 삭제하는 방법이다.

*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;

int n, k;

int main(){


    cin >> n >> k;

    string s;
    cin >> s;

    deque<char> dq;

    for(int i = 0; i<s.size(); i++){
        while(k && !dq.empty() && dq.back() < s[i]){
            dq.pop_back();
            k--;
        }

        dq.push_back(s[i]);
    }

    for(int i = 0; i<dq.size()-k; i++){
        cout << dq[i];
    }

    cout << "\n";


}
