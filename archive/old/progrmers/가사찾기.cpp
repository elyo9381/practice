#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<string> arr[10001];
vector<string> reversed_arr[10001];


template<typename T>
T* upper_bound(T *arr, T *end, const T& key) {
    int l = 0, r = (int)(end - arr) - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (key < arr[mid]) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return arr + l;
}

template<typename T>
T* lower_bound(T *arr, T *end, const T& key) {
    int l = 0, r = (int)(end - arr) - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] < key) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return arr + l;
}



int countByRange(vector<string> &v, string leftValue, string rightValue){    
    printf("%d\n",upper_bound(v.begin(),v.end(),rightValue)-lower_bound(v.begin(),v.end(),leftValue));
    vector<string>::iterator rigthIndex = upper_bound(v.begin(),v.end(),rightValue);
    vector<string>::iterator leftIndex = lower_bound(v.begin(),v.end(),leftValue);
    
    return upper_bound(v.begin(),v.end(),rightValue) - lower_bound(v.begin(),v.end(),leftValue);
}


string replaceAll(string str,string from,string to){
    string res = str;
        
    int pos = 0;
    while((pos = res.find(from,pos)) != string::npos){
        res.replace(pos,from.size(),to);
     //   cout<< res << '\n';
        pos+= to.size();
    }
    return res;
}

vector<int> solution(vector<string> words, vector<string> queries){
    
    vector<int> answer;
    
    for(int i = 0; i<words.size(); i++){
        string word = words[i];
        arr[word.size()].push_back(word); // 단어를 삽입
        reverse(word.begin(),word.end());
        reversed_arr[word.size()].push_back(word);
    }
    
    
    for(int i = 0; i< 10001; i++){
        sort(arr[i].begin(), arr[i].end());
        sort(reversed_arr[i].begin(),reversed_arr[i].end());
    }
    
    for(int i = 0; i< queries.size(); i++){
        string q = queries[i];
        int res = 0;
        if(q[0] != '?'){
            res = countByRange(arr[q.size()], replaceAll(q, "?","a"), replaceAll(q,"?","z"));
            
        }
        else {
            reverse(q.begin(),q.end());
            res = countByRange(reversed_arr[q.size()], replaceAll(q, "?","a"), replaceAll(q,"?","z"));
        }
    
    answer.push_back(res);
    }
    return answer;
}