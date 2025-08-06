#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

/* 팩토리얼의 0의갯수를 구하는것은 n의 2,5의 갯수를 알면 되는것이고
2,5의 계승의 최소값만 알면되는데 
이것은 직관적인 풀이 이다.
반복되는 과정이 많으므로 
dp를 이용해서 풀어야한다.(효율적으로)*/   

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


int cache[100] = {0,};

int count_factor(int data,int num)
{
    if(cache[data] != 0)
        return cache[data];

    cache[data] =  count_factor(data/num,num)+1;
    return cache[data];
}


int main()
{
    // int t;
    // int total = 0;
    // cin >> t;

    // total =  factorial(t);
    // cout<<total<<endl;
    int five = 0, two = 0 ,ans = 0;
    int n;
    cin >> n;
    
    ans =count_factor(n,5);    
    // for(int i =2; i<=n; i*=2)
    // {
    //     two+=n/i;
    // }

    // for(int i = 5; i<=n ; i*=5)
    // {
    //     five+=n/i;
    // }

    // ans = (two<five)? two : five;
    cout << ans << '\n';
}