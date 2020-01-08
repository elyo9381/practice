#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

/*조합의 0의 갯수는 nCr 일때 n!의 영의갯수*/   

long long int process(long long int number)
{
    long long int i;
    long long int f=0;
    for(i =5; i<=number; i*=5)
    {
        f += number/i;
    }

    return f;
}

int main()
{
    long long int five = 0, two = 0 ,ans = 0, re = 0;
    long long int n,m;

    cin >> n >> m;

   re = process(n)-process(m)-process(n-m);
    cout << re << '\n';
}