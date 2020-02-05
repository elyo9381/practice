#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int N, M;
int result;
vector<int> v; 

void sumOfCards(int idx, int cnt, int sum)
{        //조건 만족할 경우
       if (cnt == 3 && sum <= M)
        {
                 result = max(result, sum);
                 return;
        }
        //기저 사례
        if (idx >= N || cnt > 3 || sum > M)
                 return;
        //해당 카드 선택
        sumOfCards(idx + 1, cnt + 1, sum + v[idx]);
        //해당 카드 선택 X
        sumOfCards(idx + 1, cnt, sum);
}


int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin >> N >> M;
        v.resize(N);

        for (int i = 0; i < N; i++)
                 cin >> v[i];

        sumOfCards(0, 0, 0);
        cout << result << "\n";
        return 0;
}




#include <cstdio>
#include <algorithm>
using namespace std;

int a[105],n,m;

int main(){
    int ret = 0;
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%d",a+i);
    }
    
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                if(a[i] + a[j] + a[k] <= m){
                    ret = max(ret,a[i] + a[j] + a[k]);
                }
            }
        }
    }
    printf("%d",ret);
}