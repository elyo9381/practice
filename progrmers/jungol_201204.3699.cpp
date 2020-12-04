#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// 모자 3, 겉옷 2, 하의 2개를 한번씩면 걸쳐서 입는 경우의수
// (3+1) * (2+1) * (2+1) -1 아무것도 안걸치는경우를 뺀것이다.
// 변장은 이러한 수학적 개념으로 접근했다면 더욱빨리 풀었을것이다.
// 나는 dfs를 통해서 푸려고 하니 매우 오래걸렸다. 물론 못풀었고 

int main(){
	int t, n;
	cin >>t;
	while(t--){

		vector<pair<string,int> > v;
		cin >> n;
		int res = 1;
		while(n--){
			string name, kind;
			bool dup = false;

			cin >> name >> kind;
			if(v.empty()) v.push_back(make_pair(kind,1));
			else{
				for(int i = 0 ; i<v.size(); i++){
					if(v[i].first == kind){
						dup = true;
						v[i].second++;
					}
				}
				if(!dup) v.push_back(make_pair(kind,1));
			}
		}

		for(int i = 0; i<v.size(); i++){
			res *= (v[i].second +1);
		}

		cout << res -1 << '\n';

		v.clear();
	}
	return 0;
}