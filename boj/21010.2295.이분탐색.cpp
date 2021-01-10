// #include <iostream>
// #include <vector>
// #include <algorithm>
// typedef long long ll;
// using namespace std;
// const int MAX = 100001;

// int n;
// vector<int> vec;

// int func(vector<int> &vec, int x){
//     int sum = 0;

//     if( (x - 3) < 0) return 1;
//     for(int i = x-3; i<x; i++){
//         sum+=vec[i];
//     }    

//     if (sum >= vec[x]) return 1;
//     else return 0;

    
// }
// int main(){

//     cin >> n;
//     vec.resize(n,0);

//     for(int i = 0; i<n ;i++){
//         int num
//         cin >> num;
//         vec.push_back(num);
//     }

//     sort(vec.begin(),vec.end());
//     int lv = 0, rv = vec.size()-1;

//     while(lv <= rv){
//         int mid = (lv + rv) / 2;
//         if(func(vec,mid) == 1) {
//             lv = mid +1;
//         }
//         else{
//             rv = mid -1;
//         } 
//     }
//     cout << rv << '\n';
// }

#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 1010
int data1[MAX], data2[MAX*MAX], cnt=0, N;
int main()
{
    int i, j;
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &data1[i]);
    }
    std::sort(data1 + 1, data1 + 1 + N);
    for (i = 1; i <= N; i++)
    {
        for (j = i; j <= N; j++)
        {
            data2[++cnt] = data1[i] + data1[j];
        }
    }
    std::sort(data2 + 1, data2 + 1 + cnt);
    for (i = N; i >= 1; i--)
    {
        for (j = i; j >= 1; j--)
        {
            if (std::binary_search(data2 + 1, data2 + cnt + 1, data1[i] - data1[j]))
            {
                // cout << i << j << '\n';
                printf("%d", data1[i]);
                break;
            }
        }
        if (j != 0)
        {
            break;
        }
    }
    return 0;
}
