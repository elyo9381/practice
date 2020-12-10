#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

예를 들어보자. 기본 부품으로서 1, 2, 3, 4가 있다. 

중간 부품 5는 2개의 기본 부품 1과 2개의 기본 부품 2로 만들어진다. 

그리고 중간 부품 6은 2개의 중간 부품 5, 3개의 기본 부품 3과 4개의 기본 부품 4로 만들어진다. 

마지막으로 장난감 완제품 7은 2개의 중간 부품 5, 3개의 중간 부품 6과 5개의 기본 부품 4로 만들어진다. 

이런 경우에 장난감 완제품 7을 만드는데 필요한 기본 부품의 개수는 1번 16개, 2번 16개, 3번 9개, 4번 17개 이다.

입력예시
7
8
5 1 2
5 2 2
7 5 2
6 5 2
6 3 3
6 4 4
7 6 3
7 4 5


첫 수도코드 작성후 코드로 옮긴 작품이다. 
*/


int n,m;
int mpart[110][110],part[110],val[110];

void pr(){
	for(int i = 1; i<=m; i++){
		for(int j = 1; j<=n-4 ; j++){
			cout << mpart[i][j] << " " ;
		}
		cout << endl;
	}
}

void re(int a){
	// cout <<  "re in " <<a <<endl;
	if(n == a) val[n] = 1;
	if( a < 5){
		for(int i = 1; i<=a ; i++){
			cout << i << " : " << val[i] << endl;
		}
		return;
	} else {
		for(int i = 1; i<=m; i++){
			// cout << mpart[i][0] <<endl;
			if(mpart[i][1] == a){
				// cout << mpart[i][0] << val[mpart[i][1]] <<endl;
				val[mpart[i][2]] += val[a] * mpart[i][3];
			}
		}

		// for(int i = 1; i<=a ; i++){
		// 	cout <<a<<" "<< i <<" " << val[i] << endl;
		// }
		re(a-1);
	}
	return ;
}
int main(void){

	cin >> n >> m;
	for(int i = 1; i<=m; i++){
		for(int j = 1; j<=n-4 ; j++){
			int num;
			cin >> num;
			mpart[i][j] = num;
		}
	}

	re(n);

	// pr();
	return 0;
	
}
 