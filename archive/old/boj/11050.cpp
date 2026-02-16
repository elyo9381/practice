#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k,res = 1; 

    cin >> n >> m;

    for(int i = 1; i<=n; i++)res *=i;
    for(int i = 1; i<=k; i++)res /=i;
    for(int i = 1; i<=n-k; i++)res /=i;

    cout << res;

}