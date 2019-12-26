//BinSearchTree.cpp
#include "BinSearchTree.h"


BinSearchTree::BinSearchTree(void)
{
    root = 0;
}

bool BinSearchTree::AddBook(int bnum,string title)
{
	// ���� �ֿ� Ű�� ������ȣ�� �θ��带 �˻��ϱ�� �ؿ�. 
    Node *parent = Find(root,bnum);
    
    if(parent)
    {
    	// �˻��� �θ��� Ű�� �Է��� ���� ��ȣ�� ��ġ�Ͽ����� Ȯ���ϼ��� 
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
	//���� �˻��� ���� Ʈ���� ��Ʈ�� 0���� Ȯ���ϼ���. 
    if(sr==0)
    {
    	//����Ʈ���� ��Ʈ�� 0�̶�� ���� root 0�̶�� ���� �����ϴ�.
		// �� �޼��忡���� ��� ȣ���� ����� ���̸� ������ ����Ʈ����
		// �����Ҷ��� ȣ���� ���Դϴ�.
		// ���� ó�� ȣ���� �� sr�� 0�� ���� �� ���ǿ� �ش��Ͽ� 		
		// �ᱹ root�� 0�̶�� ���� �����ϴ�. 
        return sr;
    }
    // �Է� ���� ���� ��ȣ�� ����Ʈ���� ��Ʈ�� ������ ������ ��ȣ�� ���̸� ����մϴ�. 
    int gap = bnum - sr->book->GetBNum();
    if(gap==0)
    {
    	//���� ���̰� ���ٸ� sr�� ��ȯ�ϼ���. 
        return sr;
    }
    if(gap>0)
    {
    	//���̰� 0���� ũ�� ������ ���� Ʈ������ Ž���Ͼ��մϴ�. 
        if(sr->right)
        {
        	//���� ������ ����Ʈ���� ������ ��� ȣ���Ͽ� Ž���� ���� by pass 
            return Find(sr->right,bnum);
        }
        // ���� ������ ����Ʈ���� ������ Ž���� ������ ���� sr�� ��ȯ�ϼ���. 
        return sr;
    }
    //gap�� 0���� �۴ٴ°��̴�.  
    if(sr->left)
    {
    	//���� ���� Ʈ���� ������ ���ȣ�� �Ͽ� Ž���� ���� by pass 
        return Find(sr->left,bnum);
    }
    //���� ���� ����Ʈ���� ������ Ž���� ������ ���� sr�� ��ȯ�ϼ���. 
    return sr;
}
void BinSearchTree::HangNode(Node *parent, Node *now)
{
    if(parent == 0)
    {
    	//���� �θ� ������ ���ο� ��尡 ù ����̹Ƿ� root�� �����ϼ���. 
        root = now;
        return;
    }
    //���� ���ο� ����� parent ��ũ�� �����ϼ���. 
    now->parent = parent;
    // �׸��� �θ����� ����ʿ� �Ŵ� ������ �Ǵ��ϱ� ���� Ű ���� ���̸� ��� 
    int gap = now->book->GetBNum() - parent->book->GetBNum();
    //���̰� ũ�� ������ ���̰� ������  ��������  
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
	//���� bnum���� �˻��մϴ�. 
    Node *now = Find(root,bnum);
    if(now)
    {
    	//now�� �����ϸ� now�� ������ ���� ��ü�� ���ϼ���. 
        Book *sbook = now->book;
        if(sbook->GetBNum() == bnum)
        {
        	//���� ���� ��ü�� ���� ��ȣ�� �Է¹��� bnum�� ������ �˻� �����Դϴ�. 
            // ������ ���� ������ ����ϱ�� ����. 
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
	
	//���� �ڽ��� ���ʿ� ������ �ڽŰ� ���� ������ ���� ��带 ã���ϴ�. 
    if(now->left && now->right)
    {
    	// �ڽŰ� ���� ������ ���� ���� ���� ���� Ʈ������ ���� ū ���� ���� ����
		// ������ ����Ʈ������ ���� ���� ���� ���� ����Դϴ�.
		// ���⿡���� ���� ����Ʈ������ ã��� �ؿ�. 
        Node *alter = now->left;
        
        //���� ����Ʈ�������� ���� ū���� ���� ��带 ã�ƾ� �ϹǷ�
		//������ �ڽ��� ������ �̵��ϸ鼭 ó������ ������ �ڽñ� ���� ��带 ã������. 
        while(alter->right)
        {
            alter = alter->right;
        }
        // now�� ������ ���� ��ü�� ��ü�� ��忡 ������ ���� ��ü�� ��ȯ 
        Book *tmpbook = now->book;
        now->book = alter->book;
        alter->book = tmpbook;
        // ��ü�� node�� now�� �Ǹ� 
		// now�� �ڽ��� �ϳ��ְų� �ڽ��� ���� ��尡 �ȴ�. 
        now = alter;
    }

	// �ڽ��� ���ų� �ϳ��� ������
	// �ڽ��� �θ� �ڽ��� �ִ� ��ġ�� �ڽ��� �Ŵް�
	// �ڽ��� �θ�ũ�� �ڽ��� �θ� ��ũ�� �����Ѵ�.
	// �̸� ���� ���� �θ� ����ϴ� ���� �����Ѵ�. 
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
    	//������ ���ٴ°��� now�� root��°��̰� ��Ʈ�� �����ϸ�
		//chile =0 �� ���̰�root�� 0�� �ɰ��̴�.  
        root = child;
    }
    
    //now�� �ڽ��� �ִٸ� �ڽ��� �θ� �ڽ��� �θ�� �����Ѵ�. 
    if(child)
    {
        child->parent = pa;
    }
    //������ü�Ҹ�(�޸� ����) �� now ��� �Ҹ� 
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
