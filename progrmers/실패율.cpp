#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int c[501];

bool compare(pair<int, double > a, pair<int,double> b) {
    if(a.second == b.second ) return a.first < b.first;
    return a.second > b.second ;
}


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double> > v;
    
    int length = stages.size();
    
    for(int i = 0; i<stages.size(); i++){
        c[stages[i]]++;
    }
    
    for(int i = 1; i<=N; i++){
        int cnt;
        for(int j = 1; j<=N; j++){
            if(j == i)
                cnt = c[i];
        }
        
        double fail = 0;
        
        if( length >=1){
            fail = (double)cnt/length;
        }
        v.push_back({i,fail});
        length -= cnt;
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i<N; i++){
        answer.push_back(v[i].first);
    }

    return answer;
}