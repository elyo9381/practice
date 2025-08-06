#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 100005
using namespace std;

int n,m,t,k;
int mod = 10007;
int a[MAXN];

int BinarySearch(int target, int len){
    int st = 0;
    int en = len -1;
    while(st<=en){
        int mid  = (st+en)/2;
        if(a[mid]< target)
            st = mid+1;
        else if(a[mid] > target)
            en = mid-1;
        else
            return mid;
    }
    return -1; // st > en 일 경우 whlie문을 탈출함
}
void Input()
{   
  cin >> n;
  for(int i = 0; i<n; i++)
    cin >> a[i];
  
  sort(a, a+n);
}

void Solution()
{
  
  cin >> m;
  while(m--){
    cin >> t;

    if(BinarySearch(t,n) == -1) cout<< "0\n";
    else cout<<"1\n";
  }
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
