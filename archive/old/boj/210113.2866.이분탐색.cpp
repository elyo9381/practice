#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
typedef long long ll;
#define hash 1000000007LL;
using namespace std;
const int MAX = 1000002;

int R, C;
vector<string> table;
map<string,int> mp;

int main(){

    cin >> R >> C; // 행의 개수와 열의 개수 
    
    table.resize(R);
    
    for(int i = 0; i<R; i++){
        string s;
        cin >> s;
        table[i] = s;
    }

    int lv = 0 , rv = R - 1, mid = 0;

    bool trace;
    while(lv<=rv){
        mid  = (lv + rv)/2;
        bool check = true;

        for( int i = 0; i< C; i++){
            string tmp = "";
            for(int j = mid; j<R; j++){
                tmp += table[j].substr(i,1);
            }
            if(mp[tmp]){
                check = false;
                break;
            }
            mp[tmp]++;
        }

        if(!check) rv = mid -1;
        else lv = mid+1;

        trace = check;
        mp.clear();
    }
    if(!trace) cout << mid -1 ;
    else  cout << mid ;
}   