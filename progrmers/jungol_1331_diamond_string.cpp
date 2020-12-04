#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <string>
#define endl '\n'
using namespace std;

char arr[100][100];

char make_num(){
    static int a=0;   
    char b;
    b=((a++)%26)+'A';
    return b; 
}

void Print(int n){
	for(int i = 0 ; i <2*n ; ++i){
		for(int j = 0; j<2*n; j++){
			if(arr[i][j]=='\0'){
				cout<<"  ";			
			}
			else cout << arr[i][j]<< " ";
		}
		cout <<endl;
	}
}

void square(int n){
	int x = 0, y= n-1, c1 = 1, c2 = n,i;

	for(i = 0; i<n; i++){
		while(x<c2) arr[x++][y--] = make_num();
		y+=2;

		while(x<(2*c2)-c1) arr[x++][y++] = make_num();
		x-=2;

		while(y<(2*c2)-c1) arr[x--][y++] = make_num();
		y-=2;

		while(y>=c2) arr[x--][y--] = make_num();
		x++;
		c1++;
	}
}


void Input(int n){
	cin >> n ;
	for(int i = 0 ; i <=2*n ; ++i){
		for(int j = 0; j<=2*n; j++){
			arr[i][j] = -1;
		}
	}
}

int main(){

	int n;
	cin >> n;
	// Input(n);
	square(n);
	Print(n);
	return 0;
}

