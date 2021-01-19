#include <iostream>
#include <vector>
#include <cstdlib>
// #include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>

using namespace std;
#define hash 1000000007LL;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 987654321;
 

int n,m;
map<string, int> mp1;
string mp2[100001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        
        mp1[s]=i;
        mp2[i]=s;
    }

    for(int i = 0; i<m; i++){
        string s;
        cin >> s;
        int num = atoi(s.c_str());
        // s를 입력받고 s의 첫배열 원소가 1-9임을 확인하여 숫자인지 파악 
        if(num){
            cout << mp2[num-1] << '\n';
        } else {
            cout << mp1[s] + 1 <<'\n';
        }
    }

    return 0;
}



// int main(){

//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> m;

//     vector<string> v(n+1);
//     for(int i = 1; i<=n ;i++) cin >> v[i];

//     vector<pair<string, int > > dogam(n);
//     for(int i = 0; i<n; i++){
//         dogam[i].first = v[i+1];
//         dogam[i].second = i+1;
//     }

//     sort(dogam.begin(),dogam.end());
//     for(int i = 0; i<m ;i++){
//         string s;
//         cin >> s;
//         int num = atoi(s.c_str());

//         if(num){
//             int idx = 0;
//             for(int i = 0; i< s.length(); i++){
//                 idx +=s[i] - '0';
//                 idx *= 10;
//             }
//             idx /=10;
//             cout << v[idx] << '\n';
//         } else {
//             int lo = 0 , hi = n-1 , mid ;

//             while(hi - lo > 1){
//                 mid = (lo + hi)/2;
//                 if(dogam[mid].first == s){
//                     cout << dogam[mid].second << "\n";
//                     break;
//                 } else if( dogam[mid].first < s)
//                     lo = mid;
//                 else 
//                     hi = mid;
//             }
//               // while(lo<=hi){
//             //     mid = (lo + hi)/2;
//             //     if(dogam[mid].first == s){
//             //         cout << dogam[mid].second << "\n";
//             //         break;
//             //     } else if( dogam[mid].first < s)
//             //         lo = mid+1;
//             //     else 
//             //         hi = mid-1;
//             // }
//         }
//     }
//     return 0;
// }