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
        	//ÀÔ·Â ÀÎÀÚ·Î ¹ŞÀº data¸¦ ³ëµåÀÇ ¸â¹ö ÇÊµå data¿¡ ¼³Á¤ÇÏ°í
			// µÎ°³ÀÇ ¸µÅ©´Â 0À¸·Î ¼³Á¤ÇÏ¼¼¿ä. 
            this->data = data;
            prev = next = 0;
        }
    };
 
    Node *head;
    Node *tail;
public:
     class Iterator //¿¬°á ¸®½ºÆ®¿¡ º¸°üÇÑ µ¥ÀÌÅÍ¸¦ Å½»öÇÏ±â À§ÇÑ ¹İº¹ÀÚ! 
    {
    	// ¿¬°á¸®½ºÆ®¸¦ Å½»öÇÒ ¶§ ÇöÀç ³ëµåÀÇ À§Ä¡ Á¤º¸¸¦ ¸â¹öÇÊµå·Î ±â¾ïÇÏ°í ÀÖ¾î¾ß ÇÕ´Ï´Ù. 
        Node *node;
 
    public:
    	// ¿¬°á¸®½ºÆ®¿¡¼­´Â ¸ğµç ¸â¹ö¿¡ Á¢±ÙÇÒ ¼ö ÀÖ°Ô friend·Î ÁöÁ¤ÇÏ¼¼¿ä!. 
        friend class DoubledLinkedList;
 		//»ı¼ºÀÚ¿¡¼­´Â ÇöÀç ³ëµåÀÇ À§Ä¡ Á¤º¸¸¦ ÀÔ·Â ÀÎÀÚ·Î ¹Ş¾Æ ¸â¹ö ÇÊµå¸¦ ÀÛ¼ºÇÕ´Ï´Ù. 
        Iterator(Node *node=0)
        {
            this->node = node;
        }
        //ÇöÀç ³ëµå¿¡ º¸°üÇÑ ÀÚ·á¸¦ Á¢±ÙÇÒ ¼öÀÖ¾î¾ß°ÚÁÒ 
        int GetData()const 
        {
            if(node==0) // ÇöÀç ³ëµå°¡ ¾øÀ»¶§ 
            {
                throw "ìœ íš¨í•œ ë…¸ë“œë¥¼ ê°€ë¦¬í‚¤ê³  ìˆì§€ ì•ŠìŠµë‹ˆë‹¤.";
            }
            return node->data;
        }
        // Å½»öÇÏ±â À§ÇÑ Çü½ÄÀÌ¹Ç·Î ´ÙÀ½ ³ëµåÀÇ À§Ä¡·Î ÀÌµ¿ÇÏ´Â ¸Ş¼­µå¸¦ Á¦°øÇÕ½Ã´Ù. 
        bool MoveNext()
        {
            if(node->next)// ´ÙÀ½ ³ëµåÀÇ À§Ä¡·Î ÀÌµ¿ 
            {
                node = node->next;//´ÙÀ½³ëµå°¡ ÀÖÀ» ¶§ 
                return true;
            }
            return false;
        }
        //Å½»öÇÒ ³¡ÀÌˆ ÆÇº°ÇÏ±â À§ÇØ¼­´Â °°ÀºÁö ´Ù¸¥Áö ÆÇº°ÇÏ´Â ±â´ÉÀÌ ÇÊ¿äÇÕ´Ï´Ù. 
        bool operator==(const Iterator &iter)
        {
            return node == iter.node;
        }
        bool operator!=(const Iterator &iter)// ´Ù¸¥Áö ÆÇº° 
        {
            return node != iter.node;
        }
    };
 
    DoubledLinkedList()//»ı¼ºÀÚ ½Ã ÃÊ±âÈ­ 
    {
        head = new Node();// ´õ¹Ì³ëµå »ı¼º 
        tail = new Node();// ´õ¹Ì ³ëµå »ı¼º ¹× ÃÊ±âÈ­  
        head->next = tail;
        tail->prev = head;
    }
 
    ~DoubledLinkedList() //¼Ò¸êÀÚ½Ã ÃÊ±âÈ­ ÇÏ¿© ¼Ò¸ê 
    {
    	//¿¬°á¸®½ºÆ®¸¦ ¼Ò¸êÇÒ ¶§ ¸ğµç ³ëµå¸¦ 
		// ÇÔ²² ¼Ò¸íÇÏ´Â°ÍÀº ´Ü¼ø ¿¬°á¸®½ºÆ®¿Í ´Ù¸£Áö ¾Ê½À´Ï´Ù. 
        Node *prev=0;
		// head°¡ Á¸ÀçÇÏ¸é ¼Ò¸êÇÏ´Â °ÍÀ» ¹İº¹ÇÕ´Ï´Ù.        
        while(head !=0)
        {            
        	// headÀÇ ÀÌÀü ³ëµå¸¦ ±â¾ïÇÑ ÈÄ¿¡
			// head¸¦ ´ÙÀ½ ³ëµå¸¦ °¡¸®Å°°Ô ¼³Á¤ÇÕ´Ï´Ù. 
			// head¸¦ prev¿¡ ´ëÀÔÇÏ°í ÇìµåÀÇ³Ø½ºÆ®´Â Çìµå·Î ÁöÄªÇÔ
			// 1 2 °¡ Á¸ÀçÇÒ¶§ 1Àº headÀÏ¶§ 1Àº prev°¡ µÇ°í Çìµå´Â2°¡ µÊ  
            prev = head;
            head = head->next;
            delete prev;// ±â¾ïÇÑ ÀÌÀü³ëµå¸¦ ¼Ò¸êÇÕ´Ï´Ù. 
        }
    }
    void PushBack(int data)
    {
    	// º¸°üÇÒ data¸¦ ÀÔ·Â ÀÎÀÚ·Î ³ëµå¸¦ »ı¼ºÇÏ¼¼¿ä. 
        Node *node = new Node(data);
        // ¼øÂ÷ º¸°üÀº tail ¾Õ¿¡ »õ·Î¿î ³ëµå¸¦ ¿¬°áÇØ¾ß°ÚÁÒ. 
        HangNode(node,tail);
    }
    void PushFront(int data)
    {
    	// º¸°üÇÒ data¸¦ ÀÔ·Â ÀÎÀÚ·Î ³ëµå¸¦ »ı¼ºÇÏ¼¼¿ä. 
        Node *node = new Node(data);
        //»ı¼ºÇÑ ³ëµå¸¦ ¸Ç ¾Õ ´õ¹Ì ³ëµå µÚ¿¡ º¸°üÇÏ¸é
		// ÀÚ·á¸¦ º¸°üÇÏ´Â ³ëµåÁß¿¡´Â ¸Ç ¾ÕÀÌ µÇ°Ú ÁÒ <Çìµå´ÙÀ½¿¡ À§Ä¡ÇÑ´Ù> 
        HangNode(node,head->next);
    }
    void Insert(Iterator iter,int data)
    {
    	//º¸°üÇÒ data¸¦ ÀÔ·Â ÀÎÀÚ·Î ³ëµå¸¦ »ı¼ºÇÏ¼¼¿ä. 
        Node *node = new Node(data);
        //»ı¼ºÇÑ ³ëµå¸¦ ÀÔ·Â ÀÎÀÚ·Î ¹ŞÀº 
        // ¹İº¹ÀÚÀÇ node ¾Õ¿¡ ¿¬Ã¸é µÇ°ÚÁÒ 
        HangNode(node,iter.node);
    }
 
    Iterator Begin() // Å½»ö¿¡ »ç¿ëÇÒ ½ÃÀÛ ¹İº¹ÀÚ 
    {
    	//Å½»öÀ» ½ÃÀÛÇÒ ³ëµå´Â headÀÇ ´ÙÀ½ ³ëµåºÎÅÍ ÀÔ´Ï´Ù.
		// head°¡ °¡¸®Å°´Â ³ëµå´Â ´õ¹Ì ³ëµåÀÓÀ» ÁÖÀÇÇÏ¼¼¿ä. 
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
    	// ÀÌÁß ¿¬°á¸®½ÃÆ®ÀÌ¹Ç·Î ÀÌÀü ³ëµå¸¦ ±â¾ïÇÏ´Â º¯¼ö¸¦ ¼±¾ğÇÒ ÇÊ¿ä°¡ ¾ø¾î¿ä. 
        Node *pos=0;
        // head´Â ´õ¹Ì ³ëµå¸¦ °¡¸®Å°¹Ç·Î °Ë»öÇÒ ³ëµå´Â headÀÇ ´ÙÀ½ ³ëµåºÎÅÍ ÀÔ´Ï´Ù.
		// ±×¸®°í Å½»öÇÒ ¸µÅ©°¡ ¸Ç µÚ ³ëµå¸¦ °¡¸®Å°´Â tail°ú °°À¸¸é °Ë»öÇÒ ÀÚ·á°¡ ¾ø´Â°ÍÀÌÁÒ. 
        for(pos = head->next; pos !=tail ; pos = pos->next)
        {
        	// ¸¸¾à °°Àº ÀÚ·á°¡ ÀÖÀ¸¸é ¹İº¹¹®À» Å»ÃâÇÕ´Ñ´Ù. 
            if(pos->data == data)
            {
                break;
            }            
        }
 		// ¸¸¾à °Ë»öÇÏÁö ¸øÇÏ¿´À¸¸é pos´Â tail°ú °°½À´Ï´Ù. 
        if(pos==tail)
        {
            return false;
        }        
 		
 		//»èÁ¦ÇÒ ³ëµåÀÇ ¾ÕÂÊ ³ëµåÀÇ next¸µÅ©¸¦
		// »èÁ¦ÇÒ ³ëµåÀÇ ´ÙÀ½ ³ëµå¸¦ °¡¸®Å°°Ô ¼³Á¤ÇÕ´Ï´Ù. 
        pos->prev->next = pos->next;
        // »èÁ¦ÇÒ ´ÙÀ½ ³ëµåÀÇ prev ¸µÅ©¸¦
		// »èÁ¦ÇÒ ³ëµåÀÇ ÀÌÀü ³ëµå¸¦ °¡¸®Å°°Ô ¼³Á¤ÇÕ´Ï´Ù. 
        pos->next->prev = pos->prev;
        
        //³ëµå¸¦ ¼Ò¸êÇÕ´Ï´Ù. 
        delete pos;
        return true;
    }
    bool Exist(int data)
    {        
        Node *seek=0;
        for(seek = head->next; seek !=tail ; seek = seek->next)
        {
        	//¸¸¾à ¿øÇÏ´Â Á¶°ÇÀÇ µ¥¾îÆ¼°¡ ÀÖÀ¸¸é ÂüÀ» ¹İÈ¯ÇÏ¼¼¿ä  
            if(seek->data == data)
            {
                return true;
            }
        }
        // ¿©±â¿¡ µµ´ŞÇß´Ù´Â °ÍÀº ¿øÇÏ´Â µ¥ÀÌÅÍ°¡ ¾øÀ¸°ÍÀÌ´Ù. 
        return false;
    }
 
    void ViewAll()const
    {        
        Node *seek=0;
        //ÀüÃ¼ Á¤º¸¸¦ Ãâ·ÂÇÏ´Â ±â´É¿¡¼­µµ headÀÇ ´ÙÀ½ ³ëµåºÎÅÍ tail ÀÌÀü±îÁö Ãâ·ÂÇÏ¼¼¿ä
		// head¿Í tailÀÌ °¡¸®Å°´Â ³ëµå´Â ´õ¹Ì ³ëµåÀÓÀ» ÁÖÀÇÇÏ¼¼¿ä. 
        for(seek = head->next; seek !=tail ; seek = seek->next)
        {
            cout<<seek->data<<" "; 
        }
        cout<<endl;
    }
 
    private:
    void HangNode(Node *now,Node *pos)
    {	
    	// »õ·Î¿î ³ëµåÀÇ prev´Â pos ÀÌÀü ³ëµå À§Ä¡·Î ¼³Á¤ÇÕ´Ï´Ù. 
        now->prev = pos->prev;
        // »õ·Î¿î ³ëµåÀÇ next´Â pos·Î ¼³Á¤ÇÏ¼¼¿ä. 
        now->next = pos;
        // »õ·Î¿î ³ëµå´Â pos ÀÌÀü ³ëµåÀÇ µÚ¿¡ º¸°üÇÒ °ÅÁÒ.
		// posÀÇ ÀÌÀü ³ëµåÀÇ next¸¦ »õ·Î¿î ³ëµå·Î ¼³Á¤ÇÏ¼¼¿ä. 
        pos->prev->next = now;
        // »õ·Î¿î ³ëµå´Â pos¾Õ¿¡ º¸°üÇÒ °Å¿¹¿ä. 
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
