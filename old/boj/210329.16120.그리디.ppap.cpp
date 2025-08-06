#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
using namespace std;

/*
    조건
    ppap 는 ppap 문자열이다.
    ppap 문자열에서 p하나를 ppap로 바꾼 문자열은 ppap 문자열이다.


    설계 
    처음에 pppp,aaaa같은 경우가 올지 생각하지 못하여 apap, ppap로 끝나면 된다고 생각하였다. 
    바로 틀렸다. ㅎ
    
    ppap를 발견하면 p로 치환한다. 
    이때 주의할점 s의 인덱스별로 확인하여야하는데 스택구조를 생각하면 손쉽게 해결할수있다. 
    문자열의 뒤에서부터 확인후 pop을 하고 PPAP인지 확인후 다시 문자열을 그대로 만들어주면된다.
    PPAP가 아닌경우 원래 chk문자열에 다시 붙여준다. 
    뒤에서 4개만 확인하므로 계속 확인이 들어간다.
*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back

int n, ret = 0;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.second > b.second;
}


int main(){

    string s;
    cin >> s;
    string chk = "";
    for(int i = 0; i<s.length(); i++){
        chk += s[i];
        if(chk.length() >= 4){
            char a, b, c, d;
            d = chk.back(); chk.pop_back();
            c = chk.back(); chk.pop_back();
            b = chk.back(); chk.pop_back();
            a = chk.back(); chk.pop_back();
            string now ="";
            now +=a; now +=b; now +=c; now+=d;
            if(now != "PPAP"){
                chk += now;
            } else {
                chk += "P";
            }
        }

        else if( chk == "PPAP"){
            cout << "PPAP"; return 0;
        }
    }
    if(chk == "P" || chk == "PPAP"){
        cout << "PPAP"; return 0;
    }
    cout <<"NP";
}