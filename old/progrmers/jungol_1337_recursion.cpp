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
	for(int i = 0 ; i <tmp ; ++i){
		for(int j = 0; j<=i; j++){
			cout << arr[i][j];
		}
		cout <<endl;
	}
}




int re(int x, int y, int a, int num, int br)
{
	if( x < n && x>=0 && y<n && y>=0 && arr[x][y]==-1){
		arr[x][y] = a % 10;
		if(num==1)
			re(++x,++y,++a,num,0);
		if(num== 2)
			re(x,--y,++a,num,0);
		if(num==3)
			re(--x,y,++a,num,0);
	} 
	else 
	{
		if(br>0) return 0;
		else if(num == 1) 
			re(x-1,y-2,a,2,br+1);
		else if(num == 2) 
			re(x-1,y+1,a,3,br+1);
		else if(num == 3) 
			re(x+2,y+1,a,1,br+1);
	}
	return 0;
}
void mainfo(){
	int m = 0;
	while(arr[x][y] == -1){
		
		for(;x<n; x++){
		if(arr[x][y]!=-1) break;
		arr[x][y++] = (c++) % 10;
		}
		x--;
		y-=2;
		if(arr[x][y]!=-1) break;
		
		for(;y>=m; y--){
			if(arr[x][y]!=-1) break;
			arr[x][y] = (c++) % 10;
		}
		x--;
		y++;
		if(arr[x][y]!=-1) break;
		
		for(; x>m; x--){
			if(arr[x][y]!=-1)
				break;
			arr[x][y]=(c++)%10;
   		 }
		x+=2;
		y++;
	}
}

void Input(void){
	cin >> n ;
	tmp = n;
	for(int i = 0; i<n; ++i){
		for(int j = 0; j<=i;++j){
			arr[i][j] = -1;
		}
	}
}

int main(){


	Input();
	//re(0,0,0,1,0);
	mainfo();
	Print();
	return 0;
}



