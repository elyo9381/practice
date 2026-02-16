#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
 정렬후 a[L].e >= a[L+1].s && a[L].y != a[L+1].y을
 통해서 조건에 맞게 탐색한다. 
 이를 재귀로 풀든 루프로 풀든 상관없다.
*/

struct wood{
	int s, e, y;

	wood(int a, int b, int c){
		s = a;
		e = b;
		y = c;
	}
	bool operator<(const wood &r)const{
		if(s == r.s) return s < r.s;
		return e < r.e;
	}
};

int re(vector<wood> a,int s, int e, int L){
	int sum = 0;
	if(e == L){
		return 1;
	} else { 
		if(a[L].e >= a[L+1].s && a[L].y != a[L+1].y){
			sum +=re(a,s,e,L+1);
		} 
	}
	return sum;
}


int main(){
	int n, q;

	cin >> n >> q;
	vector<wood> a;
	for(int i = 0; i<n; i++){
		int x1,x2,y;
		cin >> x1 >> x2 >> y;
		a.push_back(wood(x1,x2,y));
	}
	sort(a.begin(), a.end());

	for(int i = 0; i<n; i++){
		cout << a[i].s << a[i].e << a[i].y<< "\n";
	}
	for(int i= 0; i<q; i++){
		int w1,w2;
		cin >> w1 >> w2 ;
		cout << re(a,w1-1,w2-1,0) << "\n";
	}
}