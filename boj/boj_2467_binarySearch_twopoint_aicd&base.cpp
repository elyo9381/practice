#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 10000
typedef long long ll;
using namespace std;
/*
  
*/

int N,M;
vector<int> v(N);
void Input()
{
    cin >> N ;
    for(int i =0 ; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
}
void Solution()
{
    int i =0, j = v.size()-1;
    int total = 2e9;
    pair<int, int> ret;

    while(i < j){

        int a = v[i];
        int b = v[j];

        if(abs(a+b) < total){
            total = abs(a+b);

            ret.first = v[i];
            ret.second = v[j];
        }

        if(a+b<0) i++;
        else j--;
    }
    cout<< ret.first << " "<< ret.second <<endl;
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
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <unordered_set>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    int score = 2e9 + 1;
    int ans[2];
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(v.begin(), v.end(), -v[i]) - v.begin();
        for (int j = idx - 1; j <= idx; j++) {
            if (j < 0 || j >= N || i == j) continue;
            if (score > abs(v[i] + v[j])) {
                score = abs(v[i] + v[j]);
                ans[0] = v[i], ans[1] = v[j];
            }
        }
    }
    if (ans[0] > ans[1]) swap(ans[0], ans[1]);
    cout << ans[0] << ' ' << ans[1] << '\n';
}