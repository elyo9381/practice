#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <string>
#define endl '\n'
using namespace std;

int arr[100][100];

void Print(int n){
	for(int i = 0 ; i <n ; ++i){
		for(int j = 0; j<n; j++){
			cout << arr[i][j]<< " ";
		}
		cout <<endl;
	}
}

void zigzeg(int n){
	int x = 0, y = 0,i,j,a=1,c=1;
	for(i = 0; i<n; i++){
		for(j = 0 ; j<c; j++)
			arr[x++][y--] = a++;
		y++;

		if(i==n-1) break;
		if(i>=n/2) {x--;y++;c--;}
		else c++;

		for(j =0; j<c; j++)
			arr[x--][y++] = a++;
		x++;
		if(i>=n/2) {x++;y--;c--;}
		else c++;
	}
}

int re(int n, int x, int y,int ct){
	if(cnt > n*n) return 0;
	if(arr[x][y]==0 && x<n && y<n && x>=0 && y>=0 && cnt<=n*n){
		if(ct == 1){
			arr[x][y] = cnt++;
			re(n,++x,--y,ct);
		}
		if(ct == 2){
			arr[x][y] = cnt++;
			re(n,--x,++y,ct);
		}
	} else {
		if( ct == 1){
			if(cnt<=(n*n)/2){
				re(n,x,++y,2);
			} else re(n,++x,y+2,2);
		} else{
			if(cnt<=(n*n)/2){
				re(n,--x,y,1);
			} else re(n,x+2,--y,1);
		}
	}
	return 0;
}

void Input(int n){
	cin >> n ;
}

int main(){

	int n;
	cin >> n;
	// Input(n);
	zigzeg(n);
	Print(n);
	return 0;
}

