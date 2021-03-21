#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 
 * 조건
 * 2+1세일
 * 유제품 3개 산가면 가장싼것은 무료 나머지 두개 제품 가격지불
 * 한번에 3개의 유제품을 사지 않는다면 할인없음 
 * N팩 구입할때 최소비용 유제품 구입할수있도 하자 
 * 
 * 설계
 * 오름차순 정렬후 왼쪽에서는 2개의 인덱스를 지나는 포인터,
 *              오른쪽에서는 1개의 인덱스를 지나는 포인터를 통해 그룹을 형성한다. 
 * l>=r이 되면 종료한다.  : fail
 * 
 * 디버그 
 * 두가지 포인터를 사용해서 결국 구현을 못했다. 
 * 높은 하나를 선택하고 낮은 두개를 선택해야하는데 결국 빠지는 수는 가장 낮은 수이다. 
 * 내림차순하고 가장 낮은 수를 빼면 가장싼것이 빠진다.
 * 
*/

int n;
int arr[100001];

bool compare(int a, int b){
    return a > b;
}

int main(){

    cin >> n; 
    for(int i= 0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n, compare);
    int cost = 0;
    for(int i = 0; i<n; i++){
        if(i % 3 == 2){
            continue;
        }
        cost += arr[i];
    }
    cout << cost <<"\n";
}