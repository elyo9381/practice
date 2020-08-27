#include <bits/stdc++.h>
using namespace std;
long long a,b,v;
long long h1,h2,mid = 0,result = 0;

void BinarySearch(long long left,long long right){
    while(left <= right){
        mid = (left+right)/2;
        h1 = mid * (a-b);
        h2 = h1 + a;
        if(h2 <= v){
            BinarySearch(mid+1,right);
        } else {
            result = mid;
            BinarySearch(left,mid-1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> a >> b >> v;

    long long lt,rt;

    lt =1; rt =v;
    
    BinarySearch(lt,rt);

    cout << result << "\n";
}