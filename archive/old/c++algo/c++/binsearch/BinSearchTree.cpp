//BinSearchTree.cpp
#include "BinSearchTree.h"


BinSearchTree::BinSearchTree(void)
{
    root = 0;
}

bool BinSearchTree::AddBook(int bnum,string title)
{
	// 먼저 주요 키인 도서번호로 부모노드를 검색하기로 해요. 
    Node *parent = Find(root,bnum);
    
    if(parent)
    {
    	// 검색한 부모의 키가 입력한 도서 번호와 일치하였는지 확인하세요 
        Book *sbook = parent->book;
        if(sbook->GetBNum() == bnum)
        {
            return false;
        }
    }
    Book *book = new Book(bnum,title);
    HangNode(parent,new Node(book));
    return true;
}
Node *BinSearchTree::Find(Node *sr, int bnum)const
{
	//만약 검색할 서브 트리의 루트가 0인지 확인하세요. 
    if(sr==0)
    {
    	//서브트리의 루트가 0이라는 말은 root 0이라는 말과 같습니다.
		// 이 메서드에서는 재귀 호출을 사용할 것이며 언제나 서브트리가
		// 존재할때만 호출할 것입니다.
		// 따라서 처음 호출할 때 sr이 0일 때만 이 조건에 해당하여 		
		// 결국 root가 0이라는 말과 같습니다. 
        return sr;
    }
    // 입력 받은 도서 번호와 서브트리의 루트에 보관하 도서의 번호의 차이를 계산합니다. 
    int gap = bnum - sr->book->GetBNum();
    if(gap==0)
    {
    	//만약 차이가 없다면 sr을 반환하세요. 
        return sr;
    }
    if(gap>0)
    {
    	//차이가 0보다 크면 오른쪽 서브 트리에서 탐색하야합니다. 
        if(sr->right)
        {
        	//만약 오른쪽 서브트리가 있으면 재귀 호출하여 탐색한 값을 by pass 
            return Find(sr->right,bnum);
        }
        // 만약 오른쪽 서브트리가 없으면 탐색을 끝내고 현재 sr을 반환하세요. 
        return sr;
    }
    //gap이 0보다 작다는것이다.  
    if(sr->left)
    {
    	//왼쪽 서브 트리가 있으면 재귀호출 하여 탐색한 값을 by pass 
        return Find(sr->left,bnum);
    }
    //만약 왼쪽 서브트리가 없으면 탐새을 끝내고 현재 sr을 반환하세요. 
    return sr;
}
void BinSearchTree::HangNode(Node *parent, Node *now)
{
    if(parent == 0)
    {
    	//만약 부모가 없으면 새로운 노드가 첫 노드이므로 root로 설정하세요. 
        root = now;
        return;
    }
    //먼저 새로운 노드의 parent 링크를 설정하세요. 
    now->parent = parent;
    // 그리고 부모노드의 어느쪽에 매달 것인지 판단하기 위해 키 값의 차이를 계산 
    int gap = now->book->GetBNum() - parent->book->GetBNum();
    //차이가 크면 오른쪽 차이가 적으면  왼쪽으로  
    if(gap>0)
    {
        parent->right = now;
    }
    else
    {
        parent->left = now;
    }
}
bool BinSearchTree::FindBook(int bnum)const
{
	//먼저 bnum으로 검색합니다. 
    Node *now = Find(root,bnum);
    if(now)
    {
    	//now가 존재하면 now에 보관한 도서 개체를 구하세요. 
        Book *sbook = now->book;
        if(sbook->GetBNum() == bnum)
        {
        	//만약 도서 개체의 도서 번호와 입력받은 bnum이 같으면 검색 성공입니다. 
            // 여기어세는 도서 정보를 출력하기로 했죠. 
			sbook->View();
            return true;
        }
    }    
    return false;
}
bool BinSearchTree::RemoveBook(int bnum)
{
    Node *now = Find(root,bnum);
    if(now)
    {
        Book *sbook = now->book;
        if(sbook->GetBNum() == bnum)
        {            
            DeHang(now);
            return true;
        }
    }    
    return false;
}
void BinSearchTree::DeHang(Node *now)
{
	
	//먼저 자식이 양쪽에 있으면 자신과 같은 성향을 갖는 노드를 찾습니다. 
    if(now->left && now->right)
    {
    	// 자신과 같은 성향을 갖는 노드는 왼쪽 서브 트리에서 제일 큰 값을 갖는 노드와
		// 오른쪽 서브트리에서 제일 작은 값을 갖는 노드입니다.
		// 여기에서는 왼쪽 서브트리에서 찾기로 해요. 
        Node *alter = now->left;
        
        //왼쪽 서브트리에서는 제일 큰값을 갖는 노드를 찾아야 하므로
		//오른쪽 자식이 있으면 이동하면서 처음으로 오른쪽 자시기 없는 노드를 찾으세요. 
        while(alter->right)
        {
            alter = alter->right;
        }
        // now에 보관한 도서 개체와 대체할 노드에 보관한 도서 개체를 교환 
        Book *tmpbook = now->book;
        now->book = alter->book;
        alter->book = tmpbook;
        // 대체할 node가 now가 되며 
		// now는 자식이 하나있거나 자식이 없는 노드가 된다. 
        now = alter;
    }

	// 자식이 없거나 하나만 있을때
	// 자신의 부모에 자신이 있던 위치의 자식을 매달고
	// 자식의 부모링크를 자신의 부모 링크로 변경한다.
	// 이를 위해 먼저 부모를 기억하는 변수 선언한다. 
    Node *pa = now->parent;
    Node *child = 0;
    (child = now->left)||(child = now->right);
    if(pa)
    {
        if(pa->left == now)
        {
            pa->left = child;
        }
        else
        {
            pa->right = child;
        }
    }
    else
    {
    	//보무가 없다는것은 now가 root라는것이고 루트를 삭제하면
		//chile =0 일 것이고root가 0이 될것이다.  
        root = child;
    }
    
    //now에 자식이 있다면 자식의 부모를 자신의 부모로 설정한다. 
    if(child)
    {
        child->parent = pa;
    }
    //도서객체소멸(메모리 해제) 및 now 노드 소멸 
    delete now->book;
    delete now;
}
void BinSearchTree::ListAll()const
{    
    cout<<"=== Pre order ===="<<endl;
    PreOrder(root);    
    cout<<"===  In order ===="<<endl;
    InOrder(root);    
    cout<<"=== Post order ===="<<endl;
    PostOrder(root);
}
void BinSearchTree::PreOrder(Node *sr)const
{
    if(sr)
    {
        sr->book->View();
        PreOrder(sr->left);
        PreOrder(sr->right);
    }
}
void BinSearchTree::InOrder(Node *sr)const
{
    if(sr)
    {        
        InOrder(sr->left);
        sr->book->View();
        InOrder(sr->right);
    }
}
void BinSearchTree::PostOrder(Node *sr)const
{
    if(sr)
    {        
        PostOrder(sr->left);
        PostOrder(sr->right);
        sr->book->View();
    }
}


BinSearchTree::~BinSearchTree(void)
{
    Clear(root);
}
void BinSearchTree::Clear(Node *sr)
{
    if(sr)
    {        
        Clear(sr->left);
        Clear(sr->right);
        delete sr->book;
        delete sr;
    }
}
