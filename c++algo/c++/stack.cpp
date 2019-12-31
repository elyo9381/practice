//����
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Stack
{
	//���ÿ��� �ڷḦ ������ ����Ұ� �ʿ��մϴ�.
	int *buffer;
	// ������� ũ�⸦ ����ϴ� ����� �����ϼ���.
	const int size;
	//���� �ֱٿ� ������ �ڷ��� ��ġ�� �ε����� ����ϴ� ���
	int top;
public:
	//�����ڴ� ���� ũ�⸦ �Է� ���ڷ� �ް� �մϴ�.
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
		//push ������ ���� �� á���� Ȯ���մϴ�. 
		if(IsFull())
		{
			// ���� �� ���� ���� �� �� ������. 
			return false;
		}
		//top�� ���� ��ġ�� �̵��մϴ�. 
		top++;
		// buffer�� top �ε��� ��Ī data�� �����ϼ� 
		buffer[top] = data;
		return true;
	 }
	 
	 int Pop()
	 {
	 	if(IsEmpty())
	 	{
	 		//���⿡�� 0�� ��ȯ�ҰԿ�.
			 //������ ���� ���ܸ� ������ ���·� ������ ���� �ְ�����
			 return -1; 
		 }
		 //buffer �� top �ε��� ��ġ�� ������ ���� ��ȯ �� ������ �����ϼ���
		 int re = buffer[top];
		 //top ��ġ�� 1 ���� �մϴ�.
		 top--;
		 return re; 
	  }
	bool IsFull()
	{
		// ������top�� -1�� �ʱⰪ�̹Ƿ� top+1�� size�� ������ ������ 
		return (top+1) == size;
	}
	bool IsEmpty()
	{
		return top == -1; 
	}
	
};
	
int main()
{
//  stack ���� ���� 
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

 	//���ø� Ŭ�����̹Ƿ� ���ø� ���� ���ڷ� ������ ������ ��Ÿ���߰���.
 	vector<int> v;
    stack<int,vector<int> > st;//int ������ �����ϴ� ����
      
 	
 	v.push_back(3);
 	v.push_back(4);
 	v.push_back(5);
 	v.push_back(6);
 	
 	
    //�����ϴ� �޼���� push�Դϴ�.
//    st.push(4); //4
//    st.push(7); //4 7
//    st.push(8); //4 7 8
//    st.push(2); //4 7 8 2
 	st.push(1);
    //������� Ȯ���ϴ� �޼���� empty�Դϴ�.
    while(st.empty() == false)
    {
        //STL���� �����ϴ� stack������ ���� �ֱٿ� ������ �ڷḦ Ȯ���ϴ� �޼��� �̸��� top�Դϴ�.
        cout<<st.top()<<" ";  //���� �ֱٿ� ������ �ڷ� Ȯ��
        //�׸��� ���� �ֱٿ� ������ �ڷḦ ������ �޼��� pop�� �����մϴ�.
        st.pop();//���� �ֱٿ� ������ �ڷ� ������
        // stack�� LIFO�� �����Ǿ� ������ st.top�ϸ� ������ ���Ұ� �������� �˼��ְ� �װ��� 
		// pop�ϸ� �����ü��ִ�.  
    }
    cout<<endl; 
	return 0;
}

