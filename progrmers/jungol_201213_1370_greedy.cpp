#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

끝나는 시간으로 정렬해서 시작시간과 비교하여 cnt체크하여 푼다.ㄴ
*/



class op{
	public:
	bool operator()(const pair<int,pair<int,int> > &a, const pair<int,pair<int,int> > &b){
		// if(a.first == b.first) return a.second < b.second;
		return a.second.second < b.second.second;
	}
};



int main(void)
{
	int n;
	cin >> n;
	vector<pair<int,pair<int,int> > > mt(n+1);
	vector<int> a;

	for(int i = 1; i<=n; i++){
		int a,b,c;
		cin >> a >> b>> c;
		mt[i] = make_pair(a,make_pair(b,c));
	}

	sort(mt.begin(), mt.end(),op());

	int cnt = 0,i, j;

	for(j = 1; j<=n; j++){
		// cout << mt[j].second.first << " : "<< mt[j].second.second<< endl;
		for( i = j+1; i<=n; i++){
		// cout << " j : " <<j << endl;
			if(mt[j].second.second < mt[i].second.second 
			&& mt[j].second.second <= mt[i].second.first 
			&& mt[j].second.first < mt[i].second.first){
				cnt++; 
				a.push_back(mt[j].first);
				j = i-1;
				break;
			}
		}
		if(j == n) {
			a.push_back(mt[j].first);
			cnt++;
		}
	}

	cout << cnt<<endl;
	for(int it = 0; it<cnt; it++){
			cout << a[it] << " ";
	}

	return 0;
	
}
 