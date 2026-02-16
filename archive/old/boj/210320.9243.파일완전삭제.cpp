#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 
 * 조건
 * 
 * 설계
 * 
 * 
*/

int N;

string firstBit, lastBit;

int main(){
    cin >> N;

    cin >> firstBit >> lastBit;

    if(N % 2 == 0){
          if(firstBit == lastBit){
            cout << "Deletion succeeded"<<"\n";
        } else{
             cout << "Deletion failed"<<"\n";
        }
    }
    else {
        for(int i = 0; i<firstBit.size(); i++){
            if(firstBit[i] == '1'){
                firstBit[i] = '0';
            } 
            else if(firstBit[i] == '0'){
                firstBit[i] = '1';
            }
        }
        if(firstBit == lastBit){
            cout << "Deletion succeeded"<<"\n";
        } else{
            cout << "Deletion failed"<<"\n";
        }
    }    
    


}