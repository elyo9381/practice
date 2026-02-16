#include <bits/stdc++.h>
using namespace std;

int arr[105], result = 0, n,m;

void sumOfCards(int idx,int cnt, int sum){
    if(cnt == 3 && sum <=m){
        result = max(result, sum);
        return ;
    }
    if(cnt > 3 || idx >=n || sum > m) return ;

    sumOfCards(idx+1,cnt+1, a[idx]+sum);
    sumOfCards(idx+1,cnt,sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 0 ; i<n; i++){
        cin >> arr[i];
    }

    sumOfCards(0,0,0);

    cout << result << "\n";
}