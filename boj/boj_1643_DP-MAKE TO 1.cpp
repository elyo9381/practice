#include <bits/stdc++.h>

using namespace std;


int d[1000000] = {0};
int To1(int n)
{
    if(n<=1)
        return d[n];

    else if(d[n] > 0)
        return d[n];

    else
    {
        d[n] = To1(n-1)+1;

        if(n%2==0)
        {
            int temp;
            temp = To1(n/2)+1;
            if(d[n] > temp)
                d[n] = temp;
        }

        if(n%3 == 0)
        {
            int temp;
            temp = To1(n/3)+1;
            if(d[n] > temp)
                d[n] = temp;
        }

        return d[n];

    }

}


int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    cout<<To1(t)<<endl;

}