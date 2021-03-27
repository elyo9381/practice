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
        cout <<dq[i];
    }

    cout << "\n";


}
