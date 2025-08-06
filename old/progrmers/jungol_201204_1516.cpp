
// #include <iostream>
// #include <string>
// using namespace std;

// char word[201];
// char cut_word[201][201];
// char end1[4]={'E', 'N', 'D', '\0'};
// int cnt[201]={0};

// void set_word(void){
// 	int i = 0; 
// 	while(word[i] != '\0'){
// 		word[i++] = ' ';
// 	}
// 	word[i]= ' ';
// }

// void set_cut_word(int a){
// 	int i =0;
// 	while(cut_word[a][i] !='\0'){
// 		cut_word[a][i++] = ' ';
// 	}
// 	cut_word[a][i] = ' ';
// }
 
// int what(int a, int b) //어떤 것이 앞 순서인지 판단하는 함수 
// {
// 	int i ;
// 	for(i = 0; ; i++){
// 		if(cut_word[a][i] > cut_word[b][i] || cut_word[b][i]=='\0')
// 			return 1;
// 		else if (cut_word[b][i] > cut_word[a][i] || cut_word[a][i] == '\0')
// 			return 0;
// 	}
// 	return 0;
// }

// void line(int c) //알파벳 순으로 정렬하는 함수 
// {
// 	int i, j ,aa, max;
// 	char temp[50];
// 	for(i = 0; i<c-1; i++){
// 		max = i;
// 		if(cut_word[i][0] != ' '){
// 			for(j = i+1; j<c; j++){
// 				if(what(max,j)==1){
// 					max = j;
// 				}
// 			}
// 			if(max != i){
// 				strcpy(temp, cut_word[i]);
// 				strcpy(cut_word[i],cut_word[max]);
// 				strcpy(cut_word[max], temp);

// 				aa = cnt[i];
// 				cnt[i] = cnt[max];
// 				cnt[max] = aa;
// 			}
// 		}
// 	}
// }


// int cut(void) //단어로 끊어내는 함수 
// {
// 	int i = 0, j = 0, k, a,flag;
// 	char temp[50];

// 	for(k = 0;; k++){ // k루프는 word라는 문자열을 확인하기 위한 루프
// 		if(word[k]== ' '|| word[k] == '\0'){ // 구분자와 널일때 문자열을 split해야한다.
// 			temp[j] ='\0';// 배열temp는 split한 단어를 보관하는 배열

// 			if(strcmp(temp, end1) == 0) // END가 입력되면 종료
// 				return -1;

// 			else if(i>0){ // 변수i는 문자열 split되고 cnt여부를 확인하기 위한 변수
// 				flag = 0; // 변수 flag는 앞에 같은 단어가 존재하는지를 여부를 알기위한 flag변수
// 				for(a = 0; a <i; a++){ // 변수 a는 단어의 철자를 반복
// 					if(strcmp(temp, cut_word[a]) ==0 ){// 앞에 같은 단어가 있을경우
// 						cnt[a]++; // 같은 단어가 존재하면 cnt증가
// 						flag=1;
// 						break;
// 					}
// 				}
// 				if(flag==0){ // flag==0은앞에 같은단어가 존재하지 않는다는 뜻
// 					cnt[i]++;// 
// 					strcpy(cut_word[i++],temp);
// 				}
// 			}
// 			else{ // i < 0 인것은 첫 루프를 의미한다.
// 				cnt[i]++; // split한 문자열의 cnt를 구해야하므로 
// 				strcpy(cut_word[i++],temp); // split한 문자열을 cut_word배열에 복사한다.
// 			}

// 			if(word[k] == '\0') // word의 인덱스를 확인후 탈출할 조건 
// 				break;
			
// 			j = 0; // 변수j는 temp에서 사용할 변수이다. 
// 				   // split하면 새로운 단어를 temp에 넣어야하고 이때문에 j=0으로 초기화 한다.
// 			k++; // k증가시키는 이유는 split하고 구분자
// 		}
		
// 		// 위의 조건문에서 split를 하였으므로 
// 		// k가 증가하였을때 구분자인지 확인하기위한 조건문
// 		if(word[k]!= ' ')
// 			temp[j++] = word[k];
// 	}
// 	return i; // i를 리턴하는이유는 입력받은 word의 split단어가 몇개인지 알수있으므로 
// }

// int main(void)
// {
//     int c=0, i, k;
 
//     while(1)
//     {
// 		set_word();
// 		for(i = 0; i < c ; i++){
// 			set_cut_word(i);
// 			cnt[i] = 0;
// 		}

// 		cin.getline(word,201,'\n');

// 		c = cut();
// 		if(c==-1)
// 		break;
// 		line(c);
// 		for(i = 0; i<c; i++){
// 			cout << cut_word[i] << ":" <<  cnt[i] << '\n';
// 		}
		
// 	}
// 	return 0;
// }

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// stl(sort) 에서 3번째 인자로 함수가 오면 함수명을
// 구조체나 클래스가 오면 구조체() 또는 클래스()를 적어줘야한다.

class op{
	public:
	bool operator()(const pair<string,int> left, const pair<string,int> right)
	{
		return left.first < right.first;
	}
};

int main(){
	string str;
	while(true){
		vector<pair<string, int> > words;
		getline(cin,str);
		
		if(str == "END") break;

		stringstream ss(str);
		string buffer;
		vector<pair<string, int> > ::iterator it;
		while( ss >> buffer){
			bool isMatch = true;
			for(it= words.begin(); it!=words.end(); it++){
				if(it -> first == buffer){
					isMatch = false;
					it->second++;
				}
			}
			if(isMatch)
				words.push_back(make_pair(buffer,1));
		}

		sort(words.begin(), words.end(), op());
		for(it = words.begin(); it!=words.end(); it++){
			cout << it->first << " : " <<it->second <<endl;
		}
	}

	return 0;
}