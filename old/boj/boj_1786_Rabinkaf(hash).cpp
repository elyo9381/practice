
// 라빈카프를 이용하면 문자열을 소수와 원시근을 통해서 a가 p의 원시근일경우 
// 앞의 문자열에 원시근을 곱한값과 패턴기준으로 타켓의 뒤쪽 문자열과 원시근을 통해서 해쉬값을 구할수잇고 
// 이를 통해서 문자열을 구할수있다.


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 10^9에 가까운 두 개의 수를 곱하는 작업이 반복되기 때문에 long long으로 선언하는 것이 편함. 굳이 int로 하고 싶으면 type casting을 계속 해줘야 함
ll a = 302;
ll p = 1000000007;
ll pow_a[1000001]; // pow_a[i] : a의 i승
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string T,P;
  pow_a[0] = 1;
  for(int i = 1; i < 1000001; i++) pow_a[i] = pow_a[i-1] * a % p;
  getline(cin, T);
  getline(cin, P);
  int lenT = T.size(), lenP = P.size();  
  if(lenT < lenP){
    cout << 0;
    return 0;
  }
  int hash_pattern = 0;
  for(int i = 0; i < lenP; i++)
    hash_pattern = (hash_pattern+P[i]*pow_a[lenP-1-i])%p;
  
  int hash_target = 0;
  for(int i = 0; i < lenP; i++)
    hash_target = (hash_target+T[i]*pow_a[lenP-1-i])%p;

  vector<int> ans;
  if(hash_target == hash_pattern) ans.push_back(1);
  for(int i = 1; i <= lenT-lenP; i++){
    // target 가장 앞에 있는 문자를 빼준다.
    hash_target = (hash_target-pow_a[lenP-1]*T[i-1])%p;

    if(hash_target < 0) hash_target += p; // 음수를 p로 나눈 나머지는 음수이기 때문에 이 처리가 반드시 필요함
    
    // 소수를 곱한다.
    hash_target = hash_target * a % p;
    // 추가된 문자열의 해쉬값을 구해서 더한다. 
    hash_target = (hash_target+T[i+lenP-1])%p;
    
    if(hash_target == hash_pattern) ans.push_back(i+1);
  }
  cout << ans.size() << '\n';
  for(auto e : ans) cout << e << ' ';
}


//  parentSize - patternSize 전체 위치에서 검사하겠다.
// #include <iostream>

// using namespace std;

// void findString(string parent, string pattern){
//   int parentSize = parent.size();
//   int patternSize = pattern.size();
//   int parentHash = 0, patternHash = 0, power =1;

//   for(int i = 0 ; i<= parentSize - patternSize; i++){
//     if(i == 0){
//       for(int  j = 0; j< patternSize; j++){
//         parentHash = parentHash + parent[patterntSize -1 -j] *power;
//         patternHash = patternHash + pattern[patternSize -1 -j] * power;
//         if(j < patternSize -1) power = powe*2;
//       }

//     } else {
//       parentHash = 2 * (parentHash - parent[i-1] * power) + parent[patternSize -1 + i];
//     }

//     if(parentHash == patternhash){
//       bool finded = true;
//       for(int j = 0; j< patternSize; j++){
//         if(parent[i+j] != pattern[j]){
//           finded = false;
//           break;
//         }
//       }
//       if(finded) {
//         printf("%d번째에서 발견했습니다. \n", i +1);
//       }
//     }
//   }
// }


// int main(void){
//   string parent = "";
//   string pattern = "";
//   findString(parent, pattern);
//   return 0;
// }
