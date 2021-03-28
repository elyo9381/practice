#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
    조건
    문자열 s,t가 주어질때
    s >> t로 바꾸는 게임 

    문자열의 뒤에 A를 추가한다.
    문자열을 뒤집고 뒤에 B를 추가한다.
    s를 t로 만들수 있는지 없는지 알아내는 프로그램 작성

    설계
    조건을 기능으로 만들고 loop에서 기능을 추가하여 만들수있는지 확인한다.
    s.size() > t.size() 를 넘으면 루프탈출 : fail
    1번 조건만 실행될때, 2번만 실행 될수있으니 재귀를 통해서 풀어야할거같다. : fail

    디버그
    s와 t의 길이가 1000까지이므로 재귀를 돌리면 경우의수는 1000^2의 경우의 수가 생긴다
    이를 재귀로 돌리면 시간초과이다. 
    아이디어를 통해서 문제를 접근해야한다. 주어진 t에서 s를 만들수있는가 의 접근이다.

*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;

int main(){

    string s,t;

    cin >> s >> t;

    while(1){
        if(s.length() == t.length()){
            if(s==t){
                flag = true;
            }
            break;
        }

        char c = t[t.length() - 1];
        t.pop_back();
        
        if(c == 'B'){
            reverse(t.begin(),t.end());
        }
    }
    cout << flag << "\n";
    return 0;
}