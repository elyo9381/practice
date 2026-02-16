#include <bits/stdc++.h>
using namespace std;
void quick_sort(int *arr, int st, int en) { // arr[st to en-1]을 정렬할 예정
  if(en-st <= 1) return; // 수열의 길이가 1 이하이면 함수 종료.(base condition)
	int pivot = arr[st]; // 제일 앞의 것을 pivot으로 잡는다. 임의의 값을 잡고 arr[st]와 swap해도 상관없음.
  int l = st+1; // 포인터 l
  int r = en-1; // 포인터 r
  while(1){
    while(l <= r and arr[l] <= pivot) l++;
    while(l <= r and arr[r] >= pivot) r--;
    if(l > r) break; // l과 r이 역전되는 그 즉시 탈출
    swap(arr[l],arr[r]);
  }
  swap(arr[st],arr[r]);
  quick_sort(arr,st,r);
  quick_sort(arr,r+1,en);
}
int a[1000001];
int main() {
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	quick_sort(a, 0, n);
	for (int i = 0; i < n; i++) cout << a[i] << '\n';
}