#include <stdio.h>
#include <stdlib.h>

int coins[] = {500, 250, 100, 50, 10};
int count[5];
int money;
int i= 0;

int main()
{
	scanf("%d",&money);

	while(money != 0){
		if(money <0){
			count[i]--;
			money +=coins[i++];
		}
		else
		{
			count[i]++;
			money -= coins[i];
		}
	}

	for (int i =0; i <5; i++){
		printf("%d  : %d\n",coins[i],count[i] );
	}
return 0;
}