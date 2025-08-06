#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
#define INF 987654321
#define hash 1000000007LL
typedef long long ll;
typedef pair<int,int> pii;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

const int MAX = 10000;

int a,b;
bool v[MAX];

string BFS(){

	queue<pair<int,string> > q;

	q.push(make_pair(a,""));
	v[a] = true;

	while(!q.empty()){
		int num = q.front().first;
		string change = q.front().second;

		q.pop();

		if(num == b) return change;

		int curNum = (2*num) % MAX;
		if(!v[curNum]){
			v[curNum] = true;
			q.push(make_pair(curNum,change+"D"));
		}
		curNum = (num - 1) < 0 ? 9999 : num -1;
		if(!v[curNum]){
			v[curNum] = true;
			q.push(make_pair(curNum,change+"S"));
		}
		curNum = (num % 1000)*10 + num/1000;
		if(!v[curNum]){
			v[curNum] = true;
			q.push(make_pair(curNum,change+"L"));
		}
		curNum = (num%10 ) * 1000 + num/10 ;
		if(!v[curNum]){
			v[curNum] = true;
			q.push(make_pair(curNum,change+"R"));
		}
	}
	return "";
}

int main(){

	int t;
	cin >> t;

	for(int i = 0; i<t; i++){
		fill(v,v+10000,0);

		cin >> a >> b;

		cout << BFS() << '\n';
	}
}