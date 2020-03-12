#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> towers;
    stack<int> tanswer;

    for(int i = 0; i< heights.size(); i++)
    {
        towers.push(heights[i]);
    }
    int tnum = towers.size();

	while(!towers.empty())
	{
		int now  = towers.top();
		towers.pop();

		stack<int> cmp(towers);
		int tn = tnum;

		if(tn == 1){
			tanswer.push(0);
			continue;
		}

		while(!cmp.empty())
		{
			int comp = cmp.top();
			cmp.pop();
			tn--;
			if(now  < comp)
			{
				tanswer.push(tn);
				break;
			}
			if(tn == 1)
			{
				tanswer.push(0);
				break;
			}

		}
	tnum--;
	}

    while(!tanswer.empty()){
        answer.push_back(tanswer.top());
        tanswer.pop();
    }

    return answer;
}