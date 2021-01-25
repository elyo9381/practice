#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
#define hash 1000000007LL;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 100001;

int board[129][129];
int n, cnt0 = 0,cnt1= 0 ;

void div_conq(int n, int x, int y){
	
	int tmp_cnt = 0;
	for(int i = x; i<x+n; i++){
		for(int j = y; j< y+n; j++){
			if(board[i][j]) tmp_cnt++;
		}
	}

	if(!tmp_cnt) cnt0++;
	else if( tmp_cnt == n*n) cnt1++;
	else {
		div_conq(n/2, x, y);
		div_conq(n/2, x, y + n/2);
		div_conq(n/2, x + n/2, y);
		div_conq(n/2, x + n/2, y + n/2);
	}	
	return ;
}

int main(){


	int n;
	cin >> n;
	for(int i= 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> board[i][j];
		}
	}

	div_conq(n,0,0);
	cout << cnt0  << '\n' << cnt1 << '\n';
}