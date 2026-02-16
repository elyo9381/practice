#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
	combination은 stl을 이용해서 풀수도 있고 재귀를 이용해서 풀수있다.
	재귀에서 가장 중요한것은 
	if(ch[L-1] < i){
		ch[L] = i;
		re(L+1);
	}
	위의 코드 내용이다.

	dfs즉 레벨을 타고 내려가면서 순열을 구하는데 L이 0-2까지는 재귀가 된다.
	이때 재귀는 레벨을 타고가며 순열을 구상하는 loop를 가지고 간다.
	ch[L-1] < i 레벨의 배열값보다 높은 값을 패스하는 방식이다.
*/

int n,m, flag = 0,cnt = 0,i,idx = 0;
int si[110],ch[110], val[110][110]; 

void pr(){
	for(int k = 0; k<i; k++){
		cnt = 0;
		for(int j = 0;j<m; j++){
			// cout << val[k][j] << " ";
			if(val[k][j] == si[j]){
				cnt++;
			}
		}
		// cout <<"\n";
		if(cnt == m){
			flag = 1;
			idx = k;
		}
	}

	if(!flag){
		cout << "NONE";

	} else {
		for(int j = 0; j<m; j++){
			if(val[idx+1][j] == 0){
				cout << "NONE";
				break;
			}
			cout << val[idx+1][j] << " ";
		}
	}
}

void re(int L){
	if(L==m){
		for(int j = 0; j<m; j++){
				val[i][j] = ch[j];
				// cout << val[i][j] << " ";
		}
		// cout <<endl;
		i++;
		return;
	} else {
		for(int i = 1; i<=n; i++){

			// int aa = 0;
			// for(int j = 0; j<m; j++){
			// 	if(val[j] == i){
			// 		aa = 1;
			// 		break;
			// 	}
			// }

			if( ch[L-1] < i){
			ch[L] = i;
			re(L+1);
		 	}
		}
	}
	return ;
}


int main(void){
	int num;
	cin >> n >> m ;

	for(int i = 0; i<m; i++){
		cin >> num;
		si[i] = num;
	}
	re(0);
	pr();
	return 0;
}
 