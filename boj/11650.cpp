#include <bits/stdc++.h>
using namespace std;

int t;
struct Pt{
	int x;
	int y;
};


bool comp(const Pt &s1,const Pt &s2){
	if(s1.x < s2.x) return true;
	else if( s1.x== s2.x) return s1.y < s2.y;
	else return false;
}


/*
	bool comp(const vector<pari<int,int> > a, const vector<pair<int,int> > b){
		if(a.x < b.x) return true;
		else if( a.x == b.x) return a.y < b.y;
		else return false;
	}
	vector<pair<int,int> > pt(100001,0);
	for(int i = 0; i<t; i++) {
		int a,b;
		cin >> a >> b;
		pt[i] = make_pair(a,b);
	}
	sort(pt.begin(),pt.end(),comp);
	for(int i = 0; i<t; i++) cout << pt[i].first << " " <<pt[i].second <<"\n";
*/ 

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;


	Pt *point = new Pt[t];

	for(int i = 0; i<t; i++){
		cin >> point[i].x >> point[i].y;
	}

	sort(point, point+t,comp);

	for(int i = 0; i<t; i++){
		cout << point[i].x << " "<< point[i].y << "\n";
	}

}


/*
입력예제
5
3 4
1 1
1 -1
2 2
3 3
출력예제
1 -1
1 1
2 2
3 3
3 4
*/ 