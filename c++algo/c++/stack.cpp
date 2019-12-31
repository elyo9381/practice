//스택
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Stack
{
	//스택에는 자료를 보관할 저장소가 필요합니다.
	int *buffer;
	// 저장소의 크기를 기억하는 멤버를 선언하세요.
	const int size;
	//가장 최근에 보관한 자료의 위치를 인덱스로 기억하는 멤버
	int top;
public:
	//생성자는 스택 크기를 입력 인자로 받게 합니다.
	Stack(int size):size(size){
		top = -1;
		buffer = new int[size];
	} 
	~Stack()
	{
		delete[] buffer;		
	}
	
	bool Push(int data)
	{
		//push 연산은 먼저 꽉 찼는지 확인합니다. 
		if(IsFull())
		{
			// 만약 꽉 차면 보관 할 수 없겠죠. 
			return false;
		}
		//top를 다음 위치로 이동합니다. 
		top++;
		// buffer의 top 인덱스 위칭 data를 보관하세 
		buffer[top] = data;
		return true;
	 }
	 
	 int Pop()
	 {
	 	if(IsEmpty())
	 	{
	 		//여기에는 0을 반환할게요.
			 //목적ㅇ 따라 예외를 던지는 형태로 구현할 수도 있겠지요
			 return -1; 
		 }
		 //buffer 의 top 인덱스 위치에 보관한 값을 반환 할 변수에 대입하세요
		 int re = buffer[top];
		 //top 위치를 1 감소 합니다.
		 top--;
		 return re; 
	  }
	bool IsFull()
	{
		// 스택의top는 -1이 초기값이므로 top+1이 size와 같으면 꽉찬것 
		return (top+1) == size;
	}
	bool IsEmpty()
	{
		return top == -1; 
	}
	
};
	
int main()
{
//  stack 직접 구현 
//	Stack st(10);
//	
//	st.Push(4); 
//	st.Push(7);
//	st.Push(8);
//	st.Push(2);
//	
//	while(st.IsEmpty() == false)
//	{
//		cout<<st.Pop()<<" ";		
//	}
//	cout<<endl;

 	//템플릿 클래스이므로 템플릿 형식 인자로 보관할 형식을 나타내야겠죠.
 	vector<int> v;
    stack<int,vector<int> > st;//int 형식을 보관하는 스택
      
 	
 	v.push_back(3);
 	v.push_back(4);
 	v.push_back(5);
 	v.push_back(6);
 	
 	
    //보관하는 메서드는 push입니다.
//    st.push(4); //4
//    st.push(7); //4 7
//    st.push(8); //4 7 8
//    st.push(2); //4 7 8 2
 	st.push(1);
    //비었는지 확인하는 메서드는 empty입니다.
    while(st.empty() == false)
    {
        //STL에서 제공하는 stack에서는 가장 최근에 보관한 자료를 확인하는 메서드 이름이 top입니다.
        cout<<st.top()<<" ";  //가장 최근에 보관한 자료 확인
        //그리고 가장 최근에 보관한 자료를 꺼내는 메서드 pop을 제공합니다.
        st.pop();//가장 최근에 보관한 자료 꺼내기
        // stack은 LIFO로 구성되어 있으니 st.top하면 마지막 원소가 무엇인지 알수있고 그것을 
		// pop하면 꺼내올수있다.  
    }
    cout<<endl; 
	return 0;
}

