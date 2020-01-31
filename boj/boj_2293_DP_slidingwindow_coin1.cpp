#include <bits/stdc++.h>

#define endl "\n"
#define MAXN 100


/* 동전 문제는 O(n^3)으로 풀수없는 문제이다.
   각각의 동전이 나오는 경우의수를 계산해서 풀게 된다면
   시간초과 진행된다.
   4MB 이기 때문이다. 
   그렇기 때문에 슬라이딩 윈도우,투 포인터를 
   이용한 DP방법으로 풀어햐한다. 
   dp review...

*/
using namespace std; 
int K; //총합
int N; //동전의 개수
int coinValue[101], cache[10001];

 

int coin(int K)
{
        memset(cache, 0, sizeof(cache));
        cache[0] = 1; //0원은 모든 동전을 세지 않았을 경우(1가지)
        for (int i = 0; i < N; i++)
              //K 뿐만 아니라 K 이하 합에 대해 경우의 수를 모두 구한다
               for (int j = coinValue[i]; j <= K; j++){
                      cout<< " cache[j] " << cache[j] << " cache[j - coinValue[i]]" <<cache[j - coinValue[i]]<<endl;
                       cache[j] += cache[j - coinValue[i]];
               }
        return cache[K];
}

int main(void)
{
        cin >> N >> K;
        for (int i = 0; i < N; i++)
               cin >> coinValue[i];
        cout << coin(K) << endl;
        return 0;
}
