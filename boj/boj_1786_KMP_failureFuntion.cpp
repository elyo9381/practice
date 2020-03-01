#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize,0);

    int j = 0;
    for(int i =1; i< patternSize; i++){
        while(j> 0 && pattern[i] != pattern[j]){
            j = table[j-1];

        }

        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }

    return table;
}

void KMP(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    vector<int> occur;
    for(int i = 0; i < parentSize; i++){
        while(j > 0 && parent[i] != pattern[j]){
            j = table[j-1];
        }

        if(parent[i] == pattern[j]) {
            // cout << j << " ";
            // cout <<  patternSize - 1<<endl;
            if(j == patternSize-1) {
                    occur.push_back(i - patternSize +2);
                    j = table[j];
            }
            else
            {
                j++;

            }    
           
        }

    }
    cout<< occur.size() << '\n';
    for( auto e : occur) cout<< e << ' ';

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string T, P;
    getline(cin,T);
    getline(cin,P);

    KMP(T, P);
    return 0;
}

