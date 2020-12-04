#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <string>


#define endl '\n'
using namespace std;

int n,m;
char arr[100][100];

void Print(){
	for(int i = 1 ; i <=n ; ++i){
		for(int j = 1; j<=n; j++){
			if(arr[i][j]=='\0'){
				cout << " ";
			}
			cout << arr[i][j];
		}
		cout <<endl;
	}
}

void fill_string(){
	int i, j, k;
	char alpha = 'A';
	for(i = 1; i<=n; i++){
		for( j = i, k = n; j<=n ; j++, k--){
			arr[j][k] = alpha++;
			if(alpha > 'Z')
				alpha = 'A';
		}
	}
}

void Input(){
	cin >> n ;
}

int main(){

	Input();
	fill_string();
	Print();

	return 0;
}