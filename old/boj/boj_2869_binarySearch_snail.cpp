#include <iostream>
#include <vector>	
#include <queue>
#include <algorithm>

    // 날짜에 대해서 이분탐색을 실행한다. 
    // 1번째 날부터 최대 5일까지이므로 
    // 날짜에 대해서 이분탐색을 yes/no로 판별하려고 할때이다. 
    // 그렇다면 날짜별로 어떻게 이분탐색을 진행하는가 ? 
    // 일반적인 이분탐색을 진행한다. 
    // left = 1, right = v로 진행하여서 
    // binarySearch(int left, int right)
    // {
    //     if(left <= right)
    //     {
    //         int mid = (left + right) /2;
    //         accetable_date = mid * (A-B);
    //         if_final_data_ = mid + A;

    //         if( if_final_date > V){
    //             ret = mid;
    //             binarySearch(left, mid -1);
    //         }
    //         else
    //         {
    //             binarySearch(mid+1, right);
    //         }
    //     }
    // }
    // mid는 체크를 당담하는 날이고 만약에 mid가 마지막날이라면 +A를 더해준 날이 V를 넘겨야한다. 
    // 그렇기 그렇기 때문에 이를 바탕으로 조건을 남기면 이분탐색으로 문제풀 풀수있다. 
    // left와 right는 첫날과 마지막날이므로 조건을 left<=right임을 명시해야한다. 
    
long long A, B, V;
long long y1, y2, mid = 0, result =0;

// void binarySearch(long long left, long long right) {  // left  = 1; right = V 일때
// 	if (left <= right) {
// 		mid = (left + right) / 2;
// 		y2 = (mid) * ((A - B)+B);
// 		if (y2 >= V) {
// 			result = mid;
// 			binarySearch(left, mid-1);
// 		}
// 		else 
//         {
// 			binarySearch(mid+ 1, right);
// 		}
// 	}
// }

void binarySearch (long long left, long long right)
{
    while(left <= right)
    {
        mid = (left + right) /2;
        if( V <= (mid-1) * (A-B)+A)
        {
            right = mid -1;
            result  = mid;
        }
        else
        {
            left = mid +1;
        }
        

    }
    

}
int main(void) {
	scanf("%lld %lld %lld", &A, &B, &V);
	long long left, right;
	left = 0; right = V;
	binarySearch(left, right);
	printf("%lld", result);
}


// int a[n], k;
// // 재귀적인 binary_search
// int binary_search(int s, int e)
// {
//     if(s == e)
//     {
//         if(a[s] == k) return s;
//         else return 0;
//     }

//     int mid  = (s+e)/2;
//     if(a[mid] >= k) return binary_search(s,mid);
//     else return binary_search(mid+1,e);
// }
// //while 을 이용한 binary_search
// int binary_search()
// {
//     int s = 0, e = n-1;
//     while(s<e)
//     {
//         int mid = (s+e)/2;
//         if(a[mid] >= k) e = mid;
//         else s  = mid+1;
//     }

//     if(a[s] == k ) return s;
//     else return NULL;
// }
