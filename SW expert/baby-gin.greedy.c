#include <stdio.h>
#include <stdlib.h>


int main(){
	int input;
	int arr[6]={0,};
	int c[10]={0,};
	int tri=0,run=0;

	scanf("%d", &input);
	// printf("%d", input);
	// for(int i = 0; i<input; i++)
	// {	
	for(int i=0; i<input; i++)
	{
		scanf("%d ", &arr[i]);
	}
		
	// }

	// for(int i=0; i<input; i++)
	// {
	// 	// printf("<C> %d",c[i]);
	// printf("%d\n",c[i]);	
	// }
	// printf("\n");

	for(int i =0; i<input; i++)
	{
		for(int j=0; j<6;j++){
			c[arr[i]%10]++;
			arr[i]/=10;

		}

		// for(int s=0; s<10; s++)
		// {
		// 	printf("%d",c[s]);
		// }
		// printf("\n");

		for(int k =0; k<10; k++)
		{
			if(c[k]>=3)
			{
				c[k] -=3;
				tri+=1;
				k--;
			}
			if((c[k]>=1)&& (c[k+1] >=1)&& (c[k+2] >=1))
			{
				c[k] -=1;
				c[k+1] -=1;
				c[k+2] -=1;
				run +=1;
				k--;
			}

			// printf("tri %d run %d",tri,run);
		}
	
		if(run+tri==2){
			printf("Baby Gin\n");
			tri=0,run=0;}
		else
			printf("Lose");
	}	

	return 0;
}