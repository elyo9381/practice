#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 4000
typedef long long ll;
using namespace std;
    /*
        문제해결방법
        
        sum2에 arr[i][0] + arr[j][1]을 한이유
        1. 문제의 조건에서 1+2 항목과 3+4 항목이 0이 되는 지점을 찾아야하므로
        2. 1+2를 더해서 vector에 넣어주는것이다.
           i*N+j를 한이유는 입력으로 받은 2차원 배열에서 값을 입력 받으려고
        3. 백터에 1+2의 값이 들어있고 오른차순으로 정렬되어있다.
        4. 3+4의 값을 정렬된 백터에서 
            upper_bound하면 같은 값의 가장오른값 
            lower_bound하면 같은 값의 가장 왼쪽값이 설정된다
            (이때 1+2의 값이 -86이고 3+4의값도 -86인데 1+2가 정렬된 백터에 -86이 하나뿐이면
             lower은 -86의인덱스 upper는 -86다음 백터의 인덱스를 반환한다.
             그렇기 때문에 upper- lower 하면 -86이 벡터에 하나 존재하므로 값은 0이되고 인덱스는 1을 반환하는것이다.)
    */



int N;
int arr[MAXN][4];

void Input()
{


    cin >> N;
    for(int i = 0; i< N; i++){
        for( int j = 0; j<4; j++){
            cin >> arr[i][j];
        }
    }
}

void Solution()
{   
    vector<int> sum2(N*N);
    for(int i = 0; i<N; i++)
        for(int j = 0 ; j< N; j++)
            sum2[i*N+j]  = arr[i][0] + arr[j][1];

    sort(sum2.begin(), sum2.end());

    ll ans = 0;
    for(int i = 0 ; i< N; i++)
        for(int j = 0;  j<N ; j++)
            ans += upper_bound(sum2.begin(), sum2.end(), -arr[i][2] -arr[j][3]) -
                    lower_bound(sum2.begin(),sum2.end(), -arr[i][2] -arr[j][3]);

    cout<<ans<<endl;
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