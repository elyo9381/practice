#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <string>
#define endl '\n'
using namespace std;

int n;
int tmp ;
int x=0,y=0,a,num,br,c=0;
int arr[100][100];

void Print(void){
	for(int i = 0 ; i <n ; ++i){
		for(int j = 0; j<n; j++){
			cout << arr[i][j] << " ";
		}
		cout <<endl;
	}
}

int re(int x, int y, int a, int num, int br)
{
	if( x < n && x>=0 && y<n && y>=0 && arr[x][y]==-1){
		arr[x][y] = a;
		if(num==1)
			re(x,++y,++a,num,0);
		if(num==2)
			re(++x,y,++a,num,0);
		if(num==3)
			re(x,--y,++a,num,0);
		if(num==4)
			re(--x,y,++a,num,0);
	} 
	else 
	{
		if(br>0) return 0;
		else if(num == 1) 
			re(++x,--y,a,2,br+1);
		else if(num == 2) 
			re(--x,--y,a,3,br+1);
		else if(num == 3) 
			re(--x,++y,a,4,br+1);
		else if(num == 4) 
			re(++x,++y,a,1,br+1);
	}
	return 0;
}

void Input(void){
	cin >> n ;
	tmp = n;
	for(int i = 0; i<n; ++i){
		for(int j = 0; j<n;++j){
			arr[i][j] = -1;
		}
	}
}

int main(){


	Input();
	re(0,0,1,1,0);
	Print();
	return 0;
}



