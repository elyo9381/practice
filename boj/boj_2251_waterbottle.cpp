#include <iostream>
#include <vector>	
#include <queue>

#define MAX 201
#define endl "\n"
using namespace std;


// 3차원 배열을 이용한 방법
// 하지만 bfs는 수작업으로 실행했다.


int A,B,C;
bool Visit[MAX][MAX][MAX];

vector<int>  V;

void Input()
{
    cin >> A >> B >> C;
}

void Solution()
{
    queue<pair<pair<int, int>, int> > Q ;
    Q.push(make_pair(make_pair(0,0),C));

    while(!Q.empty())
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int z = Q.front().second;
        Q.pop();

        if(Visit[x][y][z] == true) continue;
        Visit[x][y][z] = true;

        if(x == 0) V.push_back(z);

        // A물통에서 B물통으로 줄때
        if(x+y > B) Q.push(make_pair(make_pair(x+y-B,B),z));
        else Q.push(make_pair(make_pair(0,x+y),z));

        // A물통에서 c물통으로 줄때
        if(x+z > C) Q.push(make_pair(make_pair(x + z - C,y),C));
        else Q.push(make_pair(make_pair(0,y),x+z));
        // B물통에서 A물통으로 줄때
        if(x+y > A) Q.push(make_pair(make_pair(A,x+y-A),z));
        else Q.push(make_pair(make_pair(x+y,0),z));

        // B물통에서 C물통으로 줄때
        if(y+z > C) Q.push(make_pair(make_pair(x,y+z-C),C));
        else Q.push(make_pair(make_pair(x,0),y+z)); // z > 0;

        // C물통에서 A물통으로 줄떄
        if(z+x > A) Q.push(make_pair(make_pair(A,y),z+x-A));
        else Q.push(make_pair(make_pair(z+x,y),0));
        
        // C물통에서 B물통으로 줄때
        if(z+y > B) Q.push(make_pair(make_pair(x,B),z+y - B));
        else Q.push(make_pair(make_pair(x,z+y),0));
     
    }

    sort(V.begin(), V.end());
    for(int i = 0;  i< V.size(); i++)
    {
        cout << V[i] << " ";
    }
    cout <<endl;
}

void Solve()
{
    Input();
    Solution();
} 
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}

// koosaga code dfs version
#include <cstdio>  
#include <algorithm>  
using namespace std;  
  
int v[222][222][222];  
int q[222],a,b,c;  
  
void f(int x, int y, int z){  
    if(x == 0) q[z] = 1;  
    if(v[x][y][z]) return;  
    v[x][y][z] = 1;  
    int t;  
    t = min(b-y,x);  
    f(x-t,y+t,z);  
    t = min(c-z,x);  
    f(x-t,y,z+t);  
    t = min(b-y,z);  
    f(x,y+t,z-t);  
    t = min(c-z,y);  
    f(x,y-t,z+t);  
    t = min(a-x,y);  
    f(x+t,y-t,z);  
    t = min(a-x,z);  
    f(x+t,y,z-t);  
}  
int main(){  
    scanf("%d %d %d",&a,&b,&c);  
    f(0,0,c);  
    for (int i=0; i<222; i++) {  
        if(q[i]) printf("%d ",i);  
    }  
}  