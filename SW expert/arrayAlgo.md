## Exhaustive search(완전검색)
 *brute-force 기법이다.
 *모든 경우의 수를 테스트, 최종해법을 도출함
## greedy algorithm
 * 입력받은 어떤 값을 cnt배열에 넣고 조건의해서 cnt에서 배열인덱스의값을 삭제하는 방법으로 해를 찾아간다.(정렬이 되어있다는 가정하에)

## 정렬
* counting sort - 항목들의 순서를 결정하기 위해 집합에 각 항목이 몇 개씩 있는지 세는 작업을 하여, 선형 시간에 정렬하는 효율적인 algorithm
	- 정수나 정수로 표현할 수 있는 자료에 대해서만 적용 가능 각항목의 발새회수를 기록하기 위해, 정수 항목으로 인덱스되는 카운트들의 Arrary(배열)를 사용하기 때문임
	- DATA에서 각 항목들의 발생 회수를 세고,정수 항목들로 직접 인덱스 되는 카운트 배열 COUNTS에 저장
	-정렬된 집합에서 각ㅎㅇ목의 앞에 위치 할 항목의 개수를 반영하기 위해 COUNTS의 원소를 조정
	1Counting_Sort(A,B,K)
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