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
//    cout<<"���� ��"<<endl;
//
//    ViewMembers(base,10);
//
//    heap_sort(base,10,CompareByNum);
//
//    cout<<"��ȣ�� ���� ��"<<endl;
//
//    ViewMembers(base,10);
//
//    heap_sort(base,10,CompareByName);
//
//    cout<<"�̸����� ���� ��"<<endl;
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
//    cout<<"���� ���� �׽�Ʈ1 �ڷ� ����:"<<MAX_DATA<<endl;
//
//    st = clock();   
//
//    heap_sort(base,MAX_DATA,CompareByName);   
//
//    et=clock();
//
//    cout<<"���� �ӵ�:"<<et-st<<endl;
//
//    RemoveMembers(base,MAX_DATA);
//
// 
//
//    MakeRandomMembers(base,MAX_DATA/10);
//
//    cout<<"���� ���� �׽�Ʈ2 �ڷ� ����:"<<MAX_DATA/10<<endl;
//
//    st = clock();
//
//    MakeRandomMembers(base,MAX_DATA/10);
//
//    heap_sort(base,MAX_DATA/10,CompareByName);
//
//    et=clock();
//
//    cout<<"���� �ӵ�:"<<et-st<<endl;
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
//**�����ϰ� **�� � �Լ����� �Ķ���ͷ� *�� �ް� 
// �Լ��� ���뿡�� *�� �ε��� ���� �ǵ帱�� **���  
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

//���� �������� ���� �Ѱ� 
void heap_sort(int *base, int n)
{
	//�������� �ۼ��ؾ��Ѵ�.
	// ���������ǰ�� �ڽ��߿� �θ𺸴� ū���� �����ϸ� �ȵȴ�.
	 
	for( int i=1 ; i<n; i++)
	{
		int j =i;
		
		while(j>0)
		{
			// �θ��� �ε����� ���Ѵ�. 
			int pa = PARENT(j);
			// �ڽ��� ���� �θ��� ������ ũ�� ��ȯ�Ѵ�. 
			if(com(base[j], base[pa]) > 0 )
			{
				
				swap(base[j], base[pa]);
				// �迭�� �θ� ��� Ž���ϱ� ���� ����
				j = pa;
			}
			else
			{
				break;
			}
		}
	}
	
	// �ʱ��� �����̤� ������ ��Ʈ�� ������ �ڼ��� �ڷḦ ��ȯ�ϰ� ���Ĺ����� 1���Դϴ�.
	swap(base[0],base[n-1]);// ��Ʈ�� ������ �ڼ� ��ȯ 
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
			if(lc>=n) //�ڽ��� ���� 
			{
				break;
			}
			
			if(rc == n)// ���� �ڽĸ� ���� 
			{
				//���� �ڽ��� �ڽź��� ��ũ�� ��ȯ 
				if(com(base[me], base[lc])<0)
				{
					swap(base[me],base[lc]);
					break;	
				}
				
				break;
			}
			//���� ������ �ڽ��� �Ѵ� �ְ�
			// ���� ū�ڽ��� ���� Ž�� 
			int bc = lc;
			if(com(base[lc], base[rc])<0)
			{
				bc = rc;
			}
			
			//�ڽŰ� ���Ͽ� ũ�� �ڷḦ ��ȯ�ϰ� �ڽ��� �ε����� ���� 
			if(com(base[bc],base[me])>0)
			{
				swap(base[bc],base[me]);
				me=bc;
				
			}
			else // �ڽ��� �� ũ�� �ʴٸ� ���� �����Ѱ��̹Ƿ� �ݺ��� Ż�� 
			{
				break;
			}
		}
		swap(base[0],base[n-1]); // ��Ʈ�� �������ڼձ�ȯ�� ���� ���� 1���� 
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

