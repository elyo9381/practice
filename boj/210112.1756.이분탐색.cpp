// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>
// #include <math.h>
// typedef long long ll;
// #define hash 1000000007LL;
// using namespace std;
// const int MAX = 1000002;


// int d, n;

// vector<int> oven;

// int bs(int x, int pos){
//     int lv = 0, rv = pos, mid = 0, res = 0;

//     while(lv<=rv){  
//         mid = (lv+rv)/2;
//         //   cout << "lv : " << lv << " rv : " << rv << " mid : " << mid  << " X : " << x <<'\n';
//         if(oven[mid] < x){
//             rv = mid-1;
//         } else {
//             res = mid;
//             lv = mid+1;
//         }
//         // cout << lv << " " << rv <<'\n';
//     }
//     return res;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
    
//     cin >> d >> n;
//     oven.push_back(1000000001);
//     for(int i=1; i <= d; i++){
//         int num;
//         cin >> num;
//         oven.push_back(num);
//         oven[i] = min(oven[i-1], oven[i]);
//     }

//     // for(int  i = 1; i<d ; i++){
//     // }

//     int old = 0, dough = 0 , pos = d+1;

//     for(int i = 0; i<n; i++){
//         old = dough;
//         cin >> dough;
//         // cout << num <<endl;
//         if(!pos) continue;
//         if(dough <= old ) {pos--; continue;}
//         pos-=1;
//         pos = bs(dough,pos);
//         // cout << deep << ;
//     }
//     cout << pos;

//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
typedef long long ll;
#define hash 1000000007LL;
using namespace std;
const int MAX = 1000002;


int d, n;

vector<int> oven;

int bs(int x, int pos){
    int lv = 0, rv = pos, mid = 0, res = 0;

    while(lv<=rv){  
          cout << "lv : " << lv << " rv : " << rv << " mid : " << mid  << " X : " << x <<'\n';
        mid = (lv+rv)/2;
        if(oven[mid] > x){
            lv = mid+1;
        } else {
            res = mid;
            rv = mid-1;
        }
        cout << lv << " " << rv <<'\n';
    }
    return rv;
}

int main(){


    cin >> d >> n;
    oven.resize(d+1);
    oven[0] = 1e9+1;
    for(int i=1; i <=d; i++){
        // int r;
        // cin >> r;
        // oven.push_back(r);
        cin >> oven[i];
        oven[i] = min(oven[i-1], oven[i]);
    }


    int old = 0, dough = 0 , pos = d+1;

    for(int i = 0; i<n; i++){
        old = dough;
        cin >> dough;
        // cout << num <<endl;
        if(!pos) continue;
        if(dough <= old ) {pos--; continue;}
        pos-=1;
        pos = bs(dough,pos);
        // cout << deep << ;
    }
    cout << pos;

    return 0;
}
