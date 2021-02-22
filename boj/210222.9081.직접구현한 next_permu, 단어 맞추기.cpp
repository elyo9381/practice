#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

int main()
{
	int N,i;
	string input;
	ostringstream oss;

	cin >> N;

	for(i=0 ; i<N ; i++)
	{
		cin >> input;

        // 다음 순열이 존재하는지 체크한다. 
		if(next_permutation(input.begin(),input.end())) {
				oss << input << endl;
        }
		else { //주어진 단어가 마지막 일때는 이전 순열로 돌아간다. 
			prev_permutation(input.begin(),input.end());
			oss << input << endl;
		}
	}

	cout << oss.str();

	return 0;
}

#include<iostream>
#include<vector>
 
using namespace std;
 
bool next_permutation(int *a, int n){
    int i = n-1;                    // 뒤부터 시작 

    /**
     * // 어디까지가 감소수열인가 a[k]를 찾는다.
     * a[k] < a[k+1]을 찾는다. 
    */
    while(i > 0 && a[i] <= a[i-1])  
        i -= 1;              

    // 전체가 증가수열이다면 더이상 next는 없으므로 리버스 한다. 
    if(i <= 0){                   
        int idx = 0, j = n-1;
        while(idx < j){
            swap(a[idx], a[j]);
            idx +=1;
            j -= 1;
        }
        return false;                
    }                    

    /**
     *  k보다 인덱스가 큰것중 a[k]보다 큰수 a[h]를 찾는다.
     *  이는 사전순으로 큰수를 만들기 위해 a[k]보다 인덱스가 크며 값이 큰수를 찾는것이다.
     *  인덱스 k와 근접한 큰수를 찾게 되면 기존의 수(*a) 와 다음 순열간의 사이의 값이
     *  차이가 크게 벌어진다.
     * 
     *  그러므로 이를 방지하기 위해서 뒤에서 부터 a[k]보다 큰수를 확인한다.
    */
    int j = n-1;
    while(a[i-1] >= a[j])           
        j -= 1; 

    // 확인된 수와 swap한다. 
    // 이는 빠른 속도를 위한 과정
    swap(a[i-1],a[j]);   
    
    /**
     * a[k+1]부터 끝까지 부분수열을 오름차순으로 만들어야한다.
     * 왜냐하면 이를 통해야지 기존의 수(*a)보다 사전순으로 큰수가 만들어지기 때문
     * 
     * 또한 a[k]보다 큰수 a[h] 과정에서
     * a[k+1]부터 끝까지 내림차순이 깨지지 않아 
     * 오름차순하면 사전순을 지키며 다음 순열을 만들수있는것이다. 
     * 
    */
    j = n - 1;           
    while(i < j){        
        swap(a[i],a[j]);
        i +=1;
        j -=1;
    }
    return true;
}

bool perv_permutation(int *a, int n){

    int i = n-1;                   

    // 증가수열 a[k-1] > a[k] 찾기  
    while(i > 0 && a[i] > a[i-1])  
        i -= 1;

    // 전체가 감소수열이면 증가수열은 reverse한것이므로 reverse
    if(i <= 0){                     
        int idx = 0, j = n-1;
        while(idx < j){
            swap(a[idx], a[j]);
            idx +=1;
            j -= 1;
        }
        return false;               
    }                    

    // a[k-1]보다 작은수 a[h] 찾기 
    int j = n-1;
    while(a[j] >= a[i-1])                
        j -= 1;            

    // 사전순으로 작은수를 만들어야하므로 스왑
    swap(a[j],a[i-1]);               

    // a[k] 부터 끝까지 내림차순으로 변경
    j = n - 1;                       
    while(i < j){                    
        swap(a[i],a[j]);
        i +=1;
        j -=1;
    }
    return true;
}
 
int main(){
    int n;
    cin >> n;
    
    int *v = new int[n];
        
    for(int i = 0; i < n; i++)
        v[i] = i+1;
        
    do{                               
        for(int i = 0; i < n; i++)
            cout << v[i] << ' ';
        cout << '\n';
    }while(next_permutation(v,n));

    next_permutation(v,n);

    for(int i = 0; i<n ; i++){
        cout << v[i] << " ";
    }
    cout << "\n";


    perv_permutation(v,n);

    for(int i = 0; i<n ; i++){
        cout << v[i] << " ";
    }
    cout << "\n";



    
    return 0;
}
