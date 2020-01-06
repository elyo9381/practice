#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

/**/   

int factorial(int n)
{
     int total = 1;
     while(n != 0) // n의 수만큼 팩토리얼 계산
     {
          total *= n; // 5! = 5* 4* 3* 2* 1 
          n--;
     } 
     return total; // total값 리턴
}

int main()
{
    // int t;
    // int total = 0;
    // cin >> t;

    // total =  factorial(t);
    // cout<<total<<endl;
    int ans = 0;
    int n;
    cin >> n;
    
    for (int i=5; i<=n; i*=5)
        ans += n/i;
        
    cout << ans << '\n';
}