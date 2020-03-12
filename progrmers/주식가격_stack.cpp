// #include <string>
// #include <vector>

// using namespace std;

// vector<int> solution(vector<int> prices) {
// 	vector<int> answer(prices.size(),0);
// 	for (int i = 0; i < prices.size()-1; i++) {
// 		int time = 1;
// 		int j;
// 		for ( j = i+1; j < prices.size()-1; j++) {
// 			if (prices[i] > prices[j]) {
// 				answer.at(i) = time;
// 				break;
// 			}
// 			else {
// 				time++;
// 			}
// 		}
// 		if (j == prices.size() - 1) {
// 			answer.at(i) = time;
// 		}
// 	}
	
// 	return answer;
	
// }

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();

    for (int i = 0; i<size; i++)
    {
        // 스텍이 차있으면서 가격이 떨어지기 시작하면
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }

        // 가격이 올라갈때동안 스텍에 넣음
        s.push(i);
    }

    // 스텍에 남은것들을 계산해줌
    while (!s.empty())
    {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }

    return answer;
}