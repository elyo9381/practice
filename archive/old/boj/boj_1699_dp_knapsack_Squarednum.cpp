
#include<iostream>

using namespace std;

int d[100001];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        d[i] = i; // 최대값을 초기값으로 넣어줌. 1을 i번 하면 최대값이기 때문. 
        for(int j = 1; j*j <= i; j++){
            if(d[i] > d[i -(j*j)] + 1)
                d[i] = d[i -(j*j)] + 1;
        }

        cout<< d[i] << " ";
    }

    cout << d[n] << "\n";
}

 