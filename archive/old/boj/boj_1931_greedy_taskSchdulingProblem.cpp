#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 15
using namespace std;

/*
    task scheduling problem
    시간내 업무를 이용할수있는 최적의 회의실 사용횟수를 구하는것이고 
    사무실을 이용하는것은 끝났을때 시간이 중요하다.
    그렇기 때문에 pair를 이용하엿고(sturct)를 이용해도 된다. 
    끝날시간으로 정렬하여서 
       for(int  i =0; i<T; i++){
        if(t > v[i].second)continue;

        ans++;
        t = v[i].first;
    
    t라는 시간이 주어지고 끝날시간을 기준으로 체크를한다.

    struct 사용시 

    struct point {
    int x;
    double y;
    char c;
    };

    이라면

    point s;
    vector<point> v;

    cin >> s.x >> s.y;
    v.push_back(s);

*/

int N, M, T;
vector<pair<int, int>> v;

void Input()
{   
    cin >> T;

    for(int i = 0; i< T; i++)
    {    
        cin >> N >> M;
        v.push_back({M,N});

    }
}

void Solution()
{

    sort(v.begin(),v.end());

    int ans =0, t=0;
    for(int  i =0; i<T; i++){
        if(t > v[i].second)continue;

        ans++;
        t = v[i].first;
        
    }    
    cout<< ans <<endl;
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
            
