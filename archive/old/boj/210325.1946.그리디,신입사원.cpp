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
 * 서류,면접 적어도 하나가 다른 지원자보다 떨어지지 않는자만 선발
 * 
 * 설계
 * 둘다 떨어지는놈 카운트 그리고 전체에서 뺀다.
 * 
 * 디버그
 * 나는 각 성적에서 이웃한 데이터가지고 비교하였는데 이게 아니라 전체를 
 * 그러니깐 모두를 비교해야한다. 그렇기 때문에 둘다 성적이 떨어지는놈을 찾게 되면
 * 인접해서만 비교한다. 
 * 그렇기때문에 적어도 하나를 만족하는 것을 찾아야한다. 
 * 나는 이것을 정렬하고 나머지 면접의 우선순위가 높은놈 아래있는것을 모두 세어 
 * 문제를 풀었다. 
*/

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = int(1e9);
typedef long long ll;

int t,n;

int main(){

    cin >> t;
    while(t--){
        cin >> n;
        

        vector<pair<int,int> > v;
        v.resize(n);

        for(int i = 0; i<n; i++){
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(),v.end());

        int maxNum = v[0].second;
        int cnt = 0;

        for(int i = 1; i<n; i++){
            if(maxNum > v[i].second){
                maxNum = v[i].second;
                continue;
            }
            cnt++;
        }

        cout << v.size() - cnt << "\n";
    }
}