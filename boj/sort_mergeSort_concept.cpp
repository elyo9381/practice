#include <bits/stdc++.h>
using namespace std;

int a[1000001];
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수

// mid = (st+en)/2라고 할 때 a[st to mid-1], arr2[mid to en-1]은 
// 이미 정렬이 되어있는 상태
void merge(int st, int en){
  int mid = (st+en)/2;
  int idx0 = st; // arr_sort에 값을 넣기 위해 사용하는 index
  int idx1 = st; // a[st to mid-1]에서 값을 보기 위해 사용하는 index
  int idx2 = mid; // a[mid to en-1]에서 값을 보기 위해 사용하는 index
  while(idx1 < mid and idx2 < en){
    if(a[idx1] < a[idx2])
      tmp[idx0++] = a[idx1++];
    else
      tmp[idx0++] = a[idx2++];
  }
  // 어느 한 리스트에는 값이 남아있을 것이다.
  while(idx1 < mid) // a[st to mid-1]에 사용하지 않은 원소가 없을 때 까지
    tmp[idx0++] = a[idx1++];
  while(idx2 < en) // a[mid to en-1]에 사용하지 않은 원소가 없을 때 까지
    tmp[idx0++] = a[idx2++];
  for(int i = st; i < en; i++) a[i] = tmp[i]; // tmp에 임시저장해둔 값을 a로 다시 옮김
}

// a[st to en-1]을 정렬하고 싶다.
void merge_sort(int st, int en){
  if(en-st == 1) return; // 길이 1인 경우
  if(en-st == 2){ // 길이 2인 경우
    if(a[st] > a[st+1]){ // 앞의 원소가 뒤의 원소보다 크면
      int tmp = a[st];
      a[st] = a[st+1];
      a[st+1] = tmp; // 둘을 swap
    }
    return;
  }

  int mid = (st+en)/2;
  merge_sort(st,mid); // st to mid-1을 정렬한다.
  merge_sort(mid,en); // mid to en-1을 정렬한다.
  merge(st,en);
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;  
  for(int i = 0; i < n; i++) cin >> a[i];
  merge_sort(0,n);
  for(int i = 0; i < n; i++) cout << a[i] << '\n';
}

