#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
	그리디는 현재상황에서 지금당장 좋은것만 고르는방법
 	큰수의법칙 
	다음과 같이 입력될때 n,m,k 입력될때 
	가장큰수가 k번 더할수 없다는 조건이 있는 그리디 문제이다.
	
	
	입력
	6 8 3 
	1 4 3 5 6 4

	ex 6+6+6+5+6+6+6+5 = 46이된다. 
	출력 
	46

	loop를 통해서도 풀수있는데 더 나은 방법은 6665,6665와 같이 
	순열이 보인다. 2번의 반복 하나의 반복길이는 K+1이고 즉 m/k+1이고
	여기에 *k를 하면 가장 큰수의 총 반복 횟수가 나온다. 

	m - cnt 하면 2번째로 큰수를 더한 횟수가 나오고 이를 통해서 시간복잡도를
	N^2이 아닌 N으로 바꿄수있다. 

*/
 
int main() { 

	int n,m,k,f,s,cnt=0;
	cin >> n >> m>> k;
	// int count[1000000];
	int *data = new int[n];
	for(int i = 0; i<n; i++){
		int num;
		cin >> num;
		data[i] = num;
	}
	sort(data,data+n);
	f = data[n-1];
	s = data[n-2];

	cnt = (m / (k+1)) * k ;
	cnt += m %(k+1);

	int res = 0;
	res += cnt * f;
	res += (m-cnt) * s;
	
	cout << res <<endl;
}
