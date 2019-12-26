////Program.cpp
//#include "common.h"
//
//template <typename data, typename compare>
////�� ����(base:�迭�� ���� �ּ�, n: ���� ����, compare:�� ��)
//void quick_sort(data *base, size_t n, compare com)
//{    
//    
//    if(n<=1)//����(n<=1)   
//    {
//        return;//����
//    }
//
//    //�ǹ� ����
//    int pivot = 0; //�ǹ��� ��ġ�� ����ϱ� ���� ����    
//    if(com(base[0],base[n-1])>0)
//    { 
//        if(com(base[0],base[n/2])>0) //base[0]�� ���� ū ��, �� ������ ������ ���� 0��° ���Ұ� �߰� ��
//        {  
//            if(com(base[n/2],base[n-1])>0) //�� �߿� ū ���� �߰� ��
//            {
//                pivot = n/2;
//            }
//            else
//            {
//                pivot = n-1;
//            }
//        }
//    } 
//    else //base[n-1]�� base[0]���� ũ�ų� ����
//    { 
//        if(com(base[n/2],base[n-1])>0)
//        {
//            pivot = n-1; //n-1��° ���Ұ� �߰� ��
//        } 
//        else//n-1��° ���Ұ� ���� ū ��
//        { 
//            if(com(base[n/2],base[0])>0)//�� ������ ������ ���� 0��° ���Ұ� �߰� ��
//            {
//                pivot = n/2;//n/2�� �߰� ��
//            }
//        }
//    }
//     
//    swap(base[0],base[pivot]);//�ǹ��� �� ���� ��� ��ȯ
// 
//    size_t big=0, small=n; //�ǹ����� ū ���� ���� ���� ��ġ�� ã�� ���� ����     
//    while(big<small)//�ݺ�(big<small)
//    { 
//        for(big++; big<n; big++)//�ݺ�(big:=big+1; big<n; big:=big+1)
//        {
//            if(com(base[0],base[big])<0)//����(compare(base[0],base[big])<0)
//            {
//                break;//���� Ż��
//            }
//        } 
//        for(small--; small>0; small--)//�ݺ�(small:small-1;small>0;small:small-1)
//        {
//            if(com(base[0],base[small])>0)//����(compare(base[0],base[small])>0)
//            {
//                break;//���� Ż��
//            }
//        }
//        if(big<small)//        ����(big<small)
//        {
//            swap(base[big],base[small]); //��ȯ(base [big], base [small])            
//        }
//    }
// 
//    swap(base[0],base[small]);//��ȯ(base [0], base [small])    
//
//    quick_sort(base,small,com);//�� ����(base,small, compare)
//    quick_sort(base+big,n-big,com);//�� ����(base+big, n-big, compare)
//}
//
//#define MAX_DATA 100000
//
//int main()
//{	
//    Member *base[MAX_DATA];
//    MakeRandomMembers(base,10);
//    cout<<"���� ��"<<endl;
//    ViewMembers(base,10);
//    quick_sort(base,10,CompareByNum);
//    cout<<"��ȣ�� ���� ��"<<endl;
//    ViewMembers(base,10);
//    quick_sort(base,10,CompareByName);
//    cout<<"�̸����� ���� ��"<<endl;
//    ViewMembers(base,10);
//    RemoveMembers(base,10);
//
//    clock_t st,et;
//
//    MakeRandomMembers(base,MAX_DATA);
//    cout<<"���� ���� �׽�Ʈ1 �ڷ� ����:"<<MAX_DATA<<endl;
//    st = clock();    
//    quick_sort(base,MAX_DATA,CompareByName);    
//    et=clock();
//    cout<<"���� �ӵ�:"<<et-st<<endl;
//    RemoveMembers(base,MAX_DATA);
//
//    MakeRandomMembers(base,MAX_DATA/10);
//    cout<<"���� ���� �׽�Ʈ2 �ڷ� ����:"<<MAX_DATA/10<<endl;
//    st = clock();
//    MakeRandomMembers(base,MAX_DATA/10);
//    quick_sort(base,MAX_DATA/10,CompareByName);
//    et=clock();
//    cout<<"���� �ӵ�:"<<et-st<<endl;
//    RemoveMembers(base,MAX_DATA/10);
//    return 0;
//}
//

//Program.cpp
#include <iostream>
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

//�� ����(base:�迭�� ���� �ּ�, n: ���� ����, compare:�� ��)
void quick_sort(int *base, int n)
{    
    int temp;
    if(n<=1)//����(n<=1)   
    {
        return;//����
    }

    //�ǹ� ����
    int pivot = 0; //�ǹ��� ��ġ�� ����ϱ� ���� ����    
    if(com(base[0],base[n-1])>0)
    { 
        if(com(base[0],base[n/2])>0) //base[0]�� ���� ū ��, �� ������ ������ ���� 0��° ���Ұ� �߰� ��
        {  
            if(com(base[n/2],base[n-1])>0) //�� �߿� ū ���� �߰� ��
            {
                pivot = n/2;
            }
            else
            {
                pivot = n-1;
            }
        }
    } 
    else //base[n-1]�� base[0]���� ũ�ų� ����
    { 
        if(com(base[n/2],base[n-1])>0)
        {
            pivot = n-1; //n-1��° ���Ұ� �߰� ��
        } 
        else//n-1��° ���Ұ� ���� ū ��
        { 
            if(com(base[n/2],base[0])>0)//�� ������ ������ ���� 0��° ���Ұ� �߰� ��
            {
                pivot = n/2;//n/2�� �߰� ��
            }
        }
    }
     
    swap(base[0],base[pivot]);//�ǹ��� �� ���� ��� ��ȯ
//    temp = base[0];
//    base[0] = base[pivot];
//    base[pivot] = temp;
    
    
//    cout<<"pivot and n= "<<n<<endl;
//	for(int i=0;i<5; i++)
//    {
//        cout<<base[i]<<" ";
//    }
//    cout<< endl;
    
 
    int big=0, small=n; //�ǹ����� ū ���� ���� ���� ��ġ�� ã�� ���� ����     
    while(big<small)//�ݺ�(big<small)
    { 
        for(big++; big<n; big++)//�ݺ�(big:=big+1; big<n; big:=big+1)
        {
            if(com(base[0],base[big])<0)//����(compare(base[0],base[big])<0)
            {
                break;//���� Ż��
            }
        } 
        for(small--; small>0; small--)//�ݺ�(small:small-1;small>0;small:small-1)
        {
            if(com(base[0],base[small])>0)//����(compare(base[0],base[small])>0)
            {
                break;//���� Ż��
            }
        }
        if(big<small)//        ����(big<small)
        {
        	
//        	cout<<"in whilie before swap and n= "<<n<<endl;
//				for(int i=0;i<5; i++)
//			    {
//			        cout<<base[i]<<" ";
//			    }
//			    cout<< endl;        
			    
//           temp = base[big];
//           base[big] = base[small];
//           base[small] = temp; 
			swap(base[big], base[small]);
		     
//			cout<<"in whilie after swap and n= "<<n<<endl;
//			cout<<"big "<<big<<" small "<<small<<endl;
//				for(int i=0;i<5; i++)
//			    {
//			        cout<<base[i]<<" ";
//			    }
//			    cout<< endl;          
        }
    }
 	
	swap(base[0],base[small]); 	
// 	temp = base[0];
//    base[0] = base[small];
//    base[small] = temp;
//    
//    cout<<"after while and n= "<<n<<endl;
//	for(int i=0;i<5; i++)
//    {
//        cout<<base[i]<<" ";
//    }
//    cout<< endl;
// 	cout<<"after while !! big "<<big<<" small "<<small<<endl;
//    swap(base[0],base[small]);//��ȯ(base [0], base [small])    

    quick_sort(base,small);//�� ����(base,small, compare)
    quick_sort(base+big,n-big);//�� ����(base+big, n-big, compare)
}

#define MAX_DATA 100000

int main()
{	
    int base[5]={5,4,3,2,1};
    
    quick_sort(base,5);
    for(int i=0;i<5; i++)
    {
        cout<<base[i]<<" ";
    }
    cout<< endl;
    return 0;
}


