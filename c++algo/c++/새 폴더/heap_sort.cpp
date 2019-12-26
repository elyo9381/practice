////Program.cpp
//
//#include "common.h" 
//#define LCHILD(me)	(2*me+1)
//#define RCHILD(me)	(LCHILD(me)+1)
//#define PARENT(me)	((me-1)/2)
//
//template <typename data, typename compare>
//void heap_sort(data *base, size_t n, compare com)
//{
//	for( size_t i=1 ; i<n; i++)
//	{
//		int j =i;
//		
//		while(j>0)
//		{
//			int pa = PARENT(j);
//			if(com(base[j], base[pa]) >0 )
//			{
//				swap(base[j], base[pa]);
//				j = pa;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	
//	swap(base[0],base[n-1]);
//	n--;
//	size_t me;
//	size_t lc;
//	size_t rc;
//	
//	while(n-1)
//	{
//		me = 0;
//		while(1)
//		{
//			lc = LCHILD(me);
//			rc = RCHILD(me);
//			if(lc>=n)
//			{
//				break;
//			}
//			
//			if(rc == n)
//			{
//				if(com(base[me], base[lc])<0)
//				{
//					swap(base[me],base[lc]);
//				}
//				break;
//			}
//			int bc = lc;
//			if(com(base[lc], base[rc])>0)
//			{
//				bc = rc;
//			}
//			
//			if(com(base[bc],base[me])>0)
//			{
//				swap(base[bc],base[me]);
//				me=bc;
//			}
//			else
//			{
//				break;
//			}
//		}
//		swap(base[0],base[n-1]);
//		n--;
//	}
//}
//
//#define MAX_DATA 100000
//
// 
//
//int main()
//{
//
//    Member *base[MAX_DATA];
//
//    MakeRandomMembers(base,10);
//
//    cout<<"정렬 전"<<endl;
//
//    ViewMembers(base,10);
//
//    heap_sort(base,10,CompareByNum);
//
//    cout<<"번호로 정렬 후"<<endl;
//
//    ViewMembers(base,10);
//
//    heap_sort(base,10,CompareByName);
//
//    cout<<"이름으로 정렬 후"<<endl;
//
//    ViewMembers(base,10);
//
//    RemoveMembers(base,10);
//
// 
//
//    clock_t st,et;
//
// 
//
//    MakeRandomMembers(base,MAX_DATA);
//
//    cout<<"수행 성능 테스트1 자료 개수:"<<MAX_DATA<<endl;
//
//    st = clock();   
//
//    heap_sort(base,MAX_DATA,CompareByName);   
//
//    et=clock();
//
//    cout<<"수행 속도:"<<et-st<<endl;
//
//    RemoveMembers(base,MAX_DATA);
//
// 
//
//    MakeRandomMembers(base,MAX_DATA/10);
//
//    cout<<"수행 성능 테스트2 자료 개수:"<<MAX_DATA/10<<endl;
//
//    st = clock();
//
//    MakeRandomMembers(base,MAX_DATA/10);
//
//    heap_sort(base,MAX_DATA/10,CompareByName);
//
//    et=clock();
//
//    cout<<"수행 속도:"<<et-st<<endl;
//
//    RemoveMembers(base,MAX_DATA/10);
//
//    return 0;
//
//}




//Program.cpp
#include <iostream>

#define LCHILD(me)	(2*me+1)
#define RCHILD(me)	(LCHILD(me)+1)
#define PARENT(me)	((me-1)/2)

using namespace std;
//**가능하고 **은 어떤 함수에서 파라미터로 *을 받고 
// 함수의 내용에서 *의 인덱스 값을 건드릴떄 **사용  
int swap(int *a,int *b)
{
	int temp;
	temp = *a;
    *a = *b;
    *b = temp;
    
    return 0;
}

int com(int n1, int n2)
{
	if(n1>n2)
	{
		return 1;
	}
	else if(n1<n2)
	{
		return -1;
	}
	else return 0;
}

//오름 차순으로 정렬 한것 
void heap_sort(int *base, int n)
{
	//최초힙을 작성해야한다.
	// 오름차순의경우 자식중에 부모보다 큰값이 존재하면 안된다.
	 
	for( int i=1 ; i<n; i++)
	{
		int j =i;
		
		while(j>0)
		{
			// 부모의 인덱스를 구한다. 
			int pa = PARENT(j);
			// 자식의 값이 부모의 값보다 크면 교환한다. 
			if(com(base[j], base[pa]) > 0 )
			{
				
				swap(base[j], base[pa]);
				// 배열의 부모를 계속 탐색하기 위한 과정
				j = pa;
			}
			else
			{
				break;
			}
		}
	}
	
	// 초기힙 구성이ㅣ 끝나면 루트와 마지막 자손의 자료를 교환하고 정렬범위를 1줄입니다.
	swap(base[0],base[n-1]);// 루트와 마지막 자손 교환 
	n--;
	int me;
	int lc;
	int rc;

	while(n-1)
	{
		me = 0;
		while(1)
		{
			lc = LCHILD(me);
			rc = RCHILD(me);
			if(lc>=n) //자식이 없음 
			{
				break;
			}
			
			if(rc == n)// 왼쪽 자식만 있음 
			{
				//왼쪽 자식이 자신보다 더크면 교환 
				if(com(base[me], base[lc])<0)
				{
					swap(base[me],base[lc]);
					break;	
				}
				
				break;
			}
			//왼쪽 오른쪽 자식이 둘다 있고
			// 둘중 큰자식을 먼저 탐색 
			int bc = lc;
			if(com(base[lc], base[rc])<0)
			{
				bc = rc;
			}
			
			//자신과 비교하여 크면 자료를 교환하고 자식의 인덱스로 변경 
			if(com(base[bc],base[me])>0)
			{
				swap(base[bc],base[me]);
				me=bc;
				
			}
			else // 자식이 더 크지 않다면 힙을 구성한것이므로 반복문 탈출 
			{
				break;
			}
		}
		swap(base[0],base[n-1]); // 루트와 마지막자손교환후 정렬 범위 1감소 
		n--;
	}
}

#define MAX_DATA 100000

 

int main()
{
	
	int base[5] = {4,3,5,1,2};
	
	heap_sort(base,5);
	
	for(int i =0; i<5 ;i++)
	{
		cout<<base[i]<<" ";
	}
	cout<<endl;

    return 0;

}

