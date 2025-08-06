#include <iostream>
#include <queue>
/*큐는 연속된 메모리에 먼저들어와서 먼저나가는 자료구조이며
push(put)연산은 메모리가 비어있을때 rear에 값을 넣고 rear+1을해주며
pop(get)연산은 front에 존재하는 메모리의 값을 가져오고 front+1해서 다음 메모리공간을
가르킨다. front+1의 경우는 (front+1)%size를통해서 올라가게 한다. 
front==rear가 같다면 queue가 비어있는것이고 Next(rear)==front 이면 queue가 꽉찬것이다.*/
using namespace std;

class Queue
{
	// 여기에서는 자료를 저장할 버퍼를 생성할 떄 정하기로 할게요
	// 버퍼의 위치를 기억할 멤버를 선언하세요. 
	int *buffer;
	// 버퍼의 크기를 기억할 멤버도 필요하겠죠. 
	const int size;
	//자료를 꺼낼 위치 정보도 기억해야 합니다. 
	int front;
	//자료를 보관할 위치정보도 기억해야 합니다. 
	int rear;
public:
	Queue(int size):size(size)
	{
		//생성자에서는 자료를 보관할 버퍼를 동적으로 생성합니다. 
		buffer = new int[size];
		// 그리고 보관할 위치와 꺼낼 위치를 0으로 초기화 하세요 
		front = rear = 0;
	}
	~Queue()
	{
		//소멸자를 이용하여 소멸할때 동적으로 할당된 메모리를 해제 하세 요 
		delete[] buffer;
	}
	
	bool Put(int data)
	{
		// 버퍼가 꽉차면 보관할 수 없겠죠. 
		if(IsFull())
		{
			return false;
		}
		// 버퍼의 rear인덱스에 data를 보관하세요. 
		buffer[rear] = data;
		rear = Next(rear);
		return true;
	}
	
	bool Get()
	{
		// 비어있으면 0을 반환합니다.
		// 구현 목적에 따라 예외를 던질 수도 있겠죠. 
		if(IsEmpty())
		{
			return 0;
		}
		//꺼낼 자료는 버퍼의 front인덱스에 있는 자료입니다. 
		int re = buffer[front];
		// front를 다음 위치로 변경합니다. 
		front = Next(front);
		return re; 
	}
	
	bool IsEmpty()
	{
		// 꺼낼 위치와 들어갈 위치가 같으면 비어있는거에요 
		return front == rear;
	}
	bool IsFull()
	{
		// 들어갈 다음위치가 꺼낼 위치와 같으면 queue가 꽉차있는거에요. 
		return Next(rear) == front;
	}
private:
	int Next(int now){
		
		return (now+1)%size;
	}
};

int main()
{
	// 직접 구현한 queue 
//	Queue q(10);
//	q.Put(4);
//	q.Put(7);
//	q.Put(8);
//	q.Put(2);
//	
//	while(q.IsEmpty()==false)
//	{
//		cout<<q.Get()<<" ";
//	}
//	cout<<endl;

	queue<int> q;//int 형식을 보관하는 큐
    //STL의 큐에 자료를 보관하는 메서드는 push입니다. 
    //전산학에서 PUT 연산과 이름이 다른 점에 주의하세요.
    q.push(4); //4
    q.push(7); //4 7
    q.push(8); //4 7 8
    q.push(2); //4 7 8 2
 
    while(q.empty() == false)
    {
        //큐에서 가장 먼저 보관한 자료를 확인하는 메서드는 front입니다.
        cout<<q.front()<<" ";  //가장 먼저 보관한 자료 확인
        //그리고 가장 먼저 보관한 자료를 꺼내는 메서드는 pop이예요. 
        //전산학에서 GET 연산과 이름이 달라요.
        q.pop();//가장 먼저 보관한 자료 꺼내기
    }
    cout<<endl;
	return 0;
 } 
