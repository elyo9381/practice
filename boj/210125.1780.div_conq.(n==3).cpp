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


int n , cnt=0,cnt0=0,cnt1=0;
int board[3000][3000];

void div_conq(int n, int x, int y){

	
	bool minus = true, zero = true, plus = true;
	for(int i = x; i< x+n; i++){
		for(int j = y; j< y+n; j++){
			if(board[i][j] == -1){
				plus = false;
				zero= false;
			} else if( board[i][j] == 0){
				minus = false;
				plus= false;
			} else {
				minus= false;
				zero=false;
			}

		}
	}

	if(zero) cnt0++;
	else if(plus){
		cnt1++;
	} else if(minus){
		cnt++;
	} else {

	div_conq(n / 3, x, y);
	div_conq(n / 3, x, y+n/3);
	div_conq(n / 3, x, y+2*(n/3));

	div_conq(n / 3, x+(n/3), y);
	div_conq(n / 3, x + (n/3), y+(n/3));
	div_conq(n / 3, x +(n/3), y+2*(n/3));
	
	div_conq(n / 3, x+2*(n/3), y);
	div_conq(n / 3, x+2*(n/3), y+(n/3));
	div_conq(n / 3, x+2*(n/3), y+2*(n/3));

	}
	return ;
}

int main(){

	cin >> n;

	for(int i = 0; i<n; i++){
		for(int j = 0 ;j <n; j++){
			cin >> board[i][j];
		}
	}

	div_conq(n,0,0);

	cout << cnt <<"\n"<< cnt0<<"\n"<< cnt1<<"\n";
}