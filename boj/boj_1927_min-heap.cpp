#include <bits/stdc++.h>

using namespace std;

/*
	최소힙은 가장 작은값이 루드에 위치한다. 최대힙은 가장 큰 값이 루트에 위치한다.
	STL에서 최소힙 및 최대힙은 priority_queue로 사용가능하며 이것은 최대힙으로 구성되어있다.
	priority_queue<int, vector<int> greater<int> > PQ 
	위와같이 코드를 작성하면 최소힙을 STL에서 사용할수있다. 
	
*/

int heap[100005];
int sz = 0; // heap size

void add(int x){
	sz++;
	heap[sz] = x;
	int idx = sz;

	while(idx != 1){
		int par = idx/2;
		if(heap[par] < heap[idx])break;
		swap(heap[par],heap[idx]);
		idx = par; // whlie 종료를 위한 idx 1로 설정이다. 
	}
}

int top(){
	if(sz == 0) return 0;
	return heap[1];
}

void pop(){
	if(sz==0) return;

	swap(heap[1],heap[sz]);
	sz--;
	int idx = 1;

	while(2*idx <= sz){ // 왼쪽자식의 idx(=2*idx)가 size보다 크면 idx가 leaf라는 의미이다.
	int min_child;
	// 자식노드가 부모노드보다 크며 자식노드중에서 왼쪽이 작을경우와, 오른쪽자식이 총사이즈보다 클때
	if(heap[2*idx]  < heap[2*idx+1] or 2*idx+1 > sz) min_child = 2*idx;
	// 자식중에 오른쪽이 더 작을떄
	else min_child = 2*idx+1;
	// idx와 오른쪽 자식간에 관계에서 오른쪽이 더 크면 그자리에 위치 시킨다.
	if(heap[idx] < heap[min_child]) break;
	swap(heap[idx], heap[min_child]);
	idx = min_child;

	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;

	cin >> n;
	while(n--){
	int x;
	cin >> x;
	if(x==0){
	cout << top() << '\n';
	pop();
	}
	else{
	add(x);
	}
	}
}


#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int> > PQ;
	// priority_queue<int>로 선언시 최대힙, 위와 같이 선언시 최소힙

	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		if(x==0)
		{
			if(PQ.empty()) cout << "0\n";
			else
			{
				cout << PQ.top() << '\n';
				PQ.pop();
			}
		}
		else
		{
			PQ.push(x);
		}
	}
}

