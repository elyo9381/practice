#include <bits/stdc++.h>
using namespace std;

int t;
struct Pt{
	int x;
	int y;
};


bool comp(const Pt &s1,const Pt &s2){
	if(s1.y< s2.y) return true;
	else if( s1.y == s2.y) return s1.x < s2.x;
	else return false;
}

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
0 4
1 2
1 -1
2 2
3 3
출력예제
1 -1
1 2
2 2
3 3
0 4
*/ 