#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*백준 재귀를 이용해서 풀었는데 이해가 안된다.
*/

void go(int n)
{
    cout<<"go in"<<n<<endl;
    if(n==0)
        return;
    if(n%2==0)
    {
        go(-(n/2));
        cout<<0;
    }
    else
    {
        if(n > 0)
            go(-(n/2));
        else
            go((-n+1)/2);

        cout<<1;
    }
}
int main()
{
    int  n;

    cin >> n;

    cout<< -4/-2<<endl;
    if(n==0)
    {
        cout<< 0<<"\n";
    }
    else
    {
        go(n);
    }
}