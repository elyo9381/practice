#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

/**
 * 
 *  - 0,1로만 이루어진 문자열 s
 *  - s의 모든 숫자를 전부 같게 만들려함
 *  - 하나 이상의 숫자를 잡고 모두 뒤집는것
 * 
 *  설계 
 *  입력
 *  - 연속된 수 체크(zero,one)
 *  - zero,one중 최소값 반환
 * 
*/


int main(){

    string s;

    cin >> s;
    int zeroCount = 0;
    int oneCount = 0;
    int ret ;

    for(int i = 0; i<s.size(); i++){
        if(s[i] != s[i+1] && s[i] == '0'){
            zeroCount+=1;
        }
        if(s[i] != s[i+1] && s[i] == '1'){
            oneCount+=1;
        }
    }

    ret = zeroCount < oneCount ? zeroCount : oneCount;

    cout << ret << "\n";

}