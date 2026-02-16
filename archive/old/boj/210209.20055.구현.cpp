#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321
#define hash 1000000007LL
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 1001;

int arr[MAX];
int ch[MAX];
int n,k,cnt =0,zcnt=0;


void ratate(){

    int tmp = arr[2*n];
    for(int i = 2*n; i>=2; i--){
        arr[i] = arr[i-1];
    }
    arr[1] = tmp;

    
    for(int i = n-1; i>=1; i--){
        ch[i+1] = ch[i];
    }

    ch[1] = 0;

}

int main(){

    cin >> n >> k;

    for(int i = 1; i <=2*n ; i++){
        cin >> arr[i];
    }


    while(true){

        if(zcnt >=k )break;
        // 회전
        ratate();

        // 내릴수있으면 내림
        if(ch[n] == 1){
            ch[n] = 0;
        }

        // 로봇이 이동가능한가
            for(int i = n-1; i>=1; i--){
                // if(i == 2*n) 
                if(ch[i] == 1){
                    if(arr[i+1] !=0 && ch[i+1] == 0) {
                        arr[i+1]--;
                        ch[i+1]=1;
                        ch[i]=0;
                        if(arr[i+1]== 0) zcnt++;
                    }
                }
            }
        
        // 올라갈 수 있다면 올림
        if(arr[1] != 0 && ch[1] == 0){
            ch[1] = 1;
            arr[1]--;
            if(arr[1] == 0) zcnt++;
        }
        

        cnt++;
        

    }
    cout <<cnt <<'\n';

}

