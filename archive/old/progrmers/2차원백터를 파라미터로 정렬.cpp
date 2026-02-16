#include <vector>
#include <algorithm>
using namespace std;
 
// 2차원벡터를 배열로 받을때는 다음과 같이 받을수 있습니다.
// 파라미터로 받은 2차원 백터는 일반적인 배열의 2차원 배열 사용하듯이 
// 사용하면 된다. 
vector<int> solution(vector<int> array1, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++){
        vector<int> temp;

        // 2번째 부터 짤라야하므로 2차원배열 -1을 j값으로 시작한다.
        for (int j = commands[i][0]-1; j < commands[i][1]; j++)
            temp.push_back(array1[j]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp.at(commands[i][2] - 1));
    }
    return answer;
}