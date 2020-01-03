#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;


list<int> josephus(int n, int m);

int main()
{
    int n, m;
    //n 과 m을 입력받는다.
    cin >> n >> m;
    //jose list가 반환되었을것이고
    // 그것을 ans라는 리스트에 복사한다. 
    list<int> ans = josephus(n, m);
    //출력을 위해서 반복자를 설정한다. 
    list<int>::iterator it = ans.begin();
    // ans 를 it를 통해서 출력한다.
    //형식을 맞춰주기 위해서 다음과 같은 방법으로 출력했다.
    cout << "<" << *it;
    it++;
    for (; it != ans.end(); it++)
        cout << ", " << *it;
    cout << ">" << endl;

    return 0;
}

// n,m을 입력받고 n,m을 파라미터로 전달받는다.
list<int> josephus(int n, int m)
{
    //각각의 독립적인 리스트를 만들어준다. 
    // 이유는 조세퍼스 조건에 해당하는 순열과
    // 사람들이 1~N명 있는 순열을 구성하려고 한다. 
    list<int> human;
    list<int> jose;
    // 1~N명의 순열을 구성한다. 
    for (int i = 1; i <= n; i++)
        human.push_back(i);

    //반복자를 통해서 1~N의 순열을 순차적으로 순회한다.
    list<int>::iterator it;
    //시작적은 0번 인덱스이다. 
    it = human.begin();

    // n이 0라고 조건을 준것은 조세푸스 함수가 list를 반환하기 때문이다.
    while (n > 0)
    {
        //m-1 인덱스 만큼 it를 옮긴다. 
        // if조건은 it가 순열의 요소를 다지났을때를 고려한것이다.
        for (int i = 0; i < m - 1; i++)
        {
            it++;
            if (it == human.end())
                it = human.begin();
        }
        // it 더를 m-1번 옮기고 조세푸스 순열을 만들기 위해서 
        // it를 list에 푸시한다.
        jose.push_back(*it);

        // n의 값을 하나식 줄여주는것은 
        // 조세푸스의 순열을 만들기 위해서 it를 가르키고 
        // 그값을 다른 list에 저장하고 1~N의 순열에서는 it가 가리키는 값은 삭제해야한다.
        // 그렇기 떄문에 삭제할것을 고려해서 n을 하나 줄인다. 
        n--;

        //it가 가리키는 값을 제거한다. 
        it = human.erase(it);
        if (it == human.end())
            it = human.begin();
    }

    //반환값으로 list를 반환한다.
    return jose;
}



// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     vector<int> v;
//     int N, M;
//     cin >> N >> M;
//     // 순열을 구성하기 위한 백터에 1~N까지의 데이터를 입력한다.
//     for (int i = 1; i <= N; ++i)
//         v.push_back(i);
//     //이터를 통해서 반복자를 설정한다. 
//     vector<int>::iterator it;
//     //반복자는 인덱스 0부터 순회한다. 
//     it = v.begin();
//     cout << "<";
//     // 조세퍼스 순열을 만들기 위한 조건
//     // 여기에선 M-1만큼 it를 이동하고 다음에 it를 출력한다.
//     // it는 인덱스 0부터 시작하는 ++it를 통해서 순회할때 미리 증가한다. 
//     while (v.size() != 1) {
//         for (int i = 0; i < M-1; ++i) {
//             ++it;
//             if (it == v.end()) 
//                 it = v.begin();
//         }
//         //M-1만큼 이덱스를 이동후 it출력
//         cout << *it<<", ";
//         it = v.erase(it);//출력후 삭제
//         //it가 end를 만나면 it를 앞으로 보낸다. end()는 push의 가장 마지막 값이 아니라 
//         //push다음의 end()인덱스를 가리킨다. 
//         if (it == v.end())
//             it = v.begin();
//     }
//     // 앞서 설계한 조건을 통해서 vector안의 사이즈가 1
//     // 즉 백터에 하나의 요소만 남았으면 it를 출력한다. 
//     cout << *it<<">";
// }


// #include <iostream>

// #include <queue>

// using namespace std;

 

// int N, M; 

// int main(void)

// {
//         // 입출력 속도를 빠르게 한다.
//         ios_base::sync_with_stdio(0);
//         // 입출력 속도를 빠르게 한다.
//         cin.tie(0);
//         // 입력을 받는다. 
//         cin >> N >> M;

 
//         //큐를 생성한다.
//         queue<int> q;
//         // 큐에 1부터 N까지의 데이터를 입력한다.
//         for (int i = 0; i < N; i++)
//             q.push(i + 1);

 

//         //단순 시뮬레이션

//         cout << "<";
//         // 1~N까지의 인덱스를 순차적으로 검색및 확인을 위해서 for문을 작성
//         for (int i = 0; i < N - 1; i++)

//         {
//                 // M만큼 돌아가면서 해당하는 순열을 만들어야하기에 M만큼 이동하는 for문 작성
//                  for (int j = 0; j < M - 1; j++)

//                  {
//                         // M-1에 해당하는 인덱스까지 queue에 다시 푸시 한다.
//                          q.push(q.front());
//                         // cout<<q.front()<<endl;
//                          q.pop();

//                  }
//                 //M을 front()로 출력하고 pop()한다. 이를 통해서 M을 삭제한다. 
//                  cout << q.front() << ", ";

//                  q.pop();

//         }
//         //순열을 출력하고  > 를 출력한다. 
//         cout << q.front() << ">\n";

//         return 0;

// }