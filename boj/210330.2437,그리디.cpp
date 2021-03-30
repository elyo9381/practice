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
    무게가 양의 정우 N개 주어진다.
    추들을 사용하여 측정할수없는 양의 정수 무게중 최솟값을 구하라

    설계 
    v[0] 1이 오지 않았을때를 생각해야한다 .
    또한 만들지 못하는 최소정수는 x+v[i]+1이 v[i+1]보다 작을때이다. 
    
    
*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back

int n;

int main(){

    cin >> n;
    vector<int>  v(n);

    for( auto& c : v){
        cin >> c;
    }

    sort(v.begin(),v.end());
    bool check = false;

    if(v[0]!=1){
        cout <<1 << "\n";
    }
    else {
    int sum = 0;
        for(int i = 0; i<n; i++){
            sum+=v[i];
            // ret = min(ret, sum);
            if(sum+1 < v[i+1]){
                check = true;
                break;
            }
        }
        cout << sum + 1 <<"\n";

    }
}

