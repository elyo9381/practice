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
    과제마다 마감일이 있으므로 모든 과제를 끝내지 못할 수 도 있다. 
    과제마다 끝냈을때 얻을 수 있는 점수가 있는데, 마감일이 지난 과제는 점수를 받을수 없다. 
    최댓값 구하라

    설계 
    마감일마다 최대 점수를 구해서 합한다.
    우선순위 큐로 최대점수를 구한다. 
    마감일을 내림차순한다.
    실패했다.

    디버그
    마감이란것이 존재하고 이를 이용해서 탐욕적 기법을 사용해야한다. 
    어떻게 그리디를 적용하는가? 마감일을 기준으로 점수가 큰값은 최대한 늦은날에 해야하고 
    그날에 과제가있다면 하루 당겨서 하는 접근이 필요하다 
    
*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int MAX = 1000;
const int INF = 987654321;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back

bool com(ii a, ii b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int dayScore[MAX];

int n;

int main(){

    int n,sum = 0;
    cin >> n;
    vector<ii> v(n);
    for(int i =0 ; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(),v.end(),com);

    for(int i = 0; i<n; i++){
        int day = v[i].first;

        while(1){

            if( dayScore[day] == 0 || day < 0){
                break;
            }
            day--;
        }

        if(day >= 0){
            dayScore[day] = v[i].second;
        }
    }

    int result = 0;

    
    for(int i = 1; i< MAX; i++){
        result += dayScore[i];
    }

    cout << result << "\n";


}

