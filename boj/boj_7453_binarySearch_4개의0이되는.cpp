#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 4000
typedef long long ll;
using namespace std;

int N,idx =0;
ll Answer;
int arr[MAXN][4] , ab[MAXN * MAXN] ,cd[MAXN * MAXN];
    vector<ll> v;
    vector<ll> a;

void Input()
{
    cin >> N;
    for(int i = 0; i< N; i++){
        for( int j = 0; j<4; j++){
            cin >> arr[i][j];
        }
    }


    for(int i=0; i<N; i++){
        for(int j = 0; j< N; j++){

            a.push_back(arr[i][0] + arr[j][1]);
            v.push_back(arr[i][2] + arr[j][3]);

        }
    }

    sort(v.begin(), v.end());
    sort(a.begin(), a.end());
}
void Solution()
{
    ll ret = 0;
    ll low = 0;
    ll high = 0;
    for(int i = 0; i<N; i++)
    {
            ll low = lower_bound(v.begin(), v.end(),-a[i]) - v.begin();
            ll high = upper_bound(v.begin(), v.end(),-a[i]) - v.begin();

    if((high-low) ==0) ret++;
    }
    cout<< ret<< endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}