
/*카운팅솔트로 정렬하였다. */


#include <bits/stdc++.h>
using namespace std;
int cnt[2000001];


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    cnt[a+1000000]++;
  }
  for(int i = 0; i <= 2000000; i++){
    while(cnt[i]--){ // cnt[i]번 반복
      cout << i-1000000 << '\n';
    }
  }

  return 0;
}