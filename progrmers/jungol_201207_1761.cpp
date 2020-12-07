#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


int n[100000][4],cnt;

void pr(int m){
	int i, prcnt = 0;
	for(i = 0; i<cnt; i++)
	{
		if(n[i][3] == m){
			prcnt++;
		}
	}
	cout << prcnt;
}

void ab(int *a){
	int i,j,k,scnt,bcnt;

	for(i = 0; i<cnt ; i++){
		scnt = 0; 
		bcnt = 0;

		for( j =0; j<3; j++){
			if(n[i][j] == a[j]){
				scnt++;
			}
		}

		for(j = 0; j<3; j++){
			for( k = 0; k<3; k++){
				if(j!=k && n[i][j] == a[k])
					bcnt++;
			}
		}

		if(scnt == a[3] && bcnt==a[4]){
			n[i][3]++;
			cout <<n[i][0]<<n[i][1]<<n[i][2]<<endl;
		}
	} 
}

int set(void){

	int a=0;
	for(int i = 1; i<=9 ; i++){
		for(int j = 1; j<=9; j++){
			if(i!=j){
				for(int k = 1; k<=9; k++){
					if(k!=j && k!=i){
						n[a][0] = i;
						n[a][1] = j;
						n[a][2] = k;
						n[a++][3] = 0;
					}
				}
			}
		}
	}
	return a--;
}

int main(void){

	int m, a[5];

	cin >> m;
	cnt = set();
	for(int i = 0; i<m; i++){
		cin >> a[0] >> a[3] >> a[4];
		a[2] = a[0]%10;
		a[0] = a[0]/10;
		a[1] = a[0]%10;
		a[0] = a[0]/10;
		ab(a);
	}
	pr(m);
	return 0;
}