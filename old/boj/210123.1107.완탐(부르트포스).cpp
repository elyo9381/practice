#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;
#define hash 1000000007LL;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 100001;

/*
	풀지 못하고 구글링 하였다..

	나름 고민 하긴했었다. 
	처음엔 각 자리수마다 사용가능 여부를 체크하여 가능하면 사용하고 사용할수없을땐 사용가능한 것이 나올때까지
	투포인터 느낌으로 찾아가 최소의 값을 사용하고 이를 체크 하려고 하였다. 

	하지만 이러한 문제는 500이고 0,1을 사용하지 못할때 발생한다. 499+1이 가장 짧은 경우인데 내경우는 522의
	경우를 리턴하니 ... 문제점이 발생하였고 이를 해결치 못하여 구글링 하였다. 

	고장난 버튼이 눌렸다는건 생성할수없는 채널임을 접근하지 못하였다. 

*/

int n, m, broken[10];

int len(int x)
{
	stringstream ss; ss << x;
	string str; ss >> str;
	return str.size();
}

bool canGo(int x)
{
	stringstream ss; ss << x;
	string str; ss >> str;
	for (int i=0; i<str.size(); ++i)
		if (broken[str[i]-'0']) return false;
	return true;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i)
	{
		int ti;
		cin >> ti;
		broken[ti] = 1;
	}

	int lclosest, rclosest;

	// 가까운 수들 중 고장난 버튼을 사용치 않고 갈수있는 채널 확인
	// 채널은 무한대에 가까이 존재하므로 오십만이 넘는 채널또한 눌러서 갈수있고 
	// 틀수있는 채널제한이 오십만인것이다. 
	for (lclosest=n; lclosest>=0; --lclosest)
		if (canGo(lclosest)) break;
	for (rclosest=n; rclosest<=1000000; ++rclosest)
		if (canGo(rclosest)) break;

	// 100번의 채널에서 100으로 가려고 할수있으니 abs를 진행함
	// 고장난 버튼을 사용치 않고 갈수있는 채널의 길이와 요구채널의 차이를 구해 cnt를 구한다. 
	int ans = abs(n-100);
	if (lclosest >= 0)
		ans = min(ans, abs(n-lclosest)+len(lclosest));
	if (rclosest <= 1000000)
		ans = min(ans, abs(n-rclosest)+len(rclosest));

	cout << ans;
}