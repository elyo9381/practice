#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
	동전 자판기
*/
int arr[10],n,l[10],cost[10]={0,500,100,50,10,5,1};
int main()
{
    int i,cnt=0,sum=0;
	cin >> n;
    for(i=1;i<=6;i++){
		cin >> arr[i];
        sum+=arr[i]*cost[i];
    }
    n=sum-n;
    for(i=1;i<=6;i++){
        int temp=min(arr[i],n/cost[i]);
        n-=cost[i]*temp;
        l[i]=temp;
    }
    for(i=1;i<=6;i++) cnt+=arr[i]-l[i];
	cout << cnt << "\n";
    for(i=1;i<=6;i++){
		cout << arr[i] - l[i] << " " ;
    }
    return 0;
}

