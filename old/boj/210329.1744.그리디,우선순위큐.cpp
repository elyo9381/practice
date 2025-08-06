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
    n 수열이 주어졌을때, 그 수열의 합을 구하려고 한다. 
    수열의 두수를 묶으려고 한다. 위치상관x
    어떤수를 묶게 되면, 수열의합을 구하래 묶은수는 서로곱 한후 더한다.  

    설계
    가장 큰수끼리 묶고 1이 나오면 묶는것을 하지 않는다. 이게 최적이다.
    우선순위 큐에 넣는다.
    top() == 1이 되기 전까지 묶는다.
    또한 음수와 양수를 나눠서 계산한다. 

    설계를 ... 우선순위큐로 한다고 해놓고... 왜 백터를 썻냐.. ㅜㅜ 
*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;

int n, ret = 0;
priority_queue<int> tmp1;
priority_queue<int> tmp2;


int main(){

    cin >> n;

    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        if(a > 0) tmp1.push(a);
        else tmp2.push(-a);
    }


    while(!tmp1.empty()){
        int a,b;

        if(tmp1.size() == 1){
            ret += tmp1.top();
            tmp1.pop();
            break;
        }

        a = tmp1.top();
        tmp1.pop();

        b = tmp1.top();
        tmp1.pop();
        if( a == 1 || b == 1){
            ret += a+b;
            continue;
        }
        ret += a * b;
    }

    while(!tmp2.empty()){
        int a,b;

        if(tmp2.size()== 1){
            ret -= tmp2.top();
            tmp2.pop();
            break;
        }

        a = tmp2.top();
        tmp2.pop();

        b = tmp2.top();
        tmp2.pop();

        if( a == 1 || b == 1){
            ret += a*b;
            continue;
        }
        if( a == 0 || b == 0){
            ret += 0;
            continue;
        }
        ret += a * b;
    }

    cout <<ret << "\n";
}

// int n,ret = 0;
// vector<int> tmp1;
// vector<int> tmp2;

// int main(){
//     cin >> n;

//     for(int i = 0; i<n; i++){
//         int a;
//         cin >> a;
//         if(a > 0) tmp1.push_back(a);
//         else tmp2.push_back(-a);
//     }

//     sort(tmp1.begin(),tmp1.end(),greater<int>());
//     sort(tmp2.begin(),tmp2.end(),greater<int>());


//     for(int i = 0; i < tmp1.size() ; i+=2){
//         if(tmp1.size() == 1){
//             ret += tmp1[i];
//             break;
//         }
//         if( i == tmp1.size()-1) {
//             ret += tmp1[i];
//             break;
//         }

//         if( tmp1[i] == 1 || tmp1[i+1]== 1){
//             ret += tmp1[i] + tmp1[i+1];
//             continue;
//         }
//         int sum = (tmp1[i]*tmp1[i+1]);
//         ret += sum;
//     }

//     for(int i = 0; i < tmp2.size() ; i+=2){
//         if(tmp2.size() == 1){
//             ret -= tmp2[i];
//             break;
//         }
//         if( i == tmp2.size()-1) {
//             ret -= tmp2[i];
//             break;
//         }
//         if( tmp2[i] == 1 || tmp2[i+1]== 1){
//             ret += tmp2[i] + tmp2[i+1];
//             continue;
//         }
//         if( tmp2[i] == 0  || tmp2[i+1]== 0){
//             ret += 0;
//             continue;
//         }

//         int sum = (tmp2[i]*tmp2[i+1]);
//             ret += sum;
        
//     }

//     cout << ret << "\n";
// }

