
//Program.cpp
#include "common.h"

template <typename data, typename compare>

void merge_sort(data *base, size_t n, compare algo)
{
	//분할과정에서 n이 1보다 작거나 같으면 종료합니다. 
	if(n<=1)
	{
		return;
	}
	
	//앞쪽요소와 뒤쪽요소로 분할합니다. 
	size_t h = n/2;
	size_t lh= n-h;
	merge_sort(base,h,algo);
	merge_sort(base+h,lh,algo);
	
	//이제 정복 과정입니다. 
	size_t ai = 0;
	size_t bi = h;
	size_t ci = 0;
	
	//임시버퍼할당 
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
    //병합 정렬이 잘 동작하는지 
    //10개 원소를 번호 순으로 정렬하여 
    //확인하고 이름 순으로 정렬하여 확인하세요.
    MakeRandomMembers(base,10);
    cout<<"정렬 전"<<endl;
    ViewMembers(base,10);
    merge_sort(base,10,CompareByNum);
    cout<<"번호로 정렬 후"<<endl;
    ViewMembers(base,10);
    merge_sort(base,10,CompareByName);
    cout<<"이름으로 정렬 후"<<endl;
    ViewMembers(base,10);
    RemoveMembers(base,10);
 
    //그리고 MAX_DATA 개일 때 수행 속도와 
    //MAX_DATA/10 개일 때 수행 속도를 비교해 보세요.
    clock_t st,et;
    MakeRandomMembers(base,MAX_DATA);
    cout<<"수행 성능 테스트1 자료 개수:"<<MAX_DATA<<endl;
    st = clock();
    merge_sort(base,MAX_DATA,CompareByName);
    et=clock();
    cout<<"수행 속도:"<<et-st<<endl;
    RemoveMembers(base,MAX_DATA);
 
    MakeRandomMembers(base,MAX_DATA/10);
    cout<<"수행 성능 테스트2 자료 개수:"<<MAX_DATA/10<<endl;
    st = clock();
    MakeRandomMembers(base,MAX_DATA/10);
    merge_sort(base,MAX_DATA/10,CompareByName);
    et=clock();
    cout<<"수행 속도:"<<et-st<<endl;
    RemoveMembers(base,MAX_DATA/10);
    return 0;
}
