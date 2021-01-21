#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
#include <cstring>

using namespace std;
#define hash 1000000007LL;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 100001;

int d[1000000];

//반복적으로 중복된 값이 나오므로 dp를 생각해야한다. 

int main(){

	int n;

	cin >> n;

	for(int i = 2; i<=n; i++){
		d[i] = d[i-1] +1;
		if(i%2==0) d[i] = min(d[i],d[i/2]+1);
		if(i%3==0) d[i] = min(d[i],d[i/3]+1);
	}
	cout << d[n] <<'\n';
}