#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int squ[100][100];

int square(int *m){
	int i, j , c=0;
	for(i = m[0]; i<(m[0]+10); i++){
		for(j = m[1] ; j<(m[1]+10); j++){
			if(squ[i][j] == 0){
				squ[i][j] =1;
				c++;
			}
		}
	}
	return c;
}

int main(){

	int n,sum = 0,m[2];

	cin >> n;

	for(int i = 0; i<n; i++){
		cin >> m[0] >> m[1];
		sum+=square(m);

	}
	cout << sum ;
	return 0;
}