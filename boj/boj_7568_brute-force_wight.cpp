#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 15

using namespace std;

/*
    둘다 낮을때만 항상 성립하는 조건이다. !     
*/ 

int N, M, T;
int MAP[MAXN];

vector<pair<pair<int,int>,int >> v; 


void Input()
{
    cin >> T;

    for(int i = 0; i< T; i++)
    {    
        int x,y;
        cin >> x >> y;
        v.push_back({{x,y},1});

    }
}

void Solution()
{
    for(int i = 0; i< T; i++)
    {
        for(int j = 0; j<T; j++)
        {
            if(i==j) continue;
            else if( v[i].first.first < v[j].first.first && v[i].first.second < v[j].first.second)
                v[i].second++;
        }
    }


    for(int i = 0; i < T; i++)
        cout<< v[i].second<< " ";
    cout<<endl;
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
