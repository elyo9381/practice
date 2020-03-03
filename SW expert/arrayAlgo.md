## Exhaustive search(완전검색)
 *brute-force 기법이다.
 *모든 경우의 수를 테스트, 최종해법을 도출함
## greedy algorithm
 * 여러 경우 중 하나를 결정 해야할 때마다 그 순간에 최적이라고 생각되는것을 선택해 나가는 방식으로 진행하여 최종적인 해답에 도달한다.
 
## 정렬
* counting sort - 항목들의 순서를 결정하기 위해 집합에 각 항목이 몇 개씩 있는지 세는 작업을 하여, 선형 시간에 정렬하는 효율적인 algorithm
	- 정수나 정수로 표현할 수 있는 자료에 대해서만 적용 가능 각항목의 발새회수를 기록하기 위해, 정수 항목으로 인덱스되는 카운트들의 Arrary(배열)를 사용하기 때문임
	- DATA에서 각 항목들의 발생 회수를 세고,정수 항목들로 직접 인덱스 되는 카운트 배열 COUNTS에 저장
	-정렬된 집합에서 각ㅎㅇ목의 앞에 위치 할 항목의 개수를 반영하기 위해 COUNTS의 원소를 조정
	`Counting_Sort(A,B,K)
	// A [1...n] -- 입력 Array(1 to k)
	// B [1...n] -- 정렬된 array
	// C [1...n] -- COUNTS array
	for i = i to k do
		C[i]=0
	for j = 1 to n do
		C[A[j]] = C[A[j]]+1
	for i = 2 to k do 
		C[i] = C[i] + C[i-1]
	for j = n 1 do 
		B[C[Aj]] = A[j]
		C[A[j]] = C[A[j]]-1
`

## 부분집합 문제
* 부분집한은 원소의 갯수가 n개일떄 2^n개의 경우가 생긴다. 이것은 비트 연산자를 통해서 풀수있다.
	- & : and연산 (두 이진수 값의 각 자릿수를 비교해,  두 값 모둥 1이 있을 땡만 1을 계산하고 나머지의 경우에는 0을 계산한다.)
	- | : or연산 (두 이진수 값의 각 자릿수를 비교해, 둥줄 하나라도 1이 있다면 1을 계사하고 나머지의 경우에는 0을 계산한다.)
	- ^ : Xor연산 (두 이진수 값의 각 자릿수를 비교해, 값이 같을 경우 0을 계산하고 다를 경우 1을 계산한다.)
	- ~ : 비트보수 (하나의 이진수의 모든 비트를 뒤집는다.)
	- >> : 오른쪽으로 시프트 (숫자의 모든 비트를 오른쪽으로 옮기고, 옮기고 빝비트 자리를 0으로 채운다. `a>>b ` a의 비트들은 b칸씩 왼쪽으로 이동한다. a / 2^b의 값이 된다.)
	- << : 왼쪽으로 시프트 (숫자의 모든 비트를 왼쪽으로 옮기고, 옮기고 빝비트 자리를 0으로 채운다. `a<<b ` a의 비트들은 b칸씩 왼쪽으로 이동한다. a x 2^b의 값이 된다.)
* subset 문제는 비트연산자를 통해서 푸는데 a,b,c,d,e의 배열이 존재할, subset은 2^n개를 구할수 있으며 배열의 인덱스 0번 즉 a는 0001로 표현할 수 있고, 인덱스 1번 즉 b는 0010로 표현가능하다. 부분집할을 비트로 표현할때 a=0001,b=0010,c=0100,d=1000,e=10000이되고 부분집합 a,b는 0011이 된다. 부분집합의 갯수를 n개로 비교할 대상을 j개라 할때 `n(i) & (1<<j) `를통해서 구할수 있다. 부분집할을 더했을때 0이 되는것을 찾을수있다.


## 검색
* 순차검색
	- 순차 탐색은 일렬로 되어 있는 자료를 순서대로 검색하는 방법을 말한다.
	*-가장 간단하고 직관적인 검색 방법이다.
	-배열이나 연결 리스트 등 순차구조로 궇ㄴ된 자료구조에서 원하는 항목을 찾을 때 유용하다.
	-알고리즘이 단순하여 구현이 쉽지만, 검색대상의 수가 많은 경웅는 구행시간이 급격히 증가하여 비효율적이다.*

	`int sequetialSearch(int *ar, unsigned int num, int key)
	{ unsinged int i ;
		for(int i =0;i<num;i++){
			//숫자가 존재할 경우 
			if(ar[i] ==key) return i;
			//정렬되어 있는데 키가 없을 경우 if(ar[i] > key) break;
		}
		return -1;
	}`

* 이진 검색
	-자료의 가운데의 있는 항목의 키 값과 비교하여 다음 검색의 위치를 결정하고 검색을 계속 진행하는 방법이다. 목적 키를 찾을 때까지 이진 검색을 순환적으로 반복 수행함으로써 검색 범위를 반으로 줄어가면서 보다 빠르게 검색을 수행 할 수 있다. 이진검색을 하기 위해서는 자료가 정렬된 상태여야한다.
	*-자료의 중앙에 있는 원소를 고른다.
	-중앙 원소의 값과 차고자 하는 목표 값을 비교한다.
	-표값이 중앙 원소의 값보다 작으면 자료읜 왼쪽 반에 대해서 새로 검색을 수행하고, 크다면 자료의 오른쪽 반에 대해서 새로 검색을 수행한다.
	-찾고자 하는 값을 찾을 때까지 위의 과정을 반복하다.*

	
	`int binarySearch(int *ar, int num, int key)
	{ int up, down, mid;
		down =0;
		up = num -1;
		for(;;){
			mid = (up+down)/2;
			if(ar[mid] ==key) return mid;
			if(ar[mid] >key)
			{
				up = mid -1;
			}
			else
			{
				down = mid +1;
			}
			if(up < down)
			{
				return -1;
			}
		}
	}`

	
* 해싱
	-대량의 데이터를 매번 정렬하면, 프로그램의 반응은 느려질 수 밖에 이러한 대량 데이터의 성늘 저하 문제를 해결하기 위해서 배열 인덱스를 사용 할 수 있다.

## 래더
* 이차배열의 상하좌우를 구하는법
	- x[]= {0,0,-1,1}
	- y[] = {-1,1,0,0}
	- x배열과 y배열을 통해서 상하 좌우를 구하고 isWall함수를 통해서 벽을 구현한다. wall함수는 x<0 || x>5 일때 true이고 !iswall일때 main문에서 함수가 상하좌우가 작동하게 된다. 배열은 `arr[y][x]`로 작성된다.

* 선택정렬 
	-주어진 자료들 중 가장 작은 값의 원소부터 차례대로 선택하여 위치를 교환하는 방식이다. 선택정렬은 셀렉션 알고리즘을 전체 자료에 적용한 것이다.

	-정렬과정
	*주어진 리스트 중에서 최소값을 찾는다.
	그 값을 리스트의 맨 앞에 위치한 값과 교환한다.
	맨 처음 위치를 제외한 나머지 리스트를 대상으로 위의 과정을 반복한다.*

##문자열
* 문자열 매칭 알고리즘 비교
	- 찾고자 하는 문자열 패턴의 길이 m, 총 문자열 길이 n
	- 고지식한 패텅 검색 알고리즘 : 수행시간(mn)
	- 카프-라빈 알고리즘 : 수행시간 O(n)
	- KMP 알고리즘 : 수행시간 O(n)
	- 보이어 무어 알고리즘 : 앞의 두 매칭 알고리즘들의 공토점 텍스트 문자열의 문자를 적어도 한번씩 훑는 다는것이다. 따라서 최선의 경우에도 (n) 보이어 알고리즘은 텍스트 문자를 다 보지 않아도 된다. 발산의 전환 : 패턴 오른쪽부터 비교한다. 최악의 경우 수행시간 O(mn) 입력에 따라 다르지만 일반적으로 O(n)보다 시간이 덜 든다.

## stack
* 메모이제이션 : 컴퓨터 프로그램을 실행 할 때 이전에 계산한 값을 메모리에 저장해서 매번 다시 계산하지 않도록 하여 전체적인 실행속도를 빠르게 하는 기술
	- DP의 핵심이 되는기술

* DP(동적 계획법) : 먼저 입력크기가 작은 부분 문제들을 모두 해결한 후에 그 해들을 이용하여 보다 큰 크기의 부분 문제들을 해결 그리고 최종적으로 원래 주어진 입력의 문제를 해결

	- recursive() 방식 : 재귀적 구조는 내부에 시스템 호출 Stack을 사용하는 overhead가 발생할수 있음
	- iterative 방식  : memorization을 재귀적 구조에 사용하는것보다 반복적 구조로 DP를 구현 한 것이 성능명에서 보다 효율적

* DFS with stack
 -비선형 구조인 그래프는 그래프로 표현된 모든 자료를 빠짐없이 검색하는것이 중요

 - 시작 정점의 한방향으로 갈수 있는 경로가 있는곳 까지 깊이 탐색
 - 더이상 갈곳이 없게 되면, 가장 마지막에 만났더 갈림길 간서이 있는 정점으로 되돌아옴
 - 다른 방향의 정점으로 탐샘을 계속 반복하여 결국 모든 정점을 방문하여 순회

##queue
* 30000

## list 와 vector의 차이점
* 자료를 보관하는 저장소가 연속적인 메모리에 있어서 인덱스 연산으 제공하지만 list에는 제공하지 않는다.

## 인접행렬 
* DFS 깊이 우선 탐색은 그래프의 정점에서 다른 정점으로 갈수 있는 경로를 찾는 방법중 하나입니다. 이를 구현하기 위해서는 그래프를 표현할수있어야 합니다.
* 만약 점의 개수가 많다면 인접행렬은 이웃하지 않는 간선을 위한 영역도 포함하여 메모리 및 성능이 나빠집니다. 이럴때는 정점과 간선의 집합으로 그래프를 표현하여 문제를 해결할 수 있습니다.


## 해쉬 
* 해쉬 함수는 16자리를 입려받아 앞 4자리를 반환하는 함수이고, 해쉬 함수를 이용해 만든 테이블을 해쉬테이블이라고한다.

* 해쉬함수를 만드는 과정에서 충돌이 일어날수있다.

* 대표적인 방법은 Oenp Addressing과 Chaining입니다.
 - Oenp Addressing에서 해당칸이 이미 차있을 경우 1칸식 뛰는것을 Linear Probing이라고 한다. 이외에도 어떤 방식으로 뛰냐에 따라 Quadratic probing, Double hasing등의 방식이 있다.

 - Chaining은 해쉬 테이블에서 각 인덱스가 원소 1개만 담는것이 아니라, Linked List 구조로 여러 원소를 담고 있는 방식을 의미한다.

 - STL을 사용할수있다면 set, map과 기능이 동일하기 떄문에 사용하지 않지만 삼성역량에서는 삽입, 삭제, 검색을 O(N)을 빠르게 수행해주는 자료구자 필요할 수 있고 이런 자료구조중에서 해쉬가 그나마 구현이 간단한 편이다.

## 이진검색트리(Binary Search Tree)
* 꼭대기 노드를 트리노드라고 부르며 제일끝의 노드, 아래로 뻗은게 없는 노드들은 리프입니다.

* 이진트리는 각 노드의 자식이 2개 이하인 트리입니다. 왼쪽자식과 오른쪽 자식을 구별할수있습니다.

* 특정 노드를 삽입할 때 필요한 시간 : 해당 노드가 자기 자리를 찾아 가기 위해 비교를 몇번 해야하는지(= 해당 노드의 높이가 얼마인지)에 비례 [이진트리에서 높이는 약 lg N에 해당한다-삽입에 따른 시간복잡도-], [편향트리에서는 높이가 N이라고 한다면 -삽입에 따른 시간복잡도는 O(N)이다.-] 

* 검색과 삽입은 같은 과정에서 이루어진다. 삽입또는 검색하고자하는 데이터를 찾은뒤 기준보다 크다면 오른쪽 자식노드로 이동 도착한 노드에서 search값이 노드보다 작으면 왼쪽 크면 오른쪽으로 N번이동하여 원하는 위치에 값을 삽입 혹은 검색한다. 

* 삭제의 경우 
  - case 1 : 자식이 없는 노드를 지울 때 그냥 지우면됨
  - case 2 : 자식이 하나인 노드를 지울 때 자식을 지워진 노드의 자리에 올리면 된다.
  - case 3 : 자식이 2개인 노드를 지울 때 지울 노드의 오른쪽 자식중 가장 작은 왼쪽자식을 지울노드로 이동시킨다.

* STL에서 이진트리를 사용할땐 set, map을 통해서 할수있다. 
- set : 값들을 이진검색트리로 저장하는 자료구조, 단 중복원소는 허용하지 않음
- map : key,value를 key에 대한 이진 검색 트리로 저장하는 자료구조, 단 중복 key는 허용하지 않음

- multiset, multimap 은 중복원소 및 중복 key가 허용된다. 

## 힙

* 힙 : 최댓값 혹은 최솟값을 빠르게 찾아내기 위한 이진트리 (이진검색트리와 헷갈리지 말것)

* 최소힙의 경우 부모는 자식보다 작아야하고, 최대힙의 경우 부모는 자식보다 커야한다. 이 때 루트가 최솟값 혹은 최댓값이 된다.

* 최소 힙에서는 원소의 삽입, 최솟값확인, 최솟값 삭제의 기능을 제공하고, 최대 힙에서는 원소의 삽입, 최댓값사제의 기능을 제공한다. 최소 혹은 최대가 아닌 값의 존재 여부 확인 혹은 원소 제거는 불가능합니다.

* 힙에서의 삽입은 일단 원소를 트리상의 다음 공간에 추가하고, 이후 힙의 성질을 만족하게끔 서로 자리를 바꾸는 식으로 구현됩니다. 트리상의 다음공간이라는 표현이 헷갈릴 수 있는데 높이가 작은곳부터, 높이가 같다면 왼쪽부터 채워나간다고 생각하면 됩니다.


## 문자열 기초

* c언어에서는 char를 가지고 문자열을 다루는 것에 비해 C++에서는 그럭저럭 편해졌긴 하지만, 여전히 python에 비해서는 문자열 다루기 정말 불편합니다. 그래서 시간복ㅈㅂ도를 크게 고려할 필요가 없는 상화에서 문자열을 빡세게 다뤄야하는 문제라면 python을 쓰시는것을 강력하게 추천드립니다.

* 실패함수
	- 실패함수 F[x] : S[0:k] = S[x+1-k:x+1]을 만족하는 최대 K
	- 문자열 S[0:x+1]에서 접두사와 접미사가 일치하는 최대 길이
	- 매칭이 실패했을때 얼마나 점프할수있는지를 구현한 실패함수


vector<int> makeTable(string pattern){
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int  j= 0;
	for(int i = 1; i< patterSize; i++){
		while(j > 0 && pattern[i] !=pattern[j]){
			j = table[j-1];
		}

		if(pattern[i] == pattern[j]){
			table[i] = ++j;
		}
	}
	return table;
}


int main(void){
	string pattern = "abacaaba";
	vector<int> table = makeTable(pattern);
	for(int i =0 i< table.size(); i++){
		cout<< table[i];
	}
	return 0;
}

* KMP알고리즘은 접두사와 접미사를 이용하여 실패함수를 구하고 parent와 pattern이 i번째 증가하다가 다르다면 실패함수를 이용하여서 접두사가 같은 위치에 j를위치시킨다. 이를 하기위해서는
실패함수를 알아야한다. 

## 라빈카프
* T과 P이 존재한다. P가 있을때 (p[0]x5^3 + p[1]x5^2 + p[2]x5^1 + p[3]x5^0)mod 509를 통해서 해쉬값을 구하고 
P의 길이 만큼 T에 길이를 P의 해쉬값가 같이 T에 해쉬값을 구한다. 
이를 통해서 해쉬값이 같을때 같은 패턴을 찾았다고 할수있다. 
	
	- 해쉬값이 같지만 실제 문자열이 다른경우는 두문자열이 동일한지를 비교하는 루틴이 추가되어야한다. 그러나 이 문제에서 실제로 두 문자열이 동일 한지 비교하는 루틴을 추가하면 시간 복잡도가 최악의 경우 O(500000^2)가 된다. 시간절약을 위해 틀릴 가능성을 감수하더라도 실제로 두 문자열이 동일 한지 비교하지 않습니다. 

## 그래프 

* 그래프에서 간선을 egde라고 부르고 정점을 vertex라고 부른다. 최단경로, 검색엔진,랭킹산정 등 관계를 설정해야하는 상황에서 유용하게 활용 될수 잇는 자료구조이다. 

* vertex와 egde가 서로 연결되어 루프가 발생하는 조건을 cycle이라고 한다. 

* 단순그래프는 루프가 존재하지 않는 그래프 이다.

* 그래프는 undirected graph와 directed graph로 구성되어 있다.

* 인접행렬를 통한 그래프의 시간복잡도는 O(V), 공간 복잡도는 O(V^2)가 필요하다.
 
 - 방향성 그래프
`int adj_matrix[10][10] = {};
int v,e;
cin >> v >> e;
for(int i =0; i<e; i++){
	int u,v;
	cin >> u >> v;
	adj_matrix[u][x] = 1;
}
`
* 인접리스트를 통한 그래프의 시간복잡도는 O(V), 공간 복잡도는 O(V+E)가 필요하다. 

 -방향성 그래프 
* BFS
`vector<int> adj[10];
int v,e;
cin >> v >> e;
for(int i =0; i<e; i++){
	int u,v;
	cin >> u >> v;
	adj.push_back(v);
}`

`int edge[10][10];
int deg[10];
int *adj[10]
int idx[10];
int main(){
	int v,e;
	cin >> v >> e;
	for(int i = 0; i< e; i++){
		cin >> edge[i][0] >> edge[i][1];
		deg[edge[i][0]]++;
	}
	for(int i = 1; i<=v; i++)
		adj[i]= new int [deg[i] + 1];
	for(int i = 0 ; i < e; i++){
		int u  = edge[i][0], v =  edge[i][1];
		adj[u][idx[u]] = v;
		idx[u]++;
	}
}
`

순회만 하는 코드


`
	//방문여부를 보여주는 bfs 연결 그래프 코드
	vector<int> adj[10];
	bool vis[10];
	void bfs(){
		queue<int> q;
		q.push(1);
		vis[1] = true;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			cout << cur << ' ';
			for(int i=0; i< adj[cur].size(); i++){
				int nxt = adj[cur][i];
				if(vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
			} 
		}
	}
	//STL을 지원하지 않는다면 별도로 큐를 구현하고 i를 adj[cur].size대신 deg[cur]까지 증가 시키면 될것입니다. 
`


`
	정점과의 거리를 나타내는 연결그래프
	vector<int> adj[10];
	int dist[10];
	void bfs(){
		for(int i =1; i<10; i++) dist[i] = -1;
		queue<int> q;
		q.push(1);
		dist[1] = 0;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int i=0; i < adj[cur].size(); i++){
				int nxt = adj[cur][i];
				if(dist[nxt] != -1) continue;
				q.push(nxt);
				dist[nxt] = dist[cur] + 1;
			} 
		}
	}
	//STL을 지원하지 않는다면 별도로 큐를 구현하고 i를 adj[cur].size대신 deg[cur]까지 증가 시키면 될것입니다. 
`


` 연결그래프가 아닐 떄 순회 
vector<int> adj[10];
bool vis[10];
int v = 9; // 정점의 갯수 
void bfs(){
	queue<int> q;
	for(int i =1; i<=v; i++){
		if(vis[i]) continue;
		q.push(i);
		vis[i] = true;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			cout << cur << ' ';
			for(int i = 0; i< adj[cur].size(); i++){
				int nxt = adj[cur][i];
				if(vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
			}
		}
	}
}
`

* DFS
 - 깊이를 우선으로 방문하는 알고리즘



 ` // 스택을 이용한 DFS
 연결 그래프에서의 순회, 비재귀
vector<int> adj[10];
bool vis[10];
void dfs(){
	stack<int> s;
	s.push(1);
	vis[1] = true;
	while(!s.emtpy()){
		int cur = s.top();
		s.pop();
		for(int i = 0; i < adj[cur].size(); i++){
			int nxt = adj[cur][i];
			if(vis[nxt]) continue;
			s.putsh(nxt);
			vis[nxt] = true;
		}
	}
}
 `


` // recursion을 이용한 DFS
vector<int> adj[10];
bool vis[10];
void dfs(int cur){
	cout << cur << ' ';
	for(int i = 0; i< ajd[cur].size(); i++){
		int nxt = adj[cur][i];
		if(vis[nxt]) continue;
		vis[nxt] = true;
		dfs(nxt);
	}
}
`

- 재귀적으로 들어갈때마다 메모리 중 스택영역에 계속 데이터가 쌓이게 된다는점 이것은 SW expert등에서 스택 메모리가 1MB로 제한될 경우 깊이 10만의 재귀함수는 반드시 스택 메모리 크기 제한을 넘기게 되고, 이로 인해 런타임에러가 발생합니다. 

- 재귀방법과 비재귀방법은 방문해다는 기록을 언제 남기냐에 대한 차이가 있다.

- 우리가 관념적으로 재귀 DFS이고 비재귀 DFS가 동작하는 방식과는 차이가 있다. 

- 비재귀 DFS는 순회를 잘 수행하지만 우리가 관념적으로 생각하는 DFS와 세부 동작이 다릅니다. 그래서 단순히 flood fill내지는 순회를 하는것이 아니라 DFS의 고유한 성질을 사용해 문제를 해결해야 하는 상황일 경우 앞에서 소개한 비재귀 를 이용하면 안됩니다. 

`
vector<int> adj[10];
bool vis[10];
void dfs(){
	stack<int> s;
	s.push(1);
	while(!s.empty()){
		int cur  = s.top();
		s.pop();
		if(vis[cur]) continue;
		vis[cur] = true;
		for( int i = 0 ; i< adj[cur].size(); i++){
			int nxt= adj[cur][i]; 
			if(vis[nxt]) continue;
			s.push(nxt);
		}
	}
}`

하지만 비재귀 또한 우리가 관념적으로 생각하는 DFS와 동일하게 동작하도록 바꿀수있습니다. 

`
vector<int> adj[10];
bool vis[10];
int v = 9;
void dfs(){
	stack<int> s;
	for(int  i =1; i<=v; i++){
		if(vis[i]) continue;
		s.push(i);
		vis[i] = true;
		whlie(!s.empty()){
			int cur = s.top();
			s.pop();
			cout <<cur << ' ';
			for(int i =0; i< adj[cur].size(); i++){
				int nxt = adj[cur][i];
				if(vis[nxt]) continue;
				s.push(nxt);
				vis[nxt] = true;
			}
		}
	}
}`