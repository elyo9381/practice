#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 10000
typedef long long ll;
using namespace std;
/*
    이진탐색풀이는
    D[i] = D[i-1] +A[i-1]이라는 점화식을 세우고 
    D,D+i까지 D[i]-M이 존재하는지 탐색하여서 해결하는방법이다.
    점화식은 A1~ + ~AN까지 이며 i번째부터 j번째까지라고 
    하였던걸 기반으로 찾은거같다.
    모든 A의항을 더하므로 i번째부터 j번째까지 
    예를 들면 12, 123, 1234 ,12342이고 i에서 j까지 더한값이다.
    각 경우의수를 d[i]에 메모제이션을 하고
    그럼 점화식은 d[i] = d[i-1] + a[i-1]이된다.
    i에서 j까지 더한값이 M이여야 하므로 
    d[i] 배열에서 d[i]-M의 값이 존재 여부를 탐색하면
    합이 5인 녀석을 찾을수있다. 


    투포인터 풀이 
    두개의 idx를 가지고 풀이하며
    low,high라고 하였을때 high를 증가시키면서 
    조건에 따라 진행한다 (여기선 다 더하는것)
    i에서 j까지 더하며 sum의 값이 M이 되는순간 카운트를 하고 
    이 경우에도 더하면서 진행한다. 
    M의 경우보다 sum이 커버리면 
    low를 진행시켜 M의 값에 도달할수있도록 진행한다. 
    이를 반복하면서 i에서j까지 더했을시 M이 될수있도록
    진행한다. 
*/


int N,M;
int arr[MAXN];
void Input()
{
    cin >> N >> M;
    for(int i =0 ; i<N; i++){
        cin >> arr[i];
    }
}
void Solution()
{   
  int low = 0, high = 0;
  int sum = arr[0];
  int result = 0;

  while( low <=high && high<N){
    if( sum <M)
        sum +=arr[++high];
    else if( sum == M)
    {
         result++;
        sum +=arr[++high];
    }
    else if(sum > M){
        sum -=arr[low++];
        if( low > high &&low<N)
        {
            high = low;
            sum = arr[low];
        }
    }
  }

  cout<< result<< endl;
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

//이진탐색으로 풀기 
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;
int A[10001];
int N, M;
LL D[10001]; // D[i] = A[0] + A[1] + A[2] + .. + A[i-1]
int main(void) {
    int N;
    LL M;
    scanf("%d %lld", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int i = 1; i <= N; i++) {
        D[i] = D[i - 1] + A[i-1];
    }

    for (int i = 1; i <= N; i++) {
        // printf("%d\n",D[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
    // D[i]에 대해서 D[j] = D[i]-M를 만족하는 j가 있는지 탐색할 것임
        printf("%d\n",binary_search(D, D + i, D[i]-M));
        cnt += binary_search(D, D + i, D[i]-M);

    } 
    printf("%d", cnt);
}


