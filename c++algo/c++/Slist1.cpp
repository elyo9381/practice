#include <iostream>
using namespace std;

class SimpleLinkedList
{
	struct Node
	{
		int data;
		Node *next;
		Node(int data=0)
		{
			this ->data = data;
			next = 0;
		}

	};
	Node *head;
	Node *tail;
public:
	class Iterator
	{
		Node *node;
	public:
		friend class SimpleLinkedList;
		Iterator(Node *node =0)
		{
			this -> node = node;
		}
		int GetData()const
		{
			if(node ==0)
			{
				throw "유효한 노드를 가르키고 있지 않습니다.";
			}
			return node -> data;
		}
		bool MoveNext()
		{
			if(node -> next)
			{
				node = node -> next;
				return true;
			}
			return false;
		}
		bool operator==(const Iterator &iter)
		{
			return node == iter.node;
		}
		bool operator!=(const Iterator &iter)
		{
			return node != iter.node;
		}
	};

	SimpleLinkedList()
	{
		head = 0;
		tail = 0;
	}

	~SimpleLinkedList()
	{
		Node *prev = 0;
		while(head !=0)
		{
			prev = head;
			head = head->next;
			delete prev;
		}
	}

	void PushBack(int data){
		Node *node = new Node(data);
		if(head==0){
			head =  tail = node;
		}
		else
		{
			tail -> next = node;
			tail = node;
		}
	}

	void PushFront(int data)
	{
		Node *node  = new Node(data);
		if(head == 0)
		{
			head = tail = node;
		}
		else
		{
			node->next = head;
			head = node;
		}
	}

	void InsertNext(Iterator iter, int data)
	{
		Node *node = new Node(data);
		Node *prev = iter.node;
		if(prev ==0)
		{
			if(head)
			{
				prev-> next = head;
				head = prev;
			}
			else
			{
				head = tail = node;
			}
		}
		else
		{
			node -> next = prev -> next;
			prev ->next = node;
			if(prev == tail)
			{
				tail = node;
			}
		}
	}

	Iterator Begin()
	{
		Iterator iter(head);
		return iter;
	}

	Iterator End()
	{
		Iterator iter(0);
		return iter;
	}

	bool Erase(int data)
	{
		Node *prev =0 ;
		Node *seek =0;

		for(seek = head; seek!= 0; seek = seek->next)
		{
			if(seek ->data == data)
			{
				break;
			}
			prev = seek;
		}

		if(seek ==0){
			return false;
		}
		if(prev)
		{
			prev ->next = seek->next;
		}
		else
		{
			head = seek->next;
		}
		if(seek == tail)
		{
			tail  = prev;
		}

		delete seek;
		return true;
	}

	void ViewAll()const
	{
		Node *seek = 0;
		for(seek= head; seek!=0; seek= seek->next)
		{
			cout<<seek->data<<"  ";

		}
		cout<<endl;
	}
};

typedef class SimpleLinkedList Slist;
int main(void){
	Slist sl;
	sl.PushBack(3);//3
    sl.PushBack(5);//3 5
    sl.PushBack(8);//3 5 8
    sl.PushBack(2);//3 5 8 2
    sl.PushBack(9);//3 5 8 2 9
    sl.PushBack(7);//3 5 8 2 9 7
    sl.PushFront(1);//1 3 5 8 2 9 7
    sl.ViewAll();
    sl.Erase(8);//1 3 5 2 9 7
    sl.ViewAll();



     Slist::Iterator seek = sl.Begin();
     Slist::Iterator last =  sl.End();
     
     
    for(; seek !=last; seek.MoveNext())
    {
    	if(seek.GetData() == 9)
    	{
    		break;
    	}
    }

    sl.InsertNext(seek,6);
    sl.ViewAll();
    return 0;
}
