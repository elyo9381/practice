#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
 어떤수 n이 1이 될 때까지 다음의 두 과정중 하나를 반복적으로 선택하여 수행하려고 한다.
 단, 두번째 연산은 n이 k로 나누어 떨어질때만 선택할수있다.
 1. n에서 1을 뺀다
 2. n을 k로 나눈다.


 입력 
 25 5

 출력 
 2

 나는 n!=1 아닐때 루프를 돌리고 n%k==0이면 2수행
 아니면 조건 1수행 으로 풀었다. 
 물론 이렇게 해도 풀리지만 	n<=100억이면 풀리지 않는다.
 100억일때도 풀리게 하려면 조건 1수행을 한번에 수행해야한다.
 어떻게 1식빼는것을 한번에 할수있을까?
 답은 n을 k의 배수로 만들어주는것이다. k의배수에서 n과 거의 비슷한값을 
 구하여 n-(k의배수에서 n과 거의 비슷한값) 해준다면 1씩 빼는것을 한번에 할수있다.
*/

int arr[100][100];

int main(){

	int n, m;
	int res = 0
	cin >> n >> m;
	
	while(true){
		tmp = (n/k)*k;
		res += (n-tmp);
		n = tmp;
		if(n < k) break;
		else {
			n /=k;
			res+=1;
		}
	}
	res += (n-1);
	cout << res <<'\n';
}

}