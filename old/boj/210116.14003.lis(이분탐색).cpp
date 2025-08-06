#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>

#define hash 1000000007LL;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 1000001;

// 최장 증가 수열 LIS
// 이분탐색으로 푸는 방법


int arr[MAX];
int lis[MAX];
pii ans[MAX]; // firs : lis가 될수 있는 위치, second : 해당 하는값
stack<int> s;

int _lower_bound(int lo, int hi, int t){

    while(lo<=hi){
        int mid = (lo+hi)/2;

        if(lis[mid] < t) {
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    return lo;
}

int main(){

    int n , i = 0, j = 0;

    cin >> n ; 

    for(int i = 0 ; i<n; i++){
        cin >> arr[i];
    }
    int pLis = 0, pArr = 1;

    lis[pLis] = arr[0];
    ans[0].first = 0;
    ans[0].second = arr[0];

    while(pArr < n){
        if(lis[pLis] < arr[pArr]){
            lis[++pLis] = arr[pArr];

            ans[pArr].first = pLis;
            ans[pArr].second = arr[pArr];
        } else {
            int pos = _lower_bound(0,pLis,arr[pArr]);
            lis[pos] = arr[pArr];

            ans[pArr].first = pos;
            ans[pArr].second = arr[pArr];
        }

        pArr++;
    }
    cout <<  pLis + 1 << '\n';

    // for(int i = 0 ; i<n ; i++){
    //     cout << lis[i] << ' ';
    
    // }
    // cout <<'\n';

    // for(int i = 0 ; i<n ; i++){
    // cout << arr[i] << ' ';
    // }
    // cout <<'\n';

    // for(int i = 0 ; i<n ; i++){
    // cout << ans[i].first<< ' ';
    // }
    // cout <<'\n';
    // for(int i = 0 ; i<n ; i++){
    // cout << ans[i].second<< ' ';
    // }
    // cout <<'\n';

    int t = pLis;

    for(int i = n-1; i>=0; i--){
        if(ans[i].first == t){
            s.push(ans[i].second);
            t--;
        }
    }

    while(!s.empty()){
        cout<< s.top()<< " ";
        s.pop();
    }
}