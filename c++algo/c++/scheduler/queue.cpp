#include <iostream>
#include <queue>
/*ť�� ���ӵ� �޸𸮿� �������ͼ� ���������� �ڷᱸ���̸�
push(put)������ �޸𸮰� ��������� rear�� ���� �ְ� rear+1�����ָ�
pop(get)������ front�� �����ϴ� �޸��� ���� �������� front+1�ؼ� ���� �޸𸮰�����
����Ų��. front+1�� ���� (front+1)%size�����ؼ� �ö󰡰� �Ѵ�. 
front==rear�� ���ٸ� queue�� ����ִ°��̰� Next(rear)==front �̸� queue�� �������̴�.*/
using namespace std;

class Queue
{
	// ���⿡���� �ڷḦ ������ ���۸� ������ �� ���ϱ�� �ҰԿ�
	// ������ ��ġ�� ����� ����� �����ϼ���. 
	int *buffer;
	// ������ ũ�⸦ ����� ����� �ʿ��ϰ���. 
	const int size;
	//�ڷḦ ���� ��ġ ������ ����ؾ� �մϴ�. 
	int front;
	//�ڷḦ ������ ��ġ������ ����ؾ� �մϴ�. 
	int rear;
public:
	Queue(int size):size(size)
	{
		//�����ڿ����� �ڷḦ ������ ���۸� �������� �����մϴ�. 
		buffer = new int[size];
		// �׸��� ������ ��ġ�� ���� ��ġ�� 0���� �ʱ�ȭ �ϼ��� 
		front = rear = 0;
	}
	~Queue()
	{
		//�Ҹ��ڸ� �̿��Ͽ� �Ҹ��Ҷ� �������� �Ҵ�� �޸𸮸� ���� �ϼ� �� 
		delete[] buffer;
	}
	
	bool Put(int data)
	{
		// ���۰� ������ ������ �� ������. 
		if(IsFull())
		{
			return false;
		}
		// ������ rear�ε����� data�� �����ϼ���. 
		buffer[rear] = data;
		rear = Next(rear);
		return true;
	}
	
	bool Get()
	{
		// ��������� 0�� ��ȯ�մϴ�.
		// ���� ������ ���� ���ܸ� ���� ���� �ְ���. 
		if(IsEmpty())
		{
			return 0;
		}
		//���� �ڷ�� ������ front�ε����� �ִ� �ڷ��Դϴ�. 
		int re = buffer[front];
		// front�� ���� ��ġ�� �����մϴ�. 
		front = Next(front);
		return re; 
	}
	
	bool IsEmpty()
	{
		// ���� ��ġ�� �� ��ġ�� ������ ����ִ°ſ��� 
		return front == rear;
	}
	bool IsFull()
	{
		// �� ������ġ�� ���� ��ġ�� ������ queue�� �����ִ°ſ���. 
		return Next(rear) == front;
	}
private:
	int Next(int now){
		
		return (now+1)%size;
	}
};

int main()
{
	// ���� ������ queue 
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

	queue<int> q;//int ������ �����ϴ� ť
    //STL�� ť�� �ڷḦ �����ϴ� �޼���� push�Դϴ�. 
    //�����п��� PUT ����� �̸��� �ٸ� ���� �����ϼ���.
    q.push(4); //4
    q.push(7); //4 7
    q.push(8); //4 7 8
    q.push(2); //4 7 8 2
 
    while(q.empty() == false)
    {
        //ť���� ���� ���� ������ �ڷḦ Ȯ���ϴ� �޼���� front�Դϴ�.
        cout<<q.front()<<" ";  //���� ���� ������ �ڷ� Ȯ��
        //�׸��� ���� ���� ������ �ڷḦ ������ �޼���� pop�̿���. 
        //�����п��� GET ����� �̸��� �޶��.
        q.pop();//���� ���� ������ �ڷ� ������
    }
    cout<<endl;
	return 0;
 } 
