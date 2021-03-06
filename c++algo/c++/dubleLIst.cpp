#include <iostream>
using namespace std;
 
class DoubledLinkedList
{
    struct Node
    {
        int data;
        Node *prev;
        Node *next;
 
        Node(int data=0)
        {
        	//입력 인자로 받은 data를 노드의 멤버 필드 data에 설정하고
			// 두개의 링크는 0으로 설정하세요. 
            this->data = data;
            prev = next = 0;
        }
    };
 
    Node *head;
    Node *tail;
public:
     class Iterator //연결 리스트에 보관한 데이터를 탐색하기 위한 반복자! 
    {
    	// 연결리스트를 탐색할 때 현재 노드의 위치 정보를 멤버필드로 기억하고 있어야 합니다. 
        Node *node;
 
    public:
    	// 연결리스트에서는 모든 멤버에 접근할 수 있게 friend로 지정하세요!. 
        friend class DoubledLinkedList;
 		//생성자에서는 현재 노드의 위치 정보를 입력 인자로 받아 멤버 필드를 작성합니다. 
        Iterator(Node *node=0)
        {
            this->node = node;
        }
        //현재 노드에 보관한 자료를 접근할 수있어야겠죠 
        int GetData()const 
        {
            if(node==0) // 현재 노드가 없을때 
            {
                throw "�쑀�슚�븳 �끂�뱶瑜� 媛�由ы궎怨� �엳吏� �븡�뒿�땲�떎.";
            }
            return node->data;
        }
        // 탐색하기 위한 형식이므로 다음 노드의 위치로 이동하는 메서드를 제공합시다. 
        bool MoveNext()
        {
            if(node->next)// 다음 노드의 위치로 이동 
            {
                node = node->next;//다음노드가 있을 때 
                return true;
            }
            return false;
        }
        //탐색할 끝이닞 판별하기 위해서는 같은지 다른지 판별하는 기능이 필요합니다. 
        bool operator==(const Iterator &iter)
        {
            return node == iter.node;
        }
        bool operator!=(const Iterator &iter)// 다른지 판별 
        {
            return node != iter.node;
        }
    };
 
    DoubledLinkedList()//생성자 시 초기화 
    {
        head = new Node();// 더미노드 생성 
        tail = new Node();// 더미 노드 생성 및 초기화  
        head->next = tail;
        tail->prev = head;
    }
 
    ~DoubledLinkedList() //소멸자시 초기화 하여 소멸 
    {
    	//연결리스트를 소멸할 때 모든 노드를 
		// 함께 소명하는것은 단순 연결리스트와 다르지 않습니다. 
        Node *prev=0;
		// head가 존재하면 소멸하는 것을 반복합니다.        
        while(head !=0)
        {            
        	// head의 이전 노드를 기억한 후에
			// head를 다음 노드를 가리키게 설정합니다. 
			// head를 prev에 대입하고 헤드의넥스트는 헤드로 지칭함
			// 1 2 가 존재할때 1은 head일때 1은 prev가 되고 헤드는2가 됨  
            prev = head;
            head = head->next;
            delete prev;// 기억한 이전노드를 소멸합니다. 
        }
    }
    void PushBack(int data)
    {
    	// 보관할 data를 입력 인자로 노드를 생성하세요. 
        Node *node = new Node(data);
        // 순차 보관은 tail 앞에 새로운 노드를 연결해야겠죠. 
        HangNode(node,tail);
    }
    void PushFront(int data)
    {
    	// 보관할 data를 입력 인자로 노드를 생성하세요. 
        Node *node = new Node(data);
        //생성한 노드를 맨 앞 더미 노드 뒤에 보관하면
		// 자료를 보관하는 노드중에는 맨 앞이 되겠 죠 <헤드다음에 위치한다> 
        HangNode(node,head->next);
    }
    void Insert(Iterator iter,int data)
    {
    	//보관할 data를 입력 인자로 노드를 생성하세요. 
        Node *node = new Node(data);
        //생성한 노드를 입력 인자로 받은 
        // 반복자의 node 앞에 연겷면 되겠죠 
        HangNode(node,iter.node);
    }
 
    Iterator Begin() // 탐색에 사용할 시작 반복자 
    {
    	//탐색을 시작할 노드는 head의 다음 노드부터 입니다.
		// head가 가리키는 노드는 더미 노드임을 주의하세요. 
        Iterator iter(head->next);
        return iter;
    }
    Iterator End() 
    {
        Iterator iter(tail);
        return iter;
    }
    bool Erase(int data)
    {                
    	// 이중 연결리시트이므로 이전 노드를 기억하는 변수를 선언할 필요가 없어요. 
        Node *pos=0;
        // head는 더미 노드를 가리키므로 검색할 노드는 head의 다음 노드부터 입니다.
		// 그리고 탐색할 링크가 맨 뒤 노드를 가리키는 tail과 같으면 검색할 자료가 없는것이죠. 
        for(pos = head->next; pos !=tail ; pos = pos->next)
        {
        	// 만약 같은 자료가 있으면 반복문을 탈출합닌다. 
            if(pos->data == data)
            {
                break;
            }            
        }
 		// 만약 검색하지 못하였으면 pos는 tail과 같습니다. 
        if(pos==tail)
        {
            return false;
        }        
 		
 		//삭제할 노드의 앞쪽 노드의 next링크를
		// 삭제할 노드의 다음 노드를 가리키게 설정합니다. 
        pos->prev->next = pos->next;
        // 삭제할 다음 노드의 prev 링크를
		// 삭제할 노드의 이전 노드를 가리키게 설정합니다. 
        pos->next->prev = pos->prev;
        
        //노드를 소멸합니다. 
        delete pos;
        return true;
    }
    bool Exist(int data)
    {        
        Node *seek=0;
        for(seek = head->next; seek !=tail ; seek = seek->next)
        {
        	//만약 원하는 조건의 데어티가 있으면 참을 반환하세요  
            if(seek->data == data)
            {
                return true;
            }
        }
        // 여기에 도달했다는 것은 원하는 데이터가 없으것이다. 
        return false;
    }
 
    void ViewAll()const
    {        
        Node *seek=0;
        //전체 정보를 출력하는 기능에서도 head의 다음 노드부터 tail 이전까지 출력하세요
		// head와 tail이 가리키는 노드는 더미 노드임을 주의하세요. 
        for(seek = head->next; seek !=tail ; seek = seek->next)
        {
            cout<<seek->data<<" "; 
        }
        cout<<endl;
    }
 
    private:
    void HangNode(Node *now,Node *pos)
    {	
    	// 새로운 노드의 prev는 pos 이전 노드 위치로 설정합니다. 
        now->prev = pos->prev;
        // 새로운 노드의 next는 pos로 설정하세요. 
        now->next = pos;
        // 새로운 노드는 pos 이전 노드의 뒤에 보관할 거죠.
		// pos의 이전 노드의 next를 새로운 노드로 설정하세요. 
        pos->prev->next = now;
        // 새로운 노드는 pos앞에 보관할 거예요. 
        pos->prev = now;
    }
};
 
typedef class DoubledLinkedList DList;
int main()
{
    DList dl;
    dl.PushBack(3);//3
    dl.PushBack(5);//3 5
    dl.PushBack(8);//3 5 8
    dl.PushBack(2);//3 5 8 2
    dl.PushBack(9);//3 5 8 2 9
    dl.PushBack(7);//3 5 8 2 9 7
    dl.PushFront(1);//1 3 5 8 2 9 7
    dl.ViewAll();
    dl.Erase(7);//1 3 5 2 9 7
    dl.ViewAll();
 
    DList::Iterator seek = dl.Begin();
    DList::Iterator last = dl.End();
    for(   ;seek != last; seek.MoveNext())
    {
        if(seek.GetData()==5)
        {
            break;
        }
    }
 
    dl.Insert(seek,6);//1 3 6 5 2 9 7
    dl.ViewAll();
    return 0;
}
