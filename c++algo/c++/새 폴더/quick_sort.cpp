////Program.cpp
//#include "common.h"
//
//template <typename data, typename compare>
////퀵 정렬(base:배열의 시작 주소, n: 원소 개수, compare:비교 논리)
//void quick_sort(data *base, size_t n, compare com)
//{    
//    
//    if(n<=1)//조건(n<=1)   
//    {
//        return;//종료
//    }
//
//    //피벗 선택
//    int pivot = 0; //피벗의 위치를 기억하기 위한 변수    
//    if(com(base[0],base[n-1])>0)
//    { 
//        if(com(base[0],base[n/2])>0) //base[0]이 제일 큰 값, 이 조건인 거짓일 때는 0번째 원소가 중간 값
//        {  
//            if(com(base[n/2],base[n-1])>0) //둘 중에 큰 값이 중간 값
//            {
//                pivot = n/2;
//            }
//            else
//            {
//                pivot = n-1;
//            }
//        }
//    } 
//    else //base[n-1]이 base[0]보다 크거나 같음
//    { 
//        if(com(base[n/2],base[n-1])>0)
//        {
//            pivot = n-1; //n-1번째 원소가 중간 값
//        } 
//        else//n-1번째 원소가 제일 큰 값
//        { 
//            if(com(base[n/2],base[0])>0)//이 조건인 거짓일 때는 0번째 원소가 중간 값
//            {
//                pivot = n/2;//n/2가 중간 값
//            }
//        }
//    }
//     
//    swap(base[0],base[pivot]);//피벗과 맨 앞의 요소 교환
// 
//    size_t big=0, small=n; //피벗보다 큰 값과 작은 값의 위치를 찾기 위한 변수     
//    while(big<small)//반복(big<small)
//    { 
//        for(big++; big<n; big++)//반복(big:=big+1; big<n; big:=big+1)
//        {
//            if(com(base[0],base[big])<0)//조건(compare(base[0],base[big])<0)
//            {
//                break;//루프 탈출
//            }
//        } 
//        for(small--; small>0; small--)//반복(small:small-1;small>0;small:small-1)
//        {
//            if(com(base[0],base[small])>0)//조건(compare(base[0],base[small])>0)
//            {
//                break;//루프 탈출
//            }
//        }
//        if(big<small)//        조건(big<small)
//        {
//            swap(base[big],base[small]); //교환(base [big], base [small])            
//        }
//    }
// 
//    swap(base[0],base[small]);//교환(base [0], base [small])    
//
//    quick_sort(base,small,com);//퀵 정렬(base,small, compare)
//    quick_sort(base+big,n-big,com);//퀵 정렬(base+big, n-big, compare)
//}
//
//#define MAX_DATA 100000
//
//int main()
//{	
//    Member *base[MAX_DATA];
//    MakeRandomMembers(base,10);
//    cout<<"정렬 전"<<endl;
//    ViewMembers(base,10);
//    quick_sort(base,10,CompareByNum);
//    cout<<"번호로 정렬 후"<<endl;
//    ViewMembers(base,10);
//    quick_sort(base,10,CompareByName);
//    cout<<"이름으로 정렬 후"<<endl;
//    ViewMembers(base,10);
//    RemoveMembers(base,10);
//
//    clock_t st,et;
//
//    MakeRandomMembers(base,MAX_DATA);
//    cout<<"수행 성능 테스트1 자료 개수:"<<MAX_DATA<<endl;
//    st = clock();    
//    quick_sort(base,MAX_DATA,CompareByName);    
//    et=clock();
//    cout<<"수행 속도:"<<et-st<<endl;
//    RemoveMembers(base,MAX_DATA);
//
//    MakeRandomMembers(base,MAX_DATA/10);
//    cout<<"수행 성능 테스트2 자료 개수:"<<MAX_DATA/10<<endl;
//    st = clock();
//    MakeRandomMembers(base,MAX_DATA/10);
//    quick_sort(base,MAX_DATA/10,CompareByName);
//    et=clock();
//    cout<<"수행 속도:"<<et-st<<endl;
//    RemoveMembers(base,MAX_DATA/10);
//    return 0;
//}
//

//Program.cpp
#include <iostream>
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

//퀵 정렬(base:배열의 시작 주소, n: 원소 개수, compare:비교 논리)
void quick_sort(int *base, int n)
{    
    int temp;
    if(n<=1)//조건(n<=1)   
    {
        return;//종료
    }

    //피벗 선택
    int pivot = 0; //피벗의 위치를 기억하기 위한 변수    
    if(com(base[0],base[n-1])>0)
    { 
        if(com(base[0],base[n/2])>0) //base[0]이 제일 큰 값, 이 조건인 거짓일 때는 0번째 원소가 중간 값
        {  
            if(com(base[n/2],base[n-1])>0) //둘 중에 큰 값이 중간 값
            {
                pivot = n/2;
            }
            else
            {
                pivot = n-1;
            }
        }
    } 
    else //base[n-1]이 base[0]보다 크거나 같음
    { 
        if(com(base[n/2],base[n-1])>0)
        {
            pivot = n-1; //n-1번째 원소가 중간 값
        } 
        else//n-1번째 원소가 제일 큰 값
        { 
            if(com(base[n/2],base[0])>0)//이 조건인 거짓일 때는 0번째 원소가 중간 값
            {
                pivot = n/2;//n/2가 중간 값
            }
        }
    }
     
    swap(base[0],base[pivot]);//피벗과 맨 앞의 요소 교환
//    temp = base[0];
//    base[0] = base[pivot];
//    base[pivot] = temp;
    
    
//    cout<<"pivot and n= "<<n<<endl;
//	for(int i=0;i<5; i++)
//    {
//        cout<<base[i]<<" ";
//    }
//    cout<< endl;
    
 
    int big=0, small=n; //피벗보다 큰 값과 작은 값의 위치를 찾기 위한 변수     
    while(big<small)//반복(big<small)
    { 
        for(big++; big<n; big++)//반복(big:=big+1; big<n; big:=big+1)
        {
            if(com(base[0],base[big])<0)//조건(compare(base[0],base[big])<0)
            {
                break;//루프 탈출
            }
        } 
        for(small--; small>0; small--)//반복(small:small-1;small>0;small:small-1)
        {
            if(com(base[0],base[small])>0)//조건(compare(base[0],base[small])>0)
            {
                break;//루프 탈출
            }
        }
        if(big<small)//        조건(big<small)
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
//    swap(base[0],base[small]);//교환(base [0], base [small])    

    quick_sort(base,small);//퀵 정렬(base,small, compare)
    quick_sort(base+big,n-big);//퀵 정렬(base+big, n-big, compare)
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


