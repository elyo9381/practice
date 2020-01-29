#include <bits/stdc++.h>

#define endl "\n"
#define MX 10000

using namespace std;

typedef long long ll;

/*

*/

int n,m=0;
int arr[MX];
bool isused[MX];
int ret = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }


    for(int i =1;i <(1<<(n));i++)
    // 1<<n: 부분집합의개수
    {
        for(int j =0;j <n;j++)// 원소의수만큼비트를비교함
        {
        if(i &(1<<j)) // i의j번째비트가1이면j번째원소출력
        {
            sum +=arr[j];
        }
        }
        if(sum == m){
            ret++;
        }
    }

    cout<< ret<<endl;
}
