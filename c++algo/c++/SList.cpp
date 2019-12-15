//단순 연결리스트
#include <iostream>
using namespace std;
class SimpleLinkedList
{
    struct Node //단순 연결리스트의 노드
    {
        //노드는 데이터와 링크로 구성합니다. 
        //여기에서 만들 연결리스트는 
        //단순 연결리스트이므로 링크의 개수는 한 개입니다.
        int data;
        Node *next;
        Node(int data=0)
        {
            //멤버 data는 입력 인자로 받은 data로 설정하세요.
            this->data = data;
            //next 링크의 값은 0(널)로 설정하세요.
            next = 0;
        }
    };
    Node *head; //연결리스트 맨 앞 노드의 위치 정보
    Node *tail;   //연결리스트 맨 뒤 노드의 위치 정보
public:
    class Iterator//연결 리스트에 보관한 데이터를 탐색하기 위한 반복자
    {
        //연결리스트를 탐색할 때 현재 노드의 위치 정보를 멤버 필드로 기억하고 있어야 합니다.
        Node *node;//현재 노드의 위치 정보
    public:
        //연결리스트에서는 모든 멤버에 접근할 수 있게 friend로 지정하세요.
        friend class SimpleLinkedList;//연결리스트에서는 모든 멤버에 접근 권한 부여
        //생성자에서는 현재 노드의 위치 정보를 입력 인자로 받아 멤버 필드를 설정합니다.
        Iterator(Node *node=0)
        {
            this->node = node;
        }
        //현재 노드에 보관한 자료를 접근할 수 있어야겠죠.
        int GetData()const //현재 노드에 보관한 자료 접근자
        {
            if(node==0)//현재 노드가 없을 때
            {
                throw "유효한 노드를 가리키고 있지 않습니다.";
            }
            return node->data;
        }
        //탐색하기 위한 형식이므로 다음 노드의 위치로 이동하는 메서드를 제공합시다.
        bool MoveNext()//다음 노드의 위치로 이동
        {
            if(node->next)//다음 노드가 있을 때
            {
                node = node->next;//다음 노드 위치 정보로 변경
                return true;
            }
            return false;
        }
        //탐색할 끝인지 판별하기 위해서는 같은지 다른지 판별하는 기능이 필요합니다.
        bool operator==(const Iterator &iter)//같은지 판별
        {
            return node == iter.node;
        }
        bool operator!=(const Iterator &iter)//다른지 판변
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
        Node *prev=0; 
 
        //head가 존재하면 반복합니다.
        while(head !=0)
        {
            //head를 이동하기 전에 prev에 head를 대입하고 head를 이동하세요.
            prev = head;
            head = head->next;
            //기억해 두었던 prev를 소멸합니다.
            delete prev;
        }
    }

    void PushBack(int data)
    {
    	//입력한 자료를 보관할 노드를 생성하세요 
        Node *node = new Node(data);
        if(head==0)//비어있을 때
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }
   void PushFront(int data)
    {
        //data를 보관하는 노드를 생성하세요.
        Node *node = new Node(data);
        if(head==0)//비어있을 때
        {
            //비어있을 때 head와 tail은 새로 생성한 노드의 위치 정보로 설정하세요.
            head = tail = node;
        }
        else
        {
       		//맨 앞에 보관할 때는 새로운 노드의 next는 현재 맨 앞의 노드 정보로 설정해야겠죠. 
            node->next = head;
            //그리고 새로 생성한 노드가 연결리스트의 맨 앞 노드입니다.
            head = node;
        }
    }
     void InsertNext(Iterator iter,int data)
    {
        //노드를 생성하세요.
        Node *node = new Node(data);
        //전달받은 반복자가 가리키는 노드를 구합니다.
        Node *prev = iter.node;
        //이전 노드가 없을 때와 없을 때 구현 동작이 다릅니다.
        if(prev==0)//이전 노드가 없을 때
        {
            if(head)//연결리스트에 보관한 자료가 있을 때
            {
                //연결리스트에 보관한 자료가 있을 때는
                //이전 노드의 next와 head를 변경해 주어야 합니다. 
                //이 부분은 맨 앞에 노드를 보관할 때의 동작과 같습니다.
                prev->next = head;
                head = prev;
            }
            else//연결리스트에 보관한 자료가 없을 때
            {
                //연결리스트에 보관한 자료가 없을 때는 
                //새로운 노드가 맨 앞이면서 맨 뒤 노드죠.
                head = tail = node;
            }            
        }
      else//이전 노드가 있을 때
        { 
            node->next = prev->next;
            prev->next = node;
            
            if(prev == tail)//이전 노드가 tail일 때
            {
                //이전 노드가 tail이면 
                //새로운 노드가 맨 뒤에 노드로 변경해 주어야겠죠.
                tail = node;
            }
        }
    }

	Iterator Begin()//탐색에 사용할 시작 반복자 
    {
        //탐색을 시작하는 반복자는 head를 인자로 생성하여 반환하세요.
        Iterator iter(head);
        return iter;
    }
    Iterator End() //탐색에 사용할 마지막 반복자
    {
        //탐색을 끝낼 조건은 0입니다. 
        //마지막 자료까지 탐색하므로 
        //tail의 다음인 0을 종료 조건의 반복자입니다.
        Iterator iter(0);
        return iter;
    }
    
    bool Erase(int data)
    {        
        Node *prev=0;
        Node *seek=0;
        for(seek = head; seek !=0 ; seek = seek->next)
        {
            if(seek->data == data)//찾는 데이터가 있을 때
            {
                break;
            }
            prev = seek;
        }

        if(seek==0)//찾는 데이터가 없을 때
        {
            return false;
        }        
        if(prev)//이전 노드가 있을 때
        {
            prev->next = seek->next;
        }
        else//이전 노드가 없을 때
        {
            head = seek->next;
        }
        if(seek == tail)//지워야 할 노드가 맨 마지막 노드일 때
        {
            tail = prev;
        }

        delete seek;
        return true;
    }

    bool Exist(int data)
    {        
        Node *seek=0;
        for(seek = head; seek !=0 ; seek = seek->next)
        {
            if(seek->data == data)
            {
                return true;
            }
        }
        return false;
    }

    void ViewAll()const
    {        
        Node *seek=0;
        for(seek = head; seek !=0 ; seek = seek->next)
        {
            cout<<seek->data<<" ";            
        }
        cout<<endl;
    }
};

typedef class SimpleLinkedList SList;
int main()
{
    SList sl;
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

    SList::Iterator seek = sl.Begin();
    SList::Iterator last = sl.End();
    for(   ;seek != last; seek.MoveNext())
    {
        if(seek.GetData()==5)
        {
            break;
        }
    }

    sl.InsertNext(seek,6);//1 3 5 6 2 9 7
    sl.ViewAll();
    return 0;
}
