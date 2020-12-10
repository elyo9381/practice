#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
	백트래킹은 dfs에서 레벨단위로 탐색하며 포문을 이용하여 마지막 노드를 확인한다.
	재귀 하는 순간에서 loop를 이용해야한다.
	dfs는 인덱스가 되어야하고 배열의 값은 loop로 통제한다. 
*/

int n,m;
int si[110],ch[110];

void pr(){
	for(int i = 1; i<=m; i++){
		for(int j = 1; j<=n-4 ; j++){
		}
		cout << endl;
	}
}

void re(int start, int L){
	if(L==6){
		for(int i = 0; i<6; i++){
			// if( ch[i]!=0 ){
				cout << ch[i] << " ";
			// }
		}
		cout <<"\n";
		return;
	} else {
		// 재귀에서 loop를 돌리기 때문에 첫인덱스에 1-7까지 나올수있다. 
		// 이를 방지하기 위한 if문이 존재한다. 
		for(int i = start; i<n; i++){
			if(ch[L-1] <= i){ // 역순으로 나오는것을 방지한다.
			ch[L] = si[i];
			re(start+1,L+1); 
		 	}
		}
	}
	return ;
}
int main(void){

	int num;
	cin >> n;
	for(int i = 0; i<n; i++){
			cin >> num;
			si[i] = num;
	}

	re(0,0);

	// pr();
	return 0;
	
}
 