#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
한쪽에만 추를 올려놓을 수 있는 양팔저울과 1, 2, 4, 16 그램의 추가 각각 10개씩 주어진다.
89 그램 물체를 측정하는데 최소 추의 개수는 몇개일까?

고찰
큰수부터 반복해서 빼서 답에 접근함
큰수부터 빼므로  현재 최적의 선택이고 빼는수가 점점 작아져 최적해에 도달한다.

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

	int cho[5];

	for(int i = 0; i<5; i++){
		int num ;
		cin >> num;
		cho[i] = num;
	}
	cin >> n;

	if(cho[0] == 0 ) cout << "impossible"<<endl;

	int total = 0,tmp = n;
	int k = 1;
	for(int i =4; i>=0; i--){

		if(cho[i] !=0){
			while( (1<<i) <= tmp){
				// cout << i<< ":" <<tmp << " " ;
				tmp -=(1<<i);
				total++;
				cho[i]--;
			}
			// cout <<endl;
		}

	}
	
	cout << total <<endl;
	// re(n);
	// pr();
	return 0;
	
}
 