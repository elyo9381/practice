#include "common.h"
template <typename data, typename compare>
//순차 정렬(base:배열의 시작 주소, n: 원소 개수, compare:비교 논리)
void sequential_sort(data *base, size_t n, compare com)
{
    for(size_t i = 0; i<n; i++) //반복(i:=0->n)
    {
        for(size_t j=i+1; j<n; j++)//반복(j:=i+1->n)
        {
            if(com(base[i],base[j])>0)//조건(compare(base[i], base[j]) > 0)
            {
                swap(base[i],base[j]); //교환(base[i],base[j])
            }
        }
    }
}
#define MAX_DATA 1000


int main()
{
    Member *base[MAX_DATA];
    MakeRandomMembers(base,10);
    cout<<"정렬 전"<<endl;
    ViewMembers(base,10);
    sequential_sort(base,10,CompareByNum);
    cout<<"번호로 정렬 후"<<endl;
    ViewMembers(base,10);
    sequential_sort(base,10,CompareByName);
    cout<<"이름으로 정렬 후"<<endl;
    ViewMembers(base,10);
    RemoveMembers(base,10);
 
    clock_t st,et;
 
    MakeRandomMembers(base,MAX_DATA);
    cout<<"수행 성능 테스트1 자료 개수:"<<MAX_DATA<<endl;
    st = clock();    
    sequential_sort(base,MAX_DATA,CompareByName);    
    et=clock();
    cout<<"수행 속도:"<<et-st<<endl;
    RemoveMembers(base,MAX_DATA);
 
    MakeRandomMembers(base,MAX_DATA/10);
    cout<<"수행 성능 테스트2 자료 개수:"<<MAX_DATA/10<<endl;
    st = clock();
    MakeRandomMembers(base,MAX_DATA/10);
    sequential_sort(base,MAX_DATA/10,CompareByName);
    et=clock();
    cout<<"수행 속도:"<<et-st<<endl;
    RemoveMembers(base,MAX_DATA/10);
    return 0;
}
