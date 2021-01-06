#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/* #include <unorderd_map>

	언더맵은 생성과정에서 정렬을 하지 않기 때문에 메모리상에서 절약을 한다.
	if(strMap.end() == strMap.find(elem))
	

	string solutino(vector<string> participant, vector<string> completion) {
		string answer = "";
		unordered_map<string, int> strMap;
		for(auto elem : completion){
			if(strMap.end() == strMap.find(elem))
				strMap.insert(make_pair(elem,1));
		}

		for(auto elem : paricipant){
			if(strMap.end() == strMap.find(elem)){
				answer = elem;
				break;
			} else {
				strMap[elem]--;
				if(strMap[elem] < 0){
					answer = elem;
					break;
				}
			}
		}
		return answer;
	}
	
*/

/*  #include <map> 
	map<key,value> key와 value를 pair형태로 선언합니다.
	begin(), end() : iterator를 반환

	insert(make_pair(key,value)) : 맵의 원소를 pair형태로 추가
	erase(key) : 맵에서 key(키값)에 해당하는 원소 삭제
	clear(): 맵의 원소들 모두삭제

	find(key) : key에 해당하는 iterator를 반환
	count(key) : key값에 해당하는 원소들(value들)의 갯수를 반환
*/


int main(){

	//map 은 string을 인덱스로 활용할 수 있다.
	//<string,int> => <key,value>

	map<string,int> m;


	m.insert(make_pair("a",1));
	m.insert(make_pair("b",2));
	m.insert(make_pair("c",3));
	m.insert(make_pair("d",4));
	m.insert(make_pair("e",5));

	m["f"] = 6; // also possible


	// erase(key)
	m.erase("d");
	m.erase("e");
	m.erase(m.find("f")); // also possible


	// empty(), size()
	if(!m.empty()) cout << "m size: " << m.size() <<'\n';



	// m.find("a") 하면 iterator를 반환하기 때문에 second값을 출력할때는 ->를 사용한다.

	cout << "a : " << m.find("a") ->  <<'\n';
	cout << "b : " << m.find("b") -> second << '\n';


	//count(key)
	cout << "a count : " << m.count("a") <<'\n';
	cout << "b count : " << m.count("b") << '\n';

	//begin(), end()

	cout << "traverse" << '\n';
	// map<string,int> :: iterator it // also possible
	for(auto it = m.begin(); it!=m.end(); it++){
		cout << "key : " << it->first << " " << "value : " << it->second << '\n';
	}

	// 변수.c_str()은 리턴값이 const char * p 이다.
	/*   01
		std::string str = "I want to convert string to char*";
		std::vector<char> writable(str.begin(), str.end());
		writable.push_back('\0');
		char* ptr = &writable[0];
		std::cout << ptr;

		-------
		02
		std::string str = "I want to convert string to char*";;
		char * writable = new char[str.size() + 1];
		std::copy(str.begin(), str.end(), writable);
		writable[str.size()] = '\0'; // 스트링 끝에 0을 추가해주는 거 잊지 마세요
		delete[] writable;
	*/ 
	/* 01 과 같은 방법으로 string을 char* 로 바꾸려면 위와같은 방법을 사용한다. 또는 
	   02 와 같은 방법으로 동적 할당 받아서 동적으로 할당받은곳에 str.begin() ~ end()를 카피하고 '\0'을 넣는다. 
	*/ 

	const char * str = m.begin()->first.c_str();
	printf("%s\n", str);
	cout <<str <<endl;
		// 형변환 string to char* : 변수.c_str();
		// 
		// printf("%s", m.end()->first.c_str());

	// string to char *  to int
	// atoi(str.c_str());




	return 0;


	/*
	
	#include <iostream>
	#include <algorithm>
	#include <map>
	
	using namespace std;
	
	map<int, long long int> MapArr;
	map<int, long long int>::iterator Lower_bound;
	map<int, long long int>::iterator Upper_bound;
	
	int main(void) {
		ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, temp;
    long long int ret = 0;
 
    MapArr.insert(pair<int, long long int>(0, -1));
    MapArr.insert(pair<int, long long int>(300001, -1));
    cin >> N;
 
    for (int i = 0; i < N; i++) {
        cin >> temp;
        long long int depth = 0;
		// --MapArr.lower_bound(temp) -- 붙이는 이유
		// map에서 lower_bound는 오른쪽 노드에서 가장 작은값을 반환한다.
		// 왼쪽 노드로 가려면 ???  -- 붙이면된다.
		// map의 컨테이너에 temp가 없으면 오른쪽 노드의 가장 작은값(본인포함)을 반환한다. lower_bound
		// upper_bound는 temp다음 노드 반환
		// 파라미터가 없으면 map::end()로 간다 ex) n이 8인데 키는 19이런식으로  사용할시 
        Lower_bound = (--MapArr.lower_bound(temp));
        Upper_bound = (MapArr.upper_bound(temp));
        depth = max(Lower_bound->second, Upper_bound->second) + 1;
        MapArr.insert(pair<int, long long int>(temp, depth));
        ret += depth;
        cout << ret << "\n";
    }
 
    return 0;

	*/
}