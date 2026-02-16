#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

/*
    조건
    선분의 길이를 구하라 
    선분은 겹치게 그리는것도 된다. 
    n개의 선분은 그리는데 x,y좌표가 주어진다.

    설계
    pair로 입력 받고 O(n)으로 풀려고 했다. 
    이전배열과 비교하며 겹치는곳은 이전 범위부터 진행하려고 하였고 안겹치면 더하는방법으로 
    : fail함..

    디버그
    라인스위핑의 문제이다. 그리디하게 겹치면 겹치는길이가최대가 되게 한다. 
    겹치는 부분을 어떻게 알아내느냐 이진탐색을 통해서 알수있으며
    다른방법으로는 변수를 계속 이동하며 확인하는 방법이 있다. 
    겹치지 않으면 더해주는 형식으로 설계해야한다. 
*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;

int n, ans = 0;
vector<pair<ll,ll> > v;

int low(int num){
    int lt = 0, rt = v.size()-1;
    if(v.size() == 0 || v[v.size()-1].second < num) return n+1;
    while(lt < rt){
        int mid = (lt + rt)/2;
        if(v[mid].second >= num) rt = mid;
        else lt = mid +1;
    }

    return rt;
}

int main(){


    cin >> n;

    for(int i = 0; i<n; i++){
        int a,b;
        cin >> a >> b;
        int idx = low(a);

        if(idx > n || idx == -1){
            v.push_back({a,b});
        }
        else {
            int var = v[idx].second;
            v[idx].second = max(var,b);
        }

    }

    for(int i = 0; i<v.size(); i++){
        ans += (v[i].second - v[i].first);
    }
    cout << ans << "\n";
}

// int main() {
// 	FIO;
// 	int n, ans = 0;
// 	cin >> n;
// 	int l, r; l = r = -1e9 - 1;
// 	FOR(i, 1, n) {
// 		int a, b; cin >> a >> b;
// 		if (a > r) {
// 			ans += (r - l);
// 			l = a, r = b;
// 		}
// 		else r = max(r, b);
// 	}
// 	ans += (r - l);
// 	cout << ans << '\n';
// 	return 0;
// }