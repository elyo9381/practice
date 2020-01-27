#include <bits/stdc++.h>

#define endl "\n"
#define MX 

using namespace std;

typedef long long ll;

/*
    Combination 과 permutation은 Idx를 인자로 받느냐 안받느냐 차이고(코드상)
    이론상으로는 조합은 중복이 없으며 순열은 중복을 인정한다. 
    그래서 Idx를 시작점으로 그 이전것은 조합에서 취급하지 않는다. 
    하지만 순열에서는 시작점의 위치가 매번 바뀌어야 하므로 
    중요하다. 뭐가?? idx가 
*/

int n,m;

void func(int* arr, bool* isused, int k,int Idx){ // 현재 k개까지 수를 택했음.
    if( k == m ){ // m개를 모두 택했으면
        for(int i = 0; i < m; i++) 
            cout << arr[i]+1 << ' '; // arr에 기록해둔 수를 출력.(0부터 m-1까지가 아니라 1부터 m까지이므로 +1을 해줌)
        
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++){ // 1부터 n까지의 수에 대해
        // if(!isused[i]){ // 아직 i가 사용되지 않았으면
          arr[k] = i; // k번째 수를 i로 정함
          isused[i] = 1; // i를 사용되었다고 표시
          func(arr, isused, k+1,i); // 다음 수를 정하러 한 단계 더 들어감
          isused[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
        // }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int arr[m] = {};
    bool isused[n] = {}; // 모두 아직 사용되지 않았다고 초기화
    func(arr, isused, 0,0);
    return 0;
}   


/*
    구사가 코드에서도 
    마찬가지로 idx 가 존재햐야 조합을 구성할수있다. 
    시작점 이전에는 쳐다보지 않으려고 한다면 말이다 
    
*/
//koosaga code
#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define move fuck
using namespace std;
const int MAXN = 300005;
const int mod = 1e9 + 7;
using lint = long long;
using llf = long double;
using pi = pair<llf, int>;

int n, m;
int vis[69];
void dfs(vector<int> v,int Idx){
    if(sz(v) == m){
        for(int i =0; i<sz(v); i++)
            printf("%d ",V[i]);
        puts("");
        return;
    }
    for(int i=0; i<=n; i++){
        // if(!vis[i]){
            vis[i] = 1;
            v.push_back(i);
            dfs(v,i);
            v.pop_back();
            vis[i] = 0;
        // }
    }
}

int main(){
    cin >> n >> m;
    vector<int> a;
    dfs(a,1);
}