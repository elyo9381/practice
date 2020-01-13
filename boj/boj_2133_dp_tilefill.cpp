#include<iostream>

using namespace std;

int d[31];

int main()
{
    int n;
    cin >> n;

    d[0] = 1;

    for (int i = 2; i <= n; i+=2){           //(i=2, j=2), (i=4, j=2,4),  (i=6, j=2,4, 6)
        for(int j = 2; i-j >= 0; j+=2){
            if(j == 2)
                d[i] = 3 * d[i-j];
            else
                d[i] += 2 * d[i-j];
        }
    }

    cout << d[n] << "\n";
}