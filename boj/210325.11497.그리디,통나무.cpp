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
 * 인접한 통나무의 높이 차가 최소가 되게 하려함
 * 
 * 설계
 * 가장 큰 높이를 찾고 배열값을 변환시켜주며 
 * 그 높이 값이 가장 낮은 경우를 찾음  그것을 반환  : fail
 * 
 * debug
 * 문제이해를 못함 인접한 배열의 최소값이 되게 하는것과 이것이 원형 배열이라고 할때
 * 인접한 배열값의 최소값을 구현하려고 하였는데 머리로 못품
 * 
 * 이문제의 원칙은 내림차순으로 정렬된 배열에서 가장 높은값이 
 * 중간에 오고 좌우로 배열값들이 들어가게 되면 인접한 배열의 최소 높이다.
 * 
 * 직접구현해도 되지만 결국엔 인덱스 차이가 2가 나게 되며 
 * 정렬한 배열의 인덱스차가 2인 값들을 비교하면 된다. 
 * 
*/

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = int(1e9);
typedef long long ll;

int main(){

    int tc,t,n;

    cin >> tc;

    while(tc--){

        cin >> n;

        vector<int> v(n);
        for(int i = 0; i<n; i++){
            cin >> v[i];
        }

        sort(v.begin(),v.end());
        int res = 0;

        for(int k = 2; k < n; k++){
            int c = v[k] - v[k-2];
            res = max(res,c);
        }
        cout << res << "\n";
    }
}
