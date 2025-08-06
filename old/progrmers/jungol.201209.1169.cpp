#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int sum =1;

int n,m,cnt=0;
int num[5];

// 재귀를 통해서 +1증가 순열 구하는법은 파라미터를 0으로 받고 파라미터를 배열의 인덱스로 사용한다.
// 재귀함수에는 for문을 통해서 배열값을 넣는다.
// 중복되지 않게하는것은 재귀 들어가기전에 num[a-1] <= i 조건 또는 미리 한번 검사하여 같은 값이 있으면 탈출하는 방법이다. 


int three(int a){
	int i , j,f, k ;
	for(i = 1; i<=6; i++){
		f = 0;
		for(k =0; k<n;k++){
			if(num[k] == i){
				f = 1;
				break;
			}
		}

		if(f == 0){
			num[a] = i;
			if(a < n-1)
				three(n,a+1);
			else{
				for(j = 0; j<n; j++)
					cout << num[j];
				cout << endl;
			}
		}
	}
	return 0;
}

int two(int a){
	int i,j;

	for(i = 1; i<=6; i++){

		if(num[a-1] <=i){
			num[a] = i;

			if(a < n-1) two(a+1);
			else {
				for(j = 0; j<n; j++)
					cout << num[j] << " ";
				cout <<endl;
			}
		}
			
	}
	return 0;
}
int one(int a){
	int i,j;

	for(i = 1; i<=6; i++){
		num[a] = i;
		if(a >= n-1){
			for(j = 0; j<n; j++)
				cout << num[j] << " ";
			cout <<"\n";
		} else {
			one(a+1);
		}
	}
	return 0;
}
int main(void){

	cin >> n;
	switch(m)
    {
        case 1:
            one(0);
            break;
 
        case 2:
            two(n, 0);
            break;
 
        case 3:
            three(n, 0);
            break;
    }
	return 0;
}
 