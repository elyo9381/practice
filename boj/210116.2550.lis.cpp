
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
const int MAX = 987564321;
 
int main()
{
    int n;
    scanf("%d", &n);
 
    vector<int> idx(n + 1); // val이 가지는 idx
    vector<int> rev(n + 1); // idx가 가지는 val
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
 
        idx[val] = i;
        rev[i] = val;
    }
 
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
 
        arr[i] = idx[val];
    }

    vector<int> lis(n, MAX);
    vector<pair<int, int> > trace;
 
    int plis = 0;
 
    lis[0] = arr[0];
    trace.push_back(make_pair(0,arr[0]));
 
    for (int i = 1; i < n; i++)
    {
        // lis 인덱스 검출
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        cout << "it : " << it << " " << arr[i] <<'\n';
            for(int i = 0 ;  i<=n+1  ; i++){
            cout << lis[i] << ' ';

        }
        cout <<" lis " << '\n';

        lis[it] = arr[i];
 
        trace.push_back(make_pair( it, arr[i] ));
    }

//     for(int i = 0 ; i<=n+1 ; i++){
//     cout << idx[i] << ' ';
//     }
//     cout <<" idx " << '\n';

//      for(int i = 0 ;  i<=n+1  ; i++){
//     cout << rev[i] << ' ';
//     }
//     cout <<" rev " << '\n';

//     for(int i = 0 ;  i<=n+1  ; i++){
//     cout << arr[i] << ' ';
//     }
//     cout <<" arr " << '\n';

//     for(int i = 0 ;  i<=n+1  ; i++){
//         cout << lis[i] << ' ';

//     }
//     cout <<" lis " << '\n';

//     for(int i = 0 ;  i<=n+1  ; i++){
//     cout << trace[i].first<< ' ';
//     }
//     cout <<" trace.first " << '\n';
//     for(int i = 0 ;  i<=n+1 ; i++){
//     cout << trace[i].second<< ' ';
//     }
//     cout <<" trace.second " << '\n';
// cout<<lis[0]<<endl;
    // plis = lis 크기
    int len = lis.size();
    for (int i = 0; i < len; i++)
        if (lis[i] != MAX)
            plis++;
 
    plis--; // 인덱스 0부터 시작이니 -1
 
    len = trace.size();
    
    // 역추적
    vector<int> ansIdx;
    for (int i = len - 1; i >= 0; i--)
    {
        if (trace[i].first != plis)
            continue;
    
        ansIdx.push_back(trace[i].second); // idx가 담긴다.    
        plis--;
    }
 
    vector<int> ans;
 
    // idx를 다시 실제 값으로 변환
    len = ansIdx.size();
    for (int i = 0; i < len; i++)
        ans.push_back(rev[ansIdx[i]]);
 
    // 오름차순
    sort(ans.begin(), ans.end());
 
    printf("%d\n", ans.size());
    for (auto i : ans)
        printf("%d ", i);
 
    return 0;
}
