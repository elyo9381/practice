//�ܼ� ���Ḯ��Ʈ
#include <iostream>
using namespace std;
class SimpleLinkedList
{
    struct Node //�ܼ� ���Ḯ��Ʈ�� ���
    {
        //���� �����Ϳ� ��ũ�� �����մϴ�. 
        //���⿡�� ���� ���Ḯ��Ʈ�� 
        //�ܼ� ���Ḯ��Ʈ�̹Ƿ� ��ũ�� ������ �� ���Դϴ�.
        int data;
        Node *next;
        Node(int data=0)
        {
            //��� data�� �Է� ���ڷ� ���� data�� �����ϼ���.
            this->data = data;
            //next ��ũ�� ���� 0(��)�� �����ϼ���.
            next = 0;
        }
    };
    Node *head; //���Ḯ��Ʈ �� �� ����� ��ġ ����
    Node *tail;   //���Ḯ��Ʈ �� �� ����� ��ġ ����
public:
    class Iterator//���� ����Ʈ�� ������ �����͸� Ž���ϱ� ���� �ݺ���
    {
        //���Ḯ��Ʈ�� Ž���� �� ���� ����� ��ġ ������ ��� �ʵ�� ����ϰ� �־�� �մϴ�.
        Node *node;//���� ����� ��ġ ����
    public:
        //���Ḯ��Ʈ������ ��� ����� ������ �� �ְ� friend�� �����ϼ���.
        friend class SimpleLinkedList;//���Ḯ��Ʈ������ ��� ����� ���� ���� �ο�
        //�����ڿ����� ���� ����� ��ġ ������ �Է� ���ڷ� �޾� ��� �ʵ带 �����մϴ�.
        Iterator(Node *node=0)
        {
            this->node = node;
        }
        //���� ��忡 ������ �ڷḦ ������ �� �־�߰���.
        int GetData()const //���� ��忡 ������ �ڷ� ������
        {
            if(node==0)//���� ��尡 ���� ��
            {
                throw "��ȿ�� ��带 ����Ű�� ���� �ʽ��ϴ�.";
            }
            return node->data;
        }
        //Ž���ϱ� ���� �����̹Ƿ� ���� ����� ��ġ�� �̵��ϴ� �޼��带 �����սô�.
        bool MoveNext()//���� ����� ��ġ�� �̵�
        {
            if(node->next)//���� ��尡 ���� ��
            {
                node = node->next;//���� ��� ��ġ ������ ����
                return true;
            }
            return false;
        }
        //Ž���� ������ �Ǻ��ϱ� ���ؼ��� ������ �ٸ��� �Ǻ��ϴ� ����� �ʿ��մϴ�.
        bool operator==(const Iterator &iter)//������ �Ǻ�
        {
            return node == iter.node;
        }
        bool operator!=(const Iterator &iter)//�ٸ��� �Ǻ�
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
 
        //head�� �����ϸ� �ݺ��մϴ�.
        while(head !=0)
        {
            //head�� �̵��ϱ� ���� prev�� head�� �����ϰ� head�� �̵��ϼ���.
            prev = head;
            head = head->next;
            //����� �ξ��� prev�� �Ҹ��մϴ�.
            delete prev;
        }
    }

    void PushBack(int data)
    {
    	//�Է��� �ڷḦ ������ ��带 �����ϼ��� 
        Node *node = new Node(data);
        if(head==0)//������� ��
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
        //data�� �����ϴ� ��带 �����ϼ���.
        Node *node = new Node(data);
        if(head==0)//������� ��
        {
            //������� �� head�� tail�� ���� ������ ����� ��ġ ������ �����ϼ���.
            head = tail = node;
        }
        else
        {
       		//�� �տ� ������ ���� ���ο� ����� next�� ���� �� ���� ��� ������ �����ؾ߰���. 
            node->next = head;
            //�׸��� ���� ������ ��尡 ���Ḯ��Ʈ�� �� �� ����Դϴ�.
            head = node;
        }
    }
     void InsertNext(Iterator iter,int data)
    {
        //��带 �����ϼ���.
        Node *node = new Node(data);
        //���޹��� �ݺ��ڰ� ����Ű�� ��带 ���մϴ�.
        Node *prev = iter.node;
        //���� ��尡 ���� ���� ���� �� ���� ������ �ٸ��ϴ�.
        if(prev==0)//���� ��尡 ���� ��
        {
            if(head)//���Ḯ��Ʈ�� ������ �ڷᰡ ���� ��
            {
                //���Ḯ��Ʈ�� ������ �ڷᰡ ���� ����
                //���� ����� next�� head�� ������ �־�� �մϴ�. 
                //�� �κ��� �� �տ� ��带 ������ ���� ���۰� �����ϴ�.
                prev->next = head;
                head = prev;
            }
            else//���Ḯ��Ʈ�� ������ �ڷᰡ ���� ��
            {
                //���Ḯ��Ʈ�� ������ �ڷᰡ ���� ���� 
                //���ο� ��尡 �� ���̸鼭 �� �� �����.
                head = tail = node;
            }            
        }
      else//���� ��尡 ���� ��
        { 
            node->next = prev->next;
            prev->next = node;
            
            if(prev == tail)//���� ��尡 tail�� ��
            {
                //���� ��尡 tail�̸� 
                //���ο� ��尡 �� �ڿ� ���� ������ �־�߰���.
                tail = node;
            }
        }
    }

	Iterator Begin()//Ž���� ����� ���� �ݺ��� 
    {
        //Ž���� �����ϴ� �ݺ��ڴ� head�� ���ڷ� �����Ͽ� ��ȯ�ϼ���.
        Iterator iter(head);
        return iter;
    }
    Iterator End() //Ž���� ����� ������ �ݺ���
    {
        //Ž���� ���� ������ 0�Դϴ�. 
        //������ �ڷ���� Ž���ϹǷ� 
        //tail�� ������ 0�� ���� ������ �ݺ����Դϴ�.
        Iterator iter(0);
        return iter;
    }
    
    bool Erase(int data)
    {        
        Node *prev=0;
        Node *seek=0;
        for(seek = head; seek !=0 ; seek = seek->next)
        {
            if(seek->data == data)//ã�� �����Ͱ� ���� ��
            {
                break;
            }
            prev = seek;
        }

        if(seek==0)//ã�� �����Ͱ� ���� ��
        {
            return false;
        }        
        if(prev)//���� ��尡 ���� ��
        {
            prev->next = seek->next;
        }
        else//���� ��尡 ���� ��
        {
            head = seek->next;
        }
        if(seek == tail)//������ �� ��尡 �� ������ ����� ��
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
