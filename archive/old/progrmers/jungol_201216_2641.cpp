#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
	

*/
struct Box{
    int s,e,w;
    Box(int a, int b, int c){
        s =a;
        e = b;
        w = c;
    }
    bool operator<(const Box &r)const{
        if(s == r.s) return s < r.s;
        return e < r.e;
    }
};

int getBox(int *capacity, int start, int end, int box){
	int min = 2147000000;

	for(int i = start; i<end; i++){
		if(capacity[i] < min) min = capacity[i];
	}

	int result = 0;
	if(min > box) {
		result = box;
	} else {
		result = min;
	}

	for(int i = start ; i<end; i++){
		capacity[i] -= result;
	}

	return result;
}

int main()
{
	vector<Box> delivery;
    int n,k,m;
    cin >> n >> k >> m;

	int *capacity = new int[m+1];

    for(int i = 0; i<m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		delivery.push_back(Box(a,b,c));
		capacity[i] = k;
	}
    sort(delivery.begin(),delivery.end());
    // cout << delivery.size()<<endl;

	int sum = 0;

	for(int i = 0; i< delivery.size();i++){
		int start = delivery[i].s;
		int end = delivery[i].e;
		int box = delivery[i].w;

		sum += getBox(capacity,start,end,box);
	}
	cout << sum;

	delete[] capacity;
	return  0;
}

