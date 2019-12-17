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
        	//�Է� ���ڷ� ���� data�� ����� ��� �ʵ� data�� �����ϰ�
			// �ΰ��� ��ũ�� 0���� �����ϼ���. 
            this->data = data;
            prev = next = 0;
        }
    };
 
    Node *head;
    Node *tail;
public:
     class Iterator //���� ����Ʈ�� ������ �����͸� Ž���ϱ� ���� �ݺ���! 
    {
    	// ���Ḯ��Ʈ�� Ž���� �� ���� ����� ��ġ ������ ����ʵ�� ����ϰ� �־�� �մϴ�. 
        Node *node;
 
    public:
    	// ���Ḯ��Ʈ������ ��� ����� ������ �� �ְ� friend�� �����ϼ���!. 
        friend class DoubledLinkedList;
 		//�����ڿ����� ���� ����� ��ġ ������ �Է� ���ڷ� �޾� ��� �ʵ带 �ۼ��մϴ�. 
        Iterator(Node *node=0)
        {
            this->node = node;
        }
        //���� ��忡 ������ �ڷḦ ������ ���־�߰��� 
        int GetData()const 
        {
            if(node==0) // ���� ��尡 ������ 
            {
                throw "유효한 노드를 가리키고 있지 않습니다.";
            }
            return node->data;
        }
        // Ž���ϱ� ���� �����̹Ƿ� ���� ����� ��ġ�� �̵��ϴ� �޼��带 �����սô�. 
        bool MoveNext()
        {
            if(node->next)// ���� ����� ��ġ�� �̵� 
            {
                node = node->next;//������尡 ���� �� 
                return true;
            }
            return false;
        }
        //Ž���� ���̈� �Ǻ��ϱ� ���ؼ��� ������ �ٸ��� �Ǻ��ϴ� ����� �ʿ��մϴ�. 
        bool operator==(const Iterator &iter)
        {
            return node == iter.node;
        }
        bool operator!=(const Iterator &iter)// �ٸ��� �Ǻ� 
        {
            return node != iter.node;
        }
    };
 
    DoubledLinkedList()//������ �� �ʱ�ȭ 
    {
        head = new Node();// ���̳�� ���� 
        tail = new Node();// ���� ��� ���� �� �ʱ�ȭ  
        head->next = tail;
        tail->prev = head;
    }
 
    ~DoubledLinkedList() //�Ҹ��ڽ� �ʱ�ȭ �Ͽ� �Ҹ� 
    {
    	//���Ḯ��Ʈ�� �Ҹ��� �� ��� ��带 
		// �Բ� �Ҹ��ϴ°��� �ܼ� ���Ḯ��Ʈ�� �ٸ��� �ʽ��ϴ�. 
        Node *prev=0;
		// head�� �����ϸ� �Ҹ��ϴ� ���� �ݺ��մϴ�.        
        while(head !=0)
        {            
        	// head�� ���� ��带 ����� �Ŀ�
			// head�� ���� ��带 ����Ű�� �����մϴ�. 
			// head�� prev�� �����ϰ� ����ǳؽ�Ʈ�� ���� ��Ī��
			// 1 2 �� �����Ҷ� 1�� head�϶� 1�� prev�� �ǰ� ����2�� ��  
            prev = head;
            head = head->next;
            delete prev;// ����� ������带 �Ҹ��մϴ�. 
        }
    }
    void PushBack(int data)
    {
    	// ������ data�� �Է� ���ڷ� ��带 �����ϼ���. 
        Node *node = new Node(data);
        // ���� ������ tail �տ� ���ο� ��带 �����ؾ߰���. 
        HangNode(node,tail);
    }
    void PushFront(int data)
    {
    	// ������ data�� �Է� ���ڷ� ��带 �����ϼ���. 
        Node *node = new Node(data);
        //������ ��带 �� �� ���� ��� �ڿ� �����ϸ�
		// �ڷḦ �����ϴ� ����߿��� �� ���� �ǰ� �� <�������� ��ġ�Ѵ�> 
        HangNode(node,head->next);
    }
    void Insert(Iterator iter,int data)
    {
    	//������ data�� �Է� ���ڷ� ��带 �����ϼ���. 
        Node *node = new Node(data);
        //������ ��带 �Է� ���ڷ� ���� 
        // �ݺ����� node �տ� ���ø� �ǰ��� 
        HangNode(node,iter.node);
    }
 
    Iterator Begin() // Ž���� ����� ���� �ݺ��� 
    {
    	//Ž���� ������ ���� head�� ���� ������ �Դϴ�.
		// head�� ����Ű�� ���� ���� ������� �����ϼ���. 
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
    	// ���� ���Ḯ��Ʈ�̹Ƿ� ���� ��带 ����ϴ� ������ ������ �ʿ䰡 �����. 
        Node *pos=0;
        // head�� ���� ��带 ����Ű�Ƿ� �˻��� ���� head�� ���� ������ �Դϴ�.
		// �׸��� Ž���� ��ũ�� �� �� ��带 ����Ű�� tail�� ������ �˻��� �ڷᰡ ���°�����. 
        for(pos = head->next; pos !=tail ; pos = pos->next)
        {
        	// ���� ���� �ڷᰡ ������ �ݺ����� Ż���մѴ�. 
            if(pos->data == data)
            {
                break;
            }            
        }
 		// ���� �˻����� ���Ͽ����� pos�� tail�� �����ϴ�. 
        if(pos==tail)
        {
            return false;
        }        
 		
 		//������ ����� ���� ����� next��ũ��
		// ������ ����� ���� ��带 ����Ű�� �����մϴ�. 
        pos->prev->next = pos->next;
        // ������ ���� ����� prev ��ũ��
		// ������ ����� ���� ��带 ����Ű�� �����մϴ�. 
        pos->next->prev = pos->prev;
        
        //��带 �Ҹ��մϴ�. 
        delete pos;
        return true;
    }
    bool Exist(int data)
    {        
        Node *seek=0;
        for(seek = head->next; seek !=tail ; seek = seek->next)
        {
        	//���� ���ϴ� ������ ����Ƽ�� ������ ���� ��ȯ�ϼ���  
            if(seek->data == data)
            {
                return true;
            }
        }
        // ���⿡ �����ߴٴ� ���� ���ϴ� �����Ͱ� �������̴�. 
        return false;
    }
 
    void ViewAll()const
    {        
        Node *seek=0;
        //��ü ������ ����ϴ� ��ɿ����� head�� ���� ������ tail �������� ����ϼ���
		// head�� tail�� ����Ű�� ���� ���� ������� �����ϼ���. 
        for(seek = head->next; seek !=tail ; seek = seek->next)
        {
            cout<<seek->data<<" "; 
        }
        cout<<endl;
    }
 
    private:
    void HangNode(Node *now,Node *pos)
    {	
    	// ���ο� ����� prev�� pos ���� ��� ��ġ�� �����մϴ�. 
        now->prev = pos->prev;
        // ���ο� ����� next�� pos�� �����ϼ���. 
        now->next = pos;
        // ���ο� ���� pos ���� ����� �ڿ� ������ ����.
		// pos�� ���� ����� next�� ���ο� ���� �����ϼ���. 
        pos->prev->next = now;
        // ���ο� ���� pos�տ� ������ �ſ���. 
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
