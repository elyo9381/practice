#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>



using namespace std;

/**
 * 
 * 조건
 * 피보나치 
 * 최소 개수의 서로 다른 피보나치 수들의 합을 나타낸다.
 * 피보나치 수들의 합이 주어진 정수와 같게 되는 최소 갯수의 서로 다른 피보나치 수들을 구하라 
 * 
 * 설계
 * 피보나치 배열을 구해놓고 배열값을 더하면서 n과 같을때를 탐색(재귀)? 
 * 될지 안될지는 구현해보지 않았지만 그리디 스럽게 접근하지 못함
 * 
 * N에서 N에 가까운 큰수를 빼서 이수를 fibo에서 만들수있는지 
 * 그리디 하게 접근해야함
 * 
*/

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = int(1e9);
typedef long long ll;

int tc,n;

int main(){

    cin >> tc;
    
    int  fibo[44] = {1,2};
    for(int i = 2; i<44; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }


    while(tc--){
        
        int t;
        cin >> n;

        vector<int> ans;

        while(n){
            for(int i = 0; i<44; i++){
                if(fibo[i] <= n) t = fibo[i];
            }
            n -= t;
            ans.push_back(t);
        }

        for(int i = ans.size() -1 ; i>=0 ; i--){
            cout << ans[i] << " ";
        }
        cout << "\n";        
    }
}