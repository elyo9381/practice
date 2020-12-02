#include<bits/stdc++.h>
using namespace std;

int n;
long long num, r=1, m =1234567891;
char str[51];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> str;

    for(int i = 0; i<n; i++){
        num +=(str[i]-96) * r;
        num %=m;
        r *=31;
        r %=m;
    }
    cout << num << "\n";
}