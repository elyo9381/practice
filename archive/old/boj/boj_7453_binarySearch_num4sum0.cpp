#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 4000
typedef long long ll;
using namespace std;
        /*
             lower_bound하면 -half의 똑같의값의 가장 낮은거
             upper_booun하면 -half의 똑같의 값의 가장 높은거 
             그래서 두개를빼면 0이된다. 
             -half ==v[low] 는 어차피 low나 high는 인덱스 값이고
             그것들의 데이터값은 같기떄문이다.

             mid1[i*T + j] 이것은 
             mid1[T*T]를 1차원 배열로 표현한것
             배열에서는 T*T로범위로 i++식 입력받을수없으니
             i*T +j를 사용하는것이고 i와 j의 범위는 T이다. 
        */   

int N,idx =0;
ll Answer;
int arr[MAXN][4] , ab[MAXN * MAXN] ,cd[MAXN * MAXN];
vector<ll> v;

void Input()
{
    cin >> N;
    for(int i = 0; i< N; i++){
        for( int j = 0; j<4; j++){
            cin >> arr[i][j];
        }
    }


    for(int i=0; i<N; i++){
        for(int j = 0; j< N; j++){
            v.push_back(arr[i][2] + arr[j][3]);

        }
    }

    sort(v.begin(), v.end());
}
void Solution()
{
    ll ret = 0;
    
    for(int i = 0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            ll half = arr[i][0] + arr[j][1];
            ll low = lower_bound(v.begin(), v.end(),-half) - v.begin();
            ll high = upper_bound(v.begin(), v.end(),-half) - v.begin();


            if(-half == v[low]){
                ret +=(high-low);
            }
        }
    }
    cout<< ret<< endl;
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

// #include <stdio.h>
// #include <algorithm>
// #include <functional>
// using namespace std;
// int A[4001], B[4001], C[4001], D[4001];
// int mid1[16000001], mid2[16000001];
// int main(void) {
//     int T;
//     scanf("%d", &T);
//     for (int i = 0; i < T; i++)
//         scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
//     for (int i = 0; i < T; i++) 
//         for (int j = 0; j < T; j++) 
//             mid1[i*T + j] = A[i] + B[j];
        
//     for (int i = 0; i < T; i++)
//         for (int j = 0; j < T; j++)
//             mid2[i*T + j] = C[i] + D[j];

//     sort(mid2, mid2 + T * T);
//     long long cnt = 0;
//     for (int i = 0; i < T*T; i++)
//         cnt += (upper_bound(mid2, mid2 + T * T, -mid1[i]) - lower_bound(mid2, mid2 + T * T, -mid1[i]));
//     printf("%lld", cnt);
// }