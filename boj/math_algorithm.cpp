#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 100001
using namespace std;

int N, K;

vector<int> v;
bool isPrime1(int n)
{
    if(n==1) return false;
    for(int i = 2; i< n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

bool isPrime2(int n)
{
    if(n==1) return false;
    for(int i =2 ; i*i<n; i++){
        if(n%i ==0) return false;
    }
    return true;
}

// 시간은 에라스토 체네스와 비슷하나 메모리를 13~40 배 더 먹음 
vector<int> allPrime1(int n )
{
    vector<int>ret;
    for(int i =1; i<=n;i++){
        if(isPrime2(i)) ret.push_back(i);
    }
    return ret;
}

// 에라스토체네스 방법이고 allPrime1 보다 메모리 효율적으로 절약
/*
    최적화
    1. i<=n에서 i*i<=n으로
    2. j = i*2에서 i*i
    3 int state[n] 에서 vector<bool> state
    int 배열을 칸당 4바이트
    bool배열을 1바이트
    vector<bool> 칸당 1비트
*/


vector<int> allPrime2(int n){
    vector<int> ret;
    vector<bool> state(n+1,true);
    state[1] = false;
    for(int i =2; i*i<=n; i++){
        if(!state[i]) continue;
        for(int j = i*i; j<=n; j += i) state[j] = false;
    }
    
    for(int i = 1; i<= n ; i++){
        if(state[i]) ret.push_back(i);
    }

    return ret;
}

// 소인수 분해
void soinsu(int n){
    for(int i = 2; i*i <= n; i++){
        while(n % i == 0){
            cout<< i<< endl;
            n/=i;
        }
    }
}
int r = 0;
int division(int n)
{
    for(int i =1; i*i <= n; i++){
        if(n%i == 0) v.push_back(i);

    }

    for(int i = v.size()-1; i>=0; i--){
        if(v[i]*v[i] == n )continue;
        v.push_back(n/v[i]);
        K--;
        if(K==0) return v[K-1];
    }



}


void Input()
{   
    cin>> N >> K;
}
void Solution()
{   

    cout<< division(N);
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
