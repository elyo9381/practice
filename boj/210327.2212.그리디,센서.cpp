#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
    조건
    N개의 센서 ,K개의 집중국
    N개의 센서가 적어도 하나의 집중국과 통신이 가능해야하며 ,
    집중국의 유지비 문제로 수신가능 영역의 길의합 최소화

    설계
    센서에 집중국의 위치를 지정하려고 하였다. 
    투포인처럼  0 to 첫번째 집중국,첫번째 집중국 to k집중국 사이의  센서 갯수를확인하려고 했다.
    <실패>

    집중국의 수신가능 영역의 길이의 합을 최소화 >> 센서들이 가까운 위치에 집중국을 설치 하는게 최소이다.

*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;

int n, k;

int main(){

    cin >> n >> k;

    vector<int> v(n);
    
    vector<int> diff(n-1,0);

    for(auto &c : v){
        cin >> c;
    }

    sort(v.begin(),v.end());
    for(int i = 0; i<n-1; i++){
        diff[i] = v[i+1] - v[i];
    }

    sort(diff.begin(),diff.end());

    int ans = 0;
    for(int i = 0;i <n-k; i++){
        ans +=diff[i];
    }

    cout << ans;
}
