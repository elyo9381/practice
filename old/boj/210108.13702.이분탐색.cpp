#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> 

using namespace std;

const int INF = INT_MAX -1;
const int MAX = 10000 + 1;

int n , k ;
int jjj[MAX];

bool check(int mid){
    int cnt = 0;

    for(int i = 0; i<n; i++){
        cnt += jjj[i]/mid;
        if(cnt>=k) return true;
    } 
    return false;
}

int main(){

    cin >> n >> k;

    for(int i = 0; i<n; i++){
        cin >> jjj[i];
    }

    if( n > k){
        cout << 0 <<'\n';
    return 0;}

    int lv = 1, rv = INF;
    while(lv <= rv){
        int mid = (lv+rv) /2;
        cout << mid <<'\n';
        if(check(mid)){
            lv = mid+1;
        } else {
            rv = mid-1;
        }
    }
    if( (rv) == -1) cout <<  0 << '\n';
    else   cout << rv <<'\n';
}