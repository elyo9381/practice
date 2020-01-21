#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MX = 1001;
// int v,e,start;
// vector<int> vec[MX];
// bool check[MX];

//인접리스트
// void dfs(int x){
//     cout<<x<<" ";

//     //방문여부를 체크함
//     check[x] = true;

//     // dfs의 인접리스트는 정점을 기준으로  
//     // 깊이 만큼 조건을 줘야함
//     // 예제에서 정점이 4개 있으로 조건을 vec[x]로 설정
//     for(int i =0; i<vec[x].size(); i++){
//         int y = vec[x][i];
//         if(check[y] == false)
//             dfs(y);
//     }

// }

// void bfs(int x){
//     queue<int> q;

//     q.push(x);
//     check[x] = true;

//     while(!q.empty()){
//         int currnetNode = q.front();
//         q.pop();
//         cout<< currnetNode << " ";
//         for(int i =0; i<vec[currnetNode].size(); i++){
//             int y = vec[currnetNode][i];
//             if(check[y] == false){
//                 q.push(y);
//                 check[y]=true;
//             }
//         }
//     }

// }

// int main(){
//     cin >> v >> e >> start;

//     //입력을 받아 인접리스트 만들기
//     while(e--)
//     {
//         int x, y;
//         cin >> x >> y;

//         vec[x].push_back(y);
//         vec[y].push_back(x);
//     }

//     // 작은 번호의 노드부터 방문 할 수 있도록 인접리스트를 정렬함
//     for(int i =1; i<=v; i++)
//         sort(vec[i].begin(),vec[i].end());

//     dfs(start);
//     cout<<endl;

//     memset(check, false, sizeof(check));

//     bfs(start);
//     cout<<endl;

// }




int v,e,start;
int arr[MX][MX];
bool check[MX];
void dfs(int x);
void bfs(int x);



void dfs(int x){
    cout<< x <<" ";
    check[x] = true;

    for(int i =1; i<=v; i++){
        if(check[i] == false && arr[x][i]==1 )
            dfs(i);
    }
}


void bfs(int x){
    queue<int> q;

    q.push(x);
    check[x] =true;


    while(!q.empty()){

    int curNode = q.front();

    q.pop();
    cout<< curNode<< " ";
    for(int i =1; i<=v;i++){
        if(check[i] == false && arr[curNode][i] == 1){
            q.push(i);
            check[i] =true;
        }   
    }
  }
}

int main()
{
    cin>> v >> e>>start;


    while(e--){
        int x,y;
        cin >>x>>y;
        arr[x][y] = arr[y][x] =1;
    }


    dfs(start);
    cout<<endl;

    memset(check, false,sizeof(check));


    bfs(start);
    cout<<endl;
}