#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 100001
using namespace std;

int N, K;

vector<int> v;
bool isPrime1(int n)
{
    if(n==1) return false;
    for(int i = 2; i< n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

bool isPrime2(int n)
{
    if(n==1) return false;
    for(int i =2 ; i*i<n; i++){
        if(n%i ==0) return false;
    }
    return true;
}

// 시간은 에라스토 체네스와 비슷하나 메모리를 13~40 배 더 먹음 
vector<int> allPrime1(int n )
{
    vector<int>ret;
    for(int i =1; i<=n;i++){
        if(isPrime2(i)) ret.push_back(i);
    }
    return ret;
}

// 에라스토체네스 방법이고 allPrime1 보다 메모리 효율적으로 절약
/*
    최적화
    1. i<=n에서 i*i<=n으로
    2. j = i*2에서 i*i
    3 int state[n] 에서 vector<bool> state
    int 배열을 칸당 4바이트
    bool배열을 1바이트
    vector<bool> 칸당 1비트
*/


vector<int> allPrime2(int n){
    vector<int> ret;
    vector<bool> state(n+1,true);
    state[1] = false;
    for(int i =2; i*i<=n; i++){
        if(!state[i]) continue;
        for(int j = i*i; j<=n; j += i) state[j] = false;
    }
    
    for(int i = 1; i<= n ; i++){
        if(state[i]) ret.push_back(i);
    }

    return ret;
}

// 소인수 분해
void soinsu(int n){
    for(int i = 2; i*i <= n; i++){
        while(n % i == 0){
            cout<< i<< endl;
            n/=i;
        }
    }
}

vector<int> division(int n)
{
    vector<int> ret;
    for(int i =1; i*i <= n; i++){
        if(n%i == 0) ret.push_back(i);

    }

    for(int i = ret.size()-1; i>=0; i--){
        if(ret[i]*ret[i] == n )continue;
        ret.push_back(n/ret[i]);
    }
    return ret;
}

// 최대 공약수
int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b){
    return a*b / GCD(a,b);
}

/*
    약수와 최대 공약수성질
    1. 두수 A, B의 공약수들은 GCD(A,B)의 모든 약수들이다.
    2. 두수 A, B의 공배수들은 LCM(A,B)의 모든 배수들이다.
    3. AXB =  GCD(A,B) X LCM(A,B)
    4. GCD(n,n+1) = 1

    성질 3을 이용해 LCM(A, B)를 A X B / GCD(A,B)로 구할수 있습니다. 
    성질 4는 보고 바로 까먹어도 아무 상관 없습니다.
*/ 


/*
    합동식

    A≡B(modm) 이라는 기호의 의미는 A와 B가 M으로 나눈 나머지가 같다는 의미입니다.

    A≡B(modm) 일때

    1. A + C  ≡ B+C(modm)
    2. A-C ≡ B-C(modm)
    3. AC≡BC(modm)
    4 그러나  A/C ≡ B/C(modm)은 성립하지 않는다. . ( A=6, B=2, C=2, M=4A=6,B=2,C=2,M=4 )

    cin >> a >> b;
    int anc = (a-b)%mod;
    if(ans < 0) ans+=mod; // 음수일땐 이렇게 해줘야한다. 
    cout<< "result : " << ans;
*/


/*
LCM을 이용해서 풀이 시간복잡도는 O(MN)이다


int solve(int m,int n , int x, int y)
{
  if(x == m) x=0;
  if(y == n) y=0;
  for(int i = 1; i<=m*n; i++)
  {
    if(i%m == x and i%n == y)return i;
  }
  return -1;
}

  O(mn)에서는 시간초과가 뜬다 
  왜나면 M,N의 까지이므로 최대 16억까지이다.
  메모리는 256MB이므로 2.6억까지 할당이된다. 
  그렇기 떄문에 O(MN)은 안되고 
  O(M+N)으로 가야한다. 
  합동식으로 구할때 (A 합동식 X) 이므로 m이 계속적으로 증가할것이다.
  X, X+m, X+2m ... 그렇기에 i의 범위를 x부터 i+=m으로 해주게 되면
  X에 대한 m을 mn으로 확인하는게 아니라  O(N)번으로 확인하게 된다.   

*/

int solve(int m, int n, int x, int y){
  if(x == m) x = 0;
  if(y == n) y = 0;
  for(int i = x; i <= m*n; i+=m){
    if(i % n == y) return i;
  }
  return -1;
}`



void Input()
{   
    cin>> N >> K;
}
void Solution()
{   

    v = division(N);
    if( v.size() < K ) cout<< 0;
    else cout<< v[K-1]; 
}
void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}
