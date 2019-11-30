#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i,z;
	int numofarr,inputarray[100]={0,};
	int counts[4]={0,};
	int tmp[100]={0,};
	int maxValue=0;
	int* pArr;


	scanf("%d", &numofarr);

	// printf("%d",numofarr);

	pArr = (int*)malloc(sizeof(int)*numofarr);


	for (int i = 0; i <numofarr; i++) 
	{
		scanf("%d", &pArr[i]);
	}

	for (int i = 0; i <numofarr; i++) 
	{
		printf("%d",pArr[i]);
	}	

	printf("\n");
	//각항목들 발생 횟수 세기
	for(int i = 0 ; i < numofarr ; i++) 
	{
		if(maxValue < pArr[i]) 
			maxValue = pArr[i];
		printf("%d <maxValue>",maxValue);
		printf("%d <data>",pArr[i]);
		printf("%d <counts>",counts[i]);
		printf("\n");
		counts[pArr[i]]++;
	}
			
	
	
	for(int i = 1; i<=maxValue; i++)
	{
		counts[i] = counts[i] + counts[i-1];

	}



	for (int i = 0; i <= maxValue; i++) 
	{
		printf("%d",counts[i]);
	}	
	printf("\n");




	for(int i = numofarr -1; i>=0; i--)
	{

		// printf("\n");
		tmp[--counts[pArr[i]]] = pArr[i];
		printf("<maxValue> %d",maxValue);
		printf("<data> %d",pArr[i]);
		printf("<counts> %d",counts[i]);
		printf("<tmp> %d",tmp[i]);
		printf("\n");
		//printf("%d", tmp[i]);
	
	}

	for (int i = 0; i < numofarr; i++) 
	{
		printf("%d",tmp[i]);
	}		


return 0;
}