#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 500002
using namespace std;

int n,m,t,k;
int mod = 10007;

vector<int> a;
vector<int> b;

/*
1822번 차집합 은 두 백터를 비교하여 ans백터에 다시 
값을 넣어서 설계하였다.

    // STL로 이진탐색 사용방법
    binary_search(v.begin(),v.end(), target)
    binary_search(arr, arr+n, target)
    v백터에 target의 여부를 알려줌

    lower_bound, upper_bound는
    각각 target이 삽입되어도 오름 차순 순서가
    유지되는 제일 왼쪽/오른쪽 인덱스를 반환합니다.

*/

int BinarySearch(int target, int len){
    int st = 0;
    int en = len -1;
    while(st<=en){
        int mid  = (st+en)/2;
        if(a[mid] < target)
            st = mid+1;
        else if(a[mid] > target)
            en = mid-1;
        else
            return mid;
    }
    return -1; // st > en 일 경우 whlie문을 탈출함

}

int lower_idx(int target, int len){
    int st=0;
    int en = len;
    while(st<en){
        int mid = (st+en)/2;
        if(a[mid] < target)
            st = mid+1;
        else en = mid;
    }
    return st; // st = en으로 가능한 후보가 1개로 확정될 경우 whlie 문을 탈출함
}

int upper_idx(int target, int len){
    int st = 0;
    int en = len;
    while(st<en){
        int mid = (st+en)/2;
        if(a[mid] > target) en = mid;
        else st= mid+1;
    }
    return st;
}

void Input()
{   
    cin >> n >> m ; 

    for(int i =0; i<n; i++){
        int num;
        cin >>num;

        a.push_back(num);
    } 


    sort(a.begin(), a.end());

    for(int i =0; i<m ; i++){
        int num; 
        cin >> num;
        b.push_back(num);
    }
    sort(b.begin(),b.end());

}
void Solution()
{   

    vector<int> ans;
    for(int i=0; i < n; i++)
        if(!binary_search(b.begin(), b.end(), a[i]))
            ans.push_back(a[i]);
    
    sort(ans.begin(), ans.end());

    cout<<ans.size()<<endl;
    for(int i = 0; i<ans.size(); i++)
        cout<< ans[i] <<" ";

    return ;


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
