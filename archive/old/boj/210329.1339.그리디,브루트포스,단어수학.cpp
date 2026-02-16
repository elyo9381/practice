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
    n의 단어
    0-9숫자중 하나로 바꿔서 n개의 수를 합하는 문제
    같은 알파벳은 같은숫자로 바꿔야하며, 두개이상의 알파벳이 같은 숫자로 바뀌어지면 안된다. 

    설계
    N이 10 이므로 2^10개의 경우의수가 발생한다. 그런데 1~9까지 숫자가 올수있으므로 최대 99억까지
    연산횟수가 발생하고 재귀,루프를 이용해서는 못푼다. 

    입력받을때 덱에 string을 입력받고 사이즈를비교해서 길이가 긴 문자열을 앞쪽에 배치한다. 
    앞에서부터 큰수를 부여하고 같은 인덱스가 존재하면 더 큰 문자열에 큰수를 배치한다.
    
    모두 실패...

    디버그 
    왜 2^10으로 생각했을까..? 10개이고 온다안온다 라고 생각을했다. 하지만 잘못된 생각 이었다. 
    1개가 오면 뒤에 9개가 올수있는것이고 N!이기 때문이가. 
    그렇기 때문에 재귀를 통해서 풀수있다. 최대 10! 이기 때문에 

    다른 풀이로는 그리디를 통해서 풀수있다. 
    문자열 각 자릿수가 존재하므로 자릿수를 값을 곱해주어 자릿수 수를 만들어주고 이를 
    정렬하여 A부터 큰수(9)를 매칭하여 더하는 방법이 최적의 해이다. 
    
*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;

int n, ans = 0;
vector<string> word;
int result = -1;
vector<char> alpha;     // 들어있는 알파벳
bool type[26];          // 어떤 알파벳이 사용되었는지 확인
bool check[10];         // 백트레킹을 위한 배열
vector<int> v;          // 각 알파벳에 해당하는 숫자

void cal(){
    int t_result = 0;
    int cnt = 0;
    int a[26];
    for(int i = 0; i<alpha.size(); i++){
        char c = alpha[i];
        int num = v[i];
        a[c - 'A'] = num;
    }

    for(int i = 0; i<word.size(); i++){
        int temp = 0;
        for(int j = 0; j<word[i].size(); j++){
            temp *= 10;
            temp += a[word[i][j] -'A'];
        }
        t_result += temp;
    }
    result = max(result,t_result);
}

void dfs(int cnt){
    if( cnt == 10){
        cal();
        return ;
    }

    for(int i = 10 - alpha.size(); i< 10; i++){
        if(!check[i]){
            v.push_back(i);
            check[i] = true;
            dfs(cnt+1);
            check[i] = false;
            v.pop_back();
        }
    }
}

int main(){

    string s;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> s;
        word.push_back(s);
        for(int j= 0; j<s.size(); j++){
            int c = s[j] - 'A';
            if(!type[c]) {
                type[c] = true;
                alpha.push_back(s[j]);
            }
        }
    }

    dfs(10 - alpha.size());
    cout << result << "\n";
    return 0;

}

// 그리디 방법 
// vector<string> word;
// int result = 0;
// int alpha[26];

// void cal(){
//     for(int i = 0; i< word.size(); i++){
//         int pow = 1;
//         for(int j =  word[i].size() -1 ; j >= 0; j--){
//             int val = word[i][j] - 'A';
//             alpha[val] += pow;
//             pow *= 10;
//         }
//     }
//     sort(alpha, alpha + 26);
//     int num = 0;
//     for(int i = 25; i>=0 ; i--){
//         if(alpha[i] == 0) break;
//         result += alpha[i] * num);
//         num--;
//     }
// }

// int main(){
//     int num;
//     string s;
//     cin >> num;
//     for(int i = 0; i<num; i++){
//         cin >> s;
//         word.push_back(ss);
//     }
//     cal();
//     cout << result ;
//     return 0;
// }