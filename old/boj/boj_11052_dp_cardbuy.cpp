#include <bits/stdc++.h>

using namespace std;

/* */

int d[1000000] = {0};
int p[100001] = {0};

// //bottom-up
int getMaxPrice(int n)
{
    if(n==0)
        return d[n];

    else if (d[n]>0)
        return d[n];

    else
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=i;j++)
            {
                d[i] = max(d[i],d[i-j] + p[j]);
            }
        }

        return d[n];
    }

}
// top-down 방식
// int getMaxPrice(int n)
// {
//     if (n==0)
//         return d[n];

//     else if (d[n] >0)
//         return d[n];

//     else
//     {
//         for(int i=1; i<=n; i++)
//             d[n] = max(d[n],getMaxPrice(n-i) +p[i]);
//     }

//     return d[n];
// }


int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    for(int i =1; i<=tc ; i++)
    {
        cin >> p[i];
    }
    
    cout<<getMaxPrice(tc)<<endl;

    return 0;
}