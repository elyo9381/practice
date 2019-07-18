#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// int  d[1001];

// int dp(int x){
// 	if(x == 0) return 1;
// 	if(x == 1) return 1;
// 	if(x == 2) return 2;
// 	if(d[x] != 0) return d[x];
// 	return d[x] = (dp(x-1) + dp(x-2)) % 10007;
// }


int main(){
    int cnt;
    int n, m, mok, Mod,c,Pac[51]={0},each[51]={0};
    int result;
    cin >> n >> m;
	for (int i = 0; i < m; ++i)
		{
			cin >> Pac[i] >> each[i]; 
				//cout<< Pac[i] <<endl;
		}

	sort(Pac, Pac+m);
	sort(each, each+m);

	// n이 패키지보다 작을때와 클때 
	// 클때는 나머지가 0일때 아닐때를 구분한다.
	// 낱개로 사는것보다 패키지 2개로 살때 더 쌀때가 있따. 
	if(n<6)
	{
		cout << min(Pac[0],each[0]*n) << endl;
	}
	else
	{

		if(n%6==0)
		{
			cout<< min(Pac[0]*(n/6), each[0]*n)<<endl;

		}
		else
		{
			c=min(Pac[0]*(n/6)+each[0]*(n%6),each[0]*n);
            cout<< min(c,Pac[0]*(n/6+1)) <<endl;


            cout << c <<endl;

		}
	}
}

