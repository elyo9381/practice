#include <bits/stdc++.h>
using namespace std;





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
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int m,n,x,y;
    cin >> m >> n >> x >> y;
    cout << solve(m,n,x,y) << '\n';
  }
}