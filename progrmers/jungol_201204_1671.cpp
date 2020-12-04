#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int squ[102][102];

int countf(int x, int y){
	int cnt = 0;

	if(squ[x+1][y] == 0) cnt++;
	if(squ[x-1][y] == 0 )cnt++;
	if(squ[x][y+1] == 0) cnt++;
	if(squ[x][y-1] == 0) cnt++;
	return cnt;
}

int line(void){
	int sum = 0, i, j;

	for(i = 1; i<101; i++){
		for(j = 1; j<101; j++){
			if(squ[i][j] == 1)
			  sum +=countf(i,j);
		}
	}
	return sum;
}

int main(){

	int n,sum = 0,m[2];

	cin >> n;
	while(n--){
		cin >> m[0] >> m[1];
		for(int i = m[0]; i<(m[0]+10); i++){
			for(int j = m[1] ; j<(m[1]+10); j++){
				if(squ[i][j] == 0){
					squ[i][j] =1;
				}
			}
		}
	}

	sum = line();
	cout << sum ;
	return 0;
}