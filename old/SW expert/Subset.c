#include <stdio.h>
#include <stdlib.h>


int main(void){
	int i,j;
	int arr[]={-7,-3,-2,5,8};
	int n =sizeof(arr)/sizeof(arr[0]);
	// n:원소의개수
	int sum; 
	int ret = 0;
	for(i =1;i <(1<<(n));i++)
	// 1<<n: 부분집합의개수
	{
		sum =0;
		for(j =0;j <n;j++)
		// 원소의수만큼비트를비교함
		{
			if(i &(1<<j))
			// i의j번째비트가1이면j번째원소출력
				{
					sum +=arr[j];
				}

	
		}
		if(sum ==0)
			{ret = 1;
				break;}
	}
	printf("%s\n", ret ? "True": "False");

	// for(int k =0;k <n; k++)
	// 	// 원소의수만큼비트를비교함
	// 	{
	// 		if( 14 &(1<<k))
	// 		// i의j번째비트가1이면j번째원소출력
	// 			{
	// 				printf("%d - ",k);

	// 			}

	// 	}
}
