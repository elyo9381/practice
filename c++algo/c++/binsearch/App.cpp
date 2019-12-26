//App.cpp
#include "App.h"

void App::Run()
{
    int key=NO_DEFINED;
    while((key = SelectMenu())!=ESC)
    {
        switch(key)
        {
        case F1: AddBook(); break;
        case F2: RemoveBook(); break;
        case F3: FindBook(); break;
        case F4: ListAll(); break;        
        default: cout<<"�߸� �����ϼ̽��ϴ�."<<endl; break;
        }
        cout<<"�ƹ� Ű�� ��������."<<endl;
        ehglobal::getkey();
    }
}

int App::SelectMenu()
{
    ehglobal::clrscr();//�ܼ� ȭ���� �����
    cout<<"���� ���� ���α׷� [ESC]: ����"<<endl;
    cout<<"F1: ���� �߰� F2: ���� ���� F3: ���� �˻� F4: ��ü ����"<<endl;

    return ehglobal::getkey();//����ڰ� �Է��� ��� Ű ��ȯ
}
void App::AddBook() //���� �߰�
{
    cout<<"�߰��� ���� ��ȣ:";
    int num = ehglobal::getnum();
    if(bstree.FindBook(num))
    {
        cout<<"�̹� �����մϴ�."<<endl;
        return;
    }
    cout<<"������:";
    string title = ehglobal::getstr();
    bstree.AddBook(num,title);
}
void App::RemoveBook()//���� ����
{
    cout<<"������ ���� ��ȣ:";
    int num = ehglobal::getnum();
    
    if(bstree.RemoveBook(num))
    {
        cout<<"�����Ͽ����ϴ�."<<endl;        
    }
    else
    {
        cout<<"�������� �ʴ� �����Դϴ�."<<endl;
    }
 
}
void App::FindBook()const //���� �˻�    
{
    cout<<"�˻��� ���� ��ȣ:";
    int num = ehglobal::getnum();
    
    if(bstree.FindBook(num)==0)    
    {
        cout<<"�������� �ʴ� �����Դϴ�."<<endl;
    }
}
void App::ListAll()const //��ü ����
{
    bstree.ListAll();
}
