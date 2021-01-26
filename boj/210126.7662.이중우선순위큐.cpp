#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
#define INF 987654321
#define hash 1000000007LL
typedef long long ll;
typedef pair<int,int> pii;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

// 이중 우선순위큐는 priority큐를 구현하여 (사용) 입력은 같이하며 삭제시 가장 max, 가장 min값인 우선순위에서 
// 삭제를 진행하면된다. 
// 이때 주의할점은 하나의 큐에서 삭제시 다른 큐에 데이터가 남아있는 상태가 있을수있다. 
// 이때는 방문체크등을 활용하여 유효하지 않는 데이터를 삭제해야한다. 


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n;

	cin >> t;

	while(t--){
		
		cin >> n;

		priority_queue<int,vector<int>, less<int> > maxHeap;
		priority_queue<int,vector<int>, greater<int> > minHeap;

		map<int,int> m;

		char op;
		int num;

		while(n--){
			cin >> op >> num;
			if(op == 'I'){
				maxHeap.push(num);
				minHeap.push(num);
				m[num]++;
			} else {
				if( num == 1){
					while(!maxHeap.empty() && m[maxHeap.top()] == 0)
						maxHeap.pop();

					if(!maxHeap.empty()){
						m[maxHeap.top()]--;
						maxHeap.pop();
					}

				} else if (num == -1) {
					while(!minHeap.empty() && m[minHeap.top()] == 0)
						minHeap.pop();

					if(!minHeap.empty()){
						m[minHeap.top()]--;
						minHeap.pop();
					}
				}
			}
		}

		while(!maxHeap.empty() && m[maxHeap.top()] == 0)
			maxHeap.pop();
		while(!minHeap.empty() && m[minHeap.top()] == 0)
			minHeap.pop();

		if(minHeap.empty())
			cout << "EMPTY\n";
		else 
			cout << maxHeap.top() << " " << minHeap.top() << '\n';
	}
}	