#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/*
  
  조건
  정수 a를 b로 바꾸려고 한다. 가능한 연산은 다음과 같은 두가지이다.
  2를 곱한다.
  1을 수의 가장 오른쪽에 추가한다.
 
  설계 
  2로 나눈다
  1이 나오면 1을 뺀다. 
  단순 그리디를 통해서는 구현하지 못함 2로 나눠지면 나누고 1이 나오면 1을 10으로 나누는 그리디

  디버그 
  탐색 || dp를 사용해서 풀어야할거 같은데
  dp를 이용해서 풀었다. 
  우선 dp배열을 만들어야 한다. 하지만 10억이고 어느정도 배열을 사이즈를 잡아야할지 모르겠다면 
  map을 사용하자 

  dp를 통해서 탐색을 진행한다. 


*/

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;

ll A, B;

map<ll,ll> dp;

ll solve(ll n, ll c){
    if( n > B) return INF;
    if(n == B) return c;
    ll &ret = dp[n];
    dp[n] = c;
    if(ret != 0) return ret;
    return ret = min(solve(n*2, c+1), solve(n*10 + 1, c+1));
}

int main(){

    cin >> A >> B;
    map<ll, ll> d;


    ll result = solve(A,1);
    if(result == INF ) cout << "-1";
    else cout << result;

}