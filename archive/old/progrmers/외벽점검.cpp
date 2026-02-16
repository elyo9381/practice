#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int pmu[8];
int ch[8];

// weak는 원형이 추가되어 있는 상태이고 dist는 permutation을 만들기위해서 파라미터로 받아왔다.
// 순열을 만들기 위해 start, Level을 뜻하는 s,L이 파라미터로 사용하였다.
// 막혔던 부분은 원형을 표현한 배열위에 length 만큼 pmu를 통해 체크하며 loop를 돌는 방법에서 막혓다. 
// 그리고 stl이 아닌 직접 pmu를 재귀를 통해서 구하여서 반환 값이 계속 바뀌는것을 캐치 하지 못하여 많은 시간을 잡아먹었다. 
// else 부분에서 answer값... pmu에 맞는 최소인원을 구하고 이를 res에 저장하므로 기억할수있도록 하였다. 


int dfs(vector<int> weak, vector<int> dist, int s, int L, int length){
	int answer, res = 1e9; 
	if(L== dist.size()){
		answer = 1e9;
		for(int start = 0; start< length; start++){ // 기존 length만큼 loop
			int cnt = 1; // cnt가 1인이유는 원형 배열에서 pmu를 인덱스별 계속 체크하기 때문에
			int position = weak[start] + pmu[cnt -1]; // pmu는 dist순열임 
			for(int idx = start; idx < start + length; idx++){
				if(position < weak[idx]){ // position은 idx-1 까지는 갈수있다는 거리임
					cnt+=1; // 갈수없는 거리에선 다음타자
					if(cnt > dist.size()){ // 인원수가 기존 dist를 넘어버리면 실행취소
						break;
					}
					position = weak[idx] + pmu[cnt -1];// cnt++ 되었으므로 새로운 인원이 갈수있는 지점을 설정
				}
			}
			answer = min(answer,cnt);
		}
		return answer;
	} else { 
		for(int i = 0; i<dist.size(); i++){
			if(ch[i] == 1) continue;
			ch[i] = 1;
			pmu[L] = dist[i];
			answer = dfs(weak,dist,i+1,L+1,length);
			res = min(res, answer);
			ch[i] = 0;
		}
	}
	return res;
}

int solution(int n, int vector<int> weak, vector<int> dist){
	// weak의 2배로 늘려서 원형을 표현할것이다. 
	// 여기서 기존 weak의 길이를 미리 변수에 지정해줘야한다.

	int length = weak.size();
	for(int i = 0; i<length; i++){
		weak.push_back(weak[i]+n);
	}

	int answer;
	
	// 각 취약점에서 거리에따른 최소인원을 체크해야한다.
	// 하지만 dist배열에서 어떤 배열의값이 먼저와야하는지 알수없으므로 
	// dist의 순열의 모든 경우의수를 체크한다. 
	// ex) 취약점 1에서 거리가 1,2,3,4 인지 모두 체크해야하는것이다.
	answer = dfs(weak,dist,0,0,length);

	if(answer > dist.size())	
		return -1;

	return answer;
}