#include "common.h"

template <typename data, typename Compare>
void insert_sort(data *base, size_t n, Compare com)
{
	for(size_t i = 1; i<n ; i++){
		for(size_t j=i; j>0 ; j--)
		{
			if(com(base[j-1],base[j])> 0)
			{
				swap(base[j-1] , base[j]);
			}
			else{
				break;
			}
				
		}
	}
}
#define MAX_DATA 100000

int main(void){
	Member *base[MAX_DATA];
	MakeRandomMembers(base,10);
	cout<<"before sort"<<endl;
	ViewMembers(base,10);
	insert_sort(base, 10, CompareByNum);
	cout<<"after num sort"<<endl;
	ViewMembers(base,10);
	insert_sort(base,10,CompareByName);
	cout<<"after name sort"<<endl;
	ViewMembers(base,10);
	RemoveMembers(base,10);


	clock_t st, et;

	MakeRandomMembers(base,MAX_DATA);
	cout<< "<test1> "<<MAX_DATA<<endl;
	st=clock();
	insert_sort(base,MAX_DATA,CompareByName);
	et=clock();
	cout<< "speed "<<et-st<<endl;
	RemoveMembers(base,MAX_DATA);

	MakeRandomMembers(base,MAX_DATA/10);
    cout<<"<test2/10> "<<MAX_DATA/10<<endl;
    st = clock();
    MakeRandomMembers(base,MAX_DATA/10);
    insert_sort(base,MAX_DATA/10,CompareByName);
    et=clock();
    cout<<"speed2 "<<et-st<<endl;
    RemoveMembers(base,MAX_DATA/10);
    return 0;

}
