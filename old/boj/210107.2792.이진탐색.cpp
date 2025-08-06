#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/*


*/

int n , m;
bool count(long long mid, vector<long long> &box){
        long long num = 0;

        for(int i = 0; i<m; i++){
                num += box[i] / mid;
                if(box[i] % mid)
                        num++;
        }
        if(num <= n) return true;
        else return false;
}

long long bs(vector<long long> &box, int start, int end){
        long long res =  1e9;
        while(start <= end){
                long long mid = (start+end)/2;
                if(count(mid,box)){
                        res = min(res,mid);
                        end = mid -1;
                } 
                else {
                        start = mid+1;
                }
                
        }
        return res;
}
int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;      
    vector<long long> box;

    long long start = 1, end = 0;

    for(int i = 0; i<m; i++){
        long long num;
        cin >> num;
        end = max(end,num);
        box.push_back(num);
    }
    cout << bs(box,start,end);
}