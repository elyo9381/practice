// #include <string>
// #include <vector>
// #include <queue>
// using namespace std;

// vector<int> solution(vector<int> progresses, vector<int> speeds) {
//     vector<int> answer;
//     queue<int> q;
    
//     for(int i = 0; i<progresses.size(); i++)
//     {
//         q.push(progresses[i]);    
//     }
    
//     while(!q.empty()){
//         for(int i = 0; i<q.size();i++){
//             q[i] += speeds[i];
//         }
//         if(q[0] >=100){     
//         for(int i = 0; i<q.size(); i++)
//         {
//             if(q[i]>=100)
//             {
//                 cnt++;
//                 q.pop();
//             }
//             else
//                 break;
//         }
//         answer.push_back(cnt);
//         }
//     }
//     return answer;
// }


#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue <int> q;
    for (int i = 0; i < progresses.size(); ++i)
        q.push(ceil((double)(100 - progresses[i]) / (double)speeds[i]));

    int num = 1;
    int cur = q.front();
    q.pop();
    while (!q.empty()) {
        if (q.front() <= cur) {
            q.pop();
            ++num;
        }
        else {
            answer.push_back(num);
            num = 1;
            cur = q.front();
            q.pop();
        }
    }
    answer.push_back(num);

    return answer;
}
