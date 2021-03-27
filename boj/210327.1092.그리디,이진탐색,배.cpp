#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

/*
  
  조건
  모든 화물은 박스 안에, 크레인 N, 1분에 박스 하나를 배에 실을수있다. 
  모든 크레인은 동시에 움직인다.

  각 크레인은 무게 제한이 있다. 무거운 박스는 크레인으로 움직일 수 없다. 
  모든 박스를 배로 옮기는데 드는 시간의 최솟값을 구하라 

  설계 
  내림차순 정렬 하고 크레인보다 큰박스가 존재하면 -1
  순차적으로 비교 하다 감당할수 있는 박스 나오면 it로 지명하고 삭제한다. 
  이때 발견한 박스가 처음이거나 마지막일수있으므로 예외처리 한다. 

  벡터를 이용해서 풀수도 있다. N^2으로 말이다. 
  이때 삭제를 잘해줘야한다. 
*/




const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;

multiset<int> s;

int n,m;
int arr[111];
int mx = 0;

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n, [](int a, int b){
        return a > b;
    });

    cin >> m;
    for(int i = 0; i<m; i++){
        int t; 
        cin >> t;
        s.insert(t);
        mx = max(mx,t);
    }

    int ans = 0;
    if(mx > arr[0]){
        cout << -1; 
    } 
    else {
        while(1){
            if(s.empty()){
            break;
            }
            ans++;

            for(int i = n-1; i>=0; i--){
            if(s.empty()) break;
            auto it = s.find(arr[i]);
            if(it != s.end()){
                s.erase(it); continue;
            }
            it = s.lower_bound(arr[i]);
            if(it == s.begin()) continue;
            --it;
            s.erase(it);
            }
        }
        
        cout << ans ;
    }
}

// int main(){

//   int n , m;


//   cin >> n; 
//   vector<int> cranes;
//   for(int i = 0; i<n; i++){
//     int c;
//     cin >> c;
//     cranes.push_back(c);
//   }

//   cin >> m;
//   vector<int> boxs;
//   for(int i = 0; i<m; i++){
//     int c;
//     cin >> c;
//     boxs.push_back(c);
//   }

//   sort(cranes.begin(),cranes.end(),greater<int>());
//   sort(boxs.begin(),boxs.end(),greater<int>());


//   int cnt = 0;

//   if( cranes[0] < boxs[0]){
//     cout << -1;
//   }
//   else {
//     while(boxs.size()){
//       int idx = 0;
//       for(int i = 0; i< boxs.size(); i++){
//         if(idx == n){
//           break;
//         }
//         if(boxs[idx] <= cranes[i]){
//           idx++;
//           boxs.erase(boxs.begin()+i);
//           i = i-1;
//         }
//       }

//       cnt++;
//     }
//     cout << cnt ;
//   }
// }