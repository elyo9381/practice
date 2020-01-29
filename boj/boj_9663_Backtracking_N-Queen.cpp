#include <bits/stdc++.h>

#define endl "\n"
#define MX 10000

using namespace std;

typedef long long ll;

/*
  1. 가지치기를 많이 하지않아서 시간초과가 발생한다.
  2. 한단계 더 들어갈 때 가능한 값인지 불가능한 값인지를 비효율적으로 판단해
  시간초과가 발생한다. 
  (예를 들어 N-Queen문제에서 isused를 따로 뒤 않으면 퀸을 특정 자리에 둘수 있ㄴ니 판단하는데 O
  O(1)대신 O(N)이 걸린다.)
  3. 재귀를 들어갔다가 탈출할때 isused와 같은 값을 제대로 바꿔 놓지 않아서 잘못된 답을 출력한다.
  4. 배열 대신 vector로 isused와 같은 값을 관리할때 함수의 인자로 참조자를 넘기는게 아니라 직접 vector를 넘겨 시간초과가 발생한다.
  
*/

int n,m;
int input[MX];
bool isused[MX];

bool isused1[40]; // column을 차지하고 있는지
bool isused2[40]; // / 방향 대각선을 차지하고 있는지
bool isused3[40]; // \ 방향 대각선을 차지하고 있는지

int cnt = 0;

void func(int cur) { // cur번째 row에 말을 배치할 예정임
    if (cur == n) { // N개를 놓는데 성공했다면
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) { // (cur, i)에 퀸을 놓을 예정
        if (isused1[i] or isused2[i + cur] or isused3[cur - i + n-1]) // column이나 대각선 중에 문제가 있다면
            continue;
        isused1[i] = 1;
        isused2[i + cur] = 1;
        isused3[cur-i+n-1] = 1;
    func(cur+1);
        isused1[i] = 0;
        isused2[i + cur] = 0;
        isused3[cur-i+n-1] = 0;
    }
}
int main(void) {
    ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  func(0);
  cout << cnt<<endl;
}

// #include <bits/stdc++.h>
// #define endl '\n'
// #define MAXN 15

// using namespace std;

// int N, Answer;
// int MAP[MAXN];

// void Input()
// {
//     cin >> N;
// }

// bool Yes_pos(int line)
// {
//     for(int i = 0; i< line; i++)
//     {
//         if( MAP[i] == MAP[line] || abs(MAP[line] - MAP[i]) == line - i )
//             return false;
//     }
//     return true;
// }

// void DFS(int line)
// {
//     if(line == N)
//     {
//         Answer++;
//         return ;
//     }

//     for(int i = 0; i< N ; i++)
//     {
//         MAP[line] = i;
//         if(Yes_pos(line) == true) DFS(line +1);
//     }
// }

// void Solution()
// {
//     DFS(0);
//     cout<< Answer <<endl;
// }

// void Solve()
// {
//     Input();
//     Solution();
// }

// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     Solve();
//     return 0;
// }