#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 
 * 조건
 * 행렬 a to b 하는데 필요한 연산의 횟수의 최솟값 구하기 
 * 행렬을 변환하는 연산은 어떤 3x3크기의 부분행렬에 있는 모든 원소를 뒤집는것
 * 
 * 설계
 * 3x3의 대조하고 다른면 변환한다. 
 * 3x3을 한 사이클로 수행핸다.
 * 구현 문제처럼 풀었고 틀렸다. 왜? a,b행렬이 다름을 확인하지 않아서
 * 
 * 디버그 
 * a,b 행렬이 다름을 확인했어야했다. 다르면 그때 a행을 변환하고 
 * 다를때를 찾는것이 최적의 해를 찾는것이다. 
 * 이때 3x3이므로 0~n-2만큼만 루프를 돌아도 된다. 
*/

int N, M;
char a[50][50], b[50][50];
int result;
 
void change(int x, int y)
{
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (a[i][j] == '1') a[i][j] = '0';
            else a[i][j] = '1';
        }
    }
}
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    cin >> N >> M;
 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> b[i][j];
 
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < M - 2; j++)
        {
            if (a[i][j] != b[i][j])
            {
                change(i, j);
                result++;
            }
        }
    }
 
    bool isDifferent = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i][j] != b[i][j])
            {
                isDifferent = true;
            }
        }
    }
 
    if (isDifferent) cout << -1;
    else cout << result;
 
    return 0;
}