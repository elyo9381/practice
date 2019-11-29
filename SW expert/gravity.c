#include <stdio.h>

#define EMPTY 0
#define BOX 1
// 배열 놓은때 가로세로 기억할것 가로가 i일때 세로 j1234가 오는것
int main()
{
	int i;
	int testCase, T;

	int roomWidth, roomHight;
	int maxFallen;

	int room[100][100] = { EMPTY,};
	int boxTop[100] = { 0,};
	int countEmptySpace;
	// testCase input
	scanf("%d", &testCase);

	for(T=0; T< testCase; T++)
	{
		// room size input 
		// when roomwidth is 0 , j put 1,2,3,4
		scanf("%d %d", &roomWidth, &roomHight);
		maxFallen = 0;
		for(int i= 0 ; i<roomWidth; i++)
		{

			scanf("%d",&boxTop[i]);
			for(int j= 0; j < roomHight; j++)
			{
				room[i][j] = BOX;
				printf("%d",room[i][j]);

			}
			printf("\n");
		}
			for(int i = 0; i < roomWidth ; i++)
			{
				if(boxTop[i]){
					countEmptySpace = 0;
					for(int j = i+1; j <roomWidth ; j++)
					{
						// 90도 돌아가있다고 생각하고 최상위에 있는칸 옆에 있는 칸들의 수를 센다 
						if(room[j][boxTop[i]-1]== EMPTY)
						{
							countEmptySpace +=1;
						}
					}
					if( countEmptySpace > maxFallen)
					{
						maxFallen = countEmptySpace;
					}
				}

			}
		printf("%d\n",maxFallen);
		
	}
}