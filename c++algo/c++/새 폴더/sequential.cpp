#include "common.h"
template <typename data, typename compare>
//���� ����(base:�迭�� ���� �ּ�, n: ���� ����, compare:�� ��)
void sequential_sort(data *base, size_t n, compare com)
{
    for(size_t i = 0; i<n; i++) //�ݺ�(i:=0->n)
    {
        for(size_t j=i+1; j<n; j++)//�ݺ�(j:=i+1->n)
        {
            if(com(base[i],base[j])>0)//����(compare(base[i], base[j]) > 0)
            {
                swap(base[i],base[j]); //��ȯ(base[i],base[j])
            }
        }
    }
}
#define MAX_DATA 1000


int main()
{
    Member *base[MAX_DATA];
    MakeRandomMembers(base,10);
    cout<<"���� ��"<<endl;
    ViewMembers(base,10);
    sequential_sort(base,10,CompareByNum);
    cout<<"��ȣ�� ���� ��"<<endl;
    ViewMembers(base,10);
    sequential_sort(base,10,CompareByName);
    cout<<"�̸����� ���� ��"<<endl;
    ViewMembers(base,10);
    RemoveMembers(base,10);
 
    clock_t st,et;
 
    MakeRandomMembers(base,MAX_DATA);
    cout<<"���� ���� �׽�Ʈ1 �ڷ� ����:"<<MAX_DATA<<endl;
    st = clock();    
    sequential_sort(base,MAX_DATA,CompareByName);    
    et=clock();
    cout<<"���� �ӵ�:"<<et-st<<endl;
    RemoveMembers(base,MAX_DATA);
 
    MakeRandomMembers(base,MAX_DATA/10);
    cout<<"���� ���� �׽�Ʈ2 �ڷ� ����:"<<MAX_DATA/10<<endl;
    st = clock();
    MakeRandomMembers(base,MAX_DATA/10);
    sequential_sort(base,MAX_DATA/10,CompareByName);
    et=clock();
    cout<<"���� �ӵ�:"<<et-st<<endl;
    RemoveMembers(base,MAX_DATA/10);
    return 0;
}
