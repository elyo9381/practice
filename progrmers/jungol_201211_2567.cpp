#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
	25->1->5가 반복된다는것은 이를 배열인덱스를 카운트하고 배열값이 2가 되면 반복되었다는뜻이니
	배열값이 2인 녀석들을 출력한다. 

	재귀는 2일때 탈출하는 기저조건으로 한다.
*/

int n,p, flag = 0,cnt = 0,i,idx = 0;
int si[110],ch[1101], val[110][110]; 

void pr(){
	for(int i = 0; i<p; i++){
		if(ch[i] == 2) cnt++;
	}
	cout <<cnt <<"\n";
}

void re(int x){
	
	if(ch[x] == 2) return;
	ch[x]++;
	re((x*n)%p);
}


int main(void){
	int num;
	cin >> n >> p ;

	re(n);

	pr();
	return 0;
}
 