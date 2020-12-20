#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*

 g는 최대공약수 l은 최소공배수임으로 이를 만족하는 수를 찾는건 
 공약수의 1배 2배 3배... n배 까지임을 알아냈었다. 
 이를 통해서 각 순서마다 두 값의 최소값을 비교하려고 하였다. 

 물론 이방법으로도 풀린다. 하지만 조금더 복잡하게 생각해보면
 출력의 예시또한 최대공약수가 g임으로 이를 한번더 확인해서 최대공약수가 같은지 확인해주는게 좋을거같다.
 물론 똑같이 n의 시간복잡도를 가지지만 조금더 정확하게 할수있다.
*/


int gcd(int a, int b){return b? gcd(b, a%b):a;} 

int main(){

	long long g,l,i,j,k,x,y,tmp;

	cin >> g >> l;
	tmp = g*l;
	if(g == l)
	{
		cout << g << l <<'\n';
	}

	for(i = g; i<l; i+=g){
		j = tmp/i;
		if(i>j) break;
		k = gcd(i,j);
		if(k == g && (i/k*j) == l){
			x = i;
			y = j;
		}
	}

	cout <<  x <<" "<< y  <<'\n';
}