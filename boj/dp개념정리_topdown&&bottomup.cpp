#include <bits/stdc++.h>

using namespace std;


// int cnt = 0; // 총 연산 횟수 출력을 위한 전역변수

// int fibonacci(int n)
// {
//     if(n <= 1)
//         return n;
//     else{
//         cnt++;
//         return fibonacci(n-1) + fibonacci(n-2); // f(n) = f(n-1) + f(n-2)
//     }
// }

// int main(void)
// {
//     cout<< fibonacci(39) <<endl;
//     cout<< cnt;
// }



// bottom-up 구현
int d[100] = {0,1};
int fibonacci(int n)
{
    if(n<=1)
        return d[n];

    else if( d[n]>0)
        return d[n];

    else
    {
        for(int i =2; i<=n; i++)
        {
            d[i] = d[i-1] +d[i-2];
        }

        return d[n];
    }
}

// int cnt =0;
// int d[100] = {0,1};

// int fibonacci(int n)
// {
//     if( n <= 1)
//         return d[n];

//     else if(d[n]> 0)
//         return d[n];

//     else
//     {
//         cnt++;
//         d[n] = fibonacci(n-1) + fibonacci(n-2); //f(n) = f(n-1) + f(n-2)
//         return d[n];
//     }
// }

int main(void)
{
    cout<<fibonacci(5)<<endl;
    // cout<<"연산의 수 "<< cnt; //70번째 수를 구함에도 불구하고 103번까지의 연산만 수행

    cout<<endl;

    //연산을 통해서 d[n]에 들어간수 
    for(int i=0; i<5;i++)
    {
        cout<<d[i]<<endl;
    }
}