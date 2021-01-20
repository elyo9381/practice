#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>

#define hash 1000000007LL;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 987654321;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end){
    if(start == end)
        return tree[node] = arr[start];

    int mid = (start + end) / 2;

    return tree[node] = init(arr,tree, node*2, start ,mid)+
                        init(arr,tree, node*2+1, mid +1, end);
}

void update(vector<ll> & tree, int node, int start, int end, int index, ll diff){
    if(!(start <= index && index <= end))
        return;
    
    tree[node] += diff;
    if(start != end){
        int mid = (start + end)/2;
        update(tree,node*2, start, mid, index,diff);
        update(tree,node*2+1, mid+1, end, index,diff);
    }
}

ll sum(vector<ll> &tree, int node, int start, int end,int left, int right){
    if( left > end || right < start)
        return 0;

    if(left <= start && end <= right)   
        return tree[node];

    int mid = (start + end) /2;
    return sum(tree, node*2, start, mid,left,right)+
            sum(tree,node*2+1, mid+1,end, left,right);
}

int main(){
    int n,m,k;

    cin >> n >> m >> k;

    int h = (int)ceil(log2(n));
    int tree_size = (1<< (h+1));

    vector<ll> arr(n);
    vector<ll> tree(tree_size);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    init(arr,tree,1,0,n-1);

    m+=k;

    while(m--){
        int get;
        cin >> get;
        if(get == 1){
            int pos; ll val;
            cin >>  pos >> val;
            ll diff = val - arr[pos-1];
            arr[pos-1] = val;
            update(tree,1,0,n-1,pos-1,diff);
        } 
        else if(get== 2){
            int left, right;
            cin >>  left >> right;
            cout <<  sum(tree,1,0,n-1,left-1,right-1)<< '\n';
        }
    }
    return 0;
}
