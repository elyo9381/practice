
//Program.cpp
#include "common.h"

template <typename data, typename compare>

void merge_sort(data *base, size_t n, compare algo)
{
	//���Ұ������� n�� 1���� �۰ų� ������ �����մϴ�. 
	if(n<=1)
	{
		return;
	}
	
	//���ʿ�ҿ� ���ʿ�ҷ� �����մϴ�. 
	size_t h = n/2;
	size_t lh= n-h;
	merge_sort(base,h,algo);
	merge_sort(base+h,lh,algo);
	
	//���� ���� �����Դϴ�. 
	size_t ai = 0;
	size_t bi = h;
	size_t ci = 0;
	
	//�ӽù����Ҵ� 
	data *tbase = new data[n];
	
	while((ai<h)&&(bi<n))
	{
		if(algo(base[ai], base[bi])>0)
		{
			tbase[ci] = base[bi];
			bi++;
		}
		else
		{
			tbase[ci] = base[ai];
			ai++;
		}
		ci++;
	}
	
	while(ai<h)
	{
		tbase[ci] = base[ai];
		ai++;
		ci++;
	}
	
	while(bi<n)
	{
		tbase[ci]= base[bi];
		bi++;
		ci++;
	}
	
	for(ci =0; ci<n;ci++)
	{
		base[ci] = tbase[ci];
		
	}
	delete[] tbase;
}

#define MAX_DATA 100000


int main()
{
    Member *base[MAX_DATA];
    //���� ������ �� �����ϴ��� 
    //10�� ���Ҹ� ��ȣ ������ �����Ͽ� 
    //Ȯ���ϰ� �̸� ������ �����Ͽ� Ȯ���ϼ���.
    MakeRandomMembers(base,10);
    cout<<"���� ��"<<endl;
    ViewMembers(base,10);
    merge_sort(base,10,CompareByNum);
    cout<<"��ȣ�� ���� ��"<<endl;
    ViewMembers(base,10);
    merge_sort(base,10,CompareByName);
    cout<<"�̸����� ���� ��"<<endl;
    ViewMembers(base,10);
    RemoveMembers(base,10);
 
    //�׸��� MAX_DATA ���� �� ���� �ӵ��� 
    //MAX_DATA/10 ���� �� ���� �ӵ��� ���� ������.
    clock_t st,et;
    MakeRandomMembers(base,MAX_DATA);
    cout<<"���� ���� �׽�Ʈ1 �ڷ� ����:"<<MAX_DATA<<endl;
    st = clock();
    merge_sort(base,MAX_DATA,CompareByName);
    et=clock();
    cout<<"���� �ӵ�:"<<et-st<<endl;
    RemoveMembers(base,MAX_DATA);
 
    MakeRandomMembers(base,MAX_DATA/10);
    cout<<"���� ���� �׽�Ʈ2 �ڷ� ����:"<<MAX_DATA/10<<endl;
    st = clock();
    MakeRandomMembers(base,MAX_DATA/10);
    merge_sort(base,MAX_DATA/10,CompareByName);
    et=clock();
    cout<<"���� �ӵ�:"<<et-st<<endl;
    RemoveMembers(base,MAX_DATA/10);
    return 0;
}
