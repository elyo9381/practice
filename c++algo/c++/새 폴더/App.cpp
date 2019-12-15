//App.cpp
#include "App.h"

class EqualerByNum
{
    int num;
public:
    EqualerByNum(int num)
    {
        this->num=num;
    }
    bool operator()(const Genre *genre)const
    {
        return num == genre->GetNum();
    }
};

class EqualerByName
{
    string name;
public:
    EqualerByName(string name)
    {
        this->name = name;
    }
    bool operator()(const Genre *genre)const
    {
        return name.compare(genre->GetName())==0;
    }
};

App::App(void)
{
    last_gnum = 0;
}

App::~App(void)
{
    GIter seek = genres.begin(); //������ ���� ��ġ
    GIter last = genres.end(); //������ ������(����) ��ġ
    const Genre *genre;
    for(;seek!=last; ++seek)
    {
        genre = (*seek); //���� �������� seek��ġ�� ������ �帣 Ȯ��
        delete genre;
    }
}

void App::Run()
{
    int key=NO_DEFINED;
    while((key = SelectMenu())!=ESC)
    {
        switch(key)
        {
        case F1: AddGenre(); break;
        case F2: RemoveGenreByNum(); break;
        case F3: RemoveGenreByName(); break;
        case F4: FindGenreByNum(); break;
        case F5: FindGenreByName(); break;
        case F6: ListGenre(); break;
        default: cout<<"�߸� �����ϼ̽��ϴ�."<<endl; break;
        }
        cout<<"�ƹ� Ű�� ��������."<<endl;
        ehglobal::getkey();
    }
}

int App::SelectMenu()
{
    ehglobal::clrscr();//�ܼ� ȭ���� �����
    cout<<"�帣 ���� ���α׷� [ESC]: ����"<<endl;
    cout<<"F1: �帣 �߰� F2: ��ȣ�� �帣 ���� F3: �̸����� �帣 ����"<<endl;
    cout<<"F4: ��ȣ�� �帣 �˻� F5: �̸����� �帣 �˻� F6: �帣 ��� ����"<<endl;

    return ehglobal::getkey();//����ڰ� �Է��� ��� Ű ��ȯ
}
void App::AddGenre() //�帣 �߰�
{
    last_gnum++;
    cout<<last_gnum<<"��° �߰��� �帣��:";
    string name = ehglobal::getstr();//�帣�� �Է�
    Genre *genre = new Genre(last_gnum,name); //�帣 ����
    genres.push_back(genre);//���� ����
}



void App::RemoveGenreByNum()//��ȣ�� �帣 ����
{
    int num=0;
    cout<<"������ �帣 ��ȣ:";
    num = ehglobal::getnum();
    EqualerByNum ebnum(num);

    GIter seek = find_if(genres.begin(), genres.end(), ebnum);
    if(seek != genres.end())
    {
        delete (*seek);
        genres.erase(seek);        
        cout<<"�����Ͽ����ϴ�."<<endl;
    }
    else
    {
        cout<<"�������� �ʴ� �帣 ��ȣ�Դϴ�."<<endl;
    }
}

void App::RemoveGenreByName()//�̸����� �帣 ����
{
    string name;
    cout<<"������ �帣��:";
    name = ehglobal::getstr();
    EqualerByName ebname(name);

    GIter seek = find_if(genres.begin(), genres.end(), ebname);
    if(seek != genres.end())
    {
        Genre *genre = (*seek);
        delete genre;
        genres.erase(seek);
        cout<<"�����Ͽ����ϴ�."<<endl;
    }
    else
    {
        cout<<"�������� �ʴ� �帣���Դϴ�."<<endl;
    }
}
void App::FindGenreByNum()const //��ȣ�� �帣 �˻�
{
    int num=0;
    cout<<"�˻��� �帣 ��ȣ:";
    num = ehglobal::getnum();
    EqualerByNum ebnum(num);

    GCIter seek = find_if(genres.begin(), genres.end(), ebnum);
    if(seek != genres.end())
    {
        Genre *genre = (*seek);
        genre->View();
    }
    else
    {
        cout<<"�������� �ʴ� �帣 ��ȣ�Դϴ�."<<endl;
    }
}
void App::FindGenreByName()const //�̸����� �帣 �˻�
{
    string name;
    cout<<"�˻��� �帣��:";
    name = ehglobal::getstr();
    EqualerByName ebname(name);

    GCIter seek = find_if(genres.begin(), genres.end(), ebname);
    if(seek != genres.end())
    {
        Genre *genre = (*seek);
        genre->View();
    }
    else
    {
        cout<<"�������� �ʴ� �帣���Դϴ�."<<endl;
    }
}
void App::ListGenre()const //�帣 ��� ����
{
    GCIter seek = genres.begin(); //������ ���� ��ġ
    GCIter last = genres.end(); //������ ������(����) ��ġ
    const Genre *genre;
    for(   ;seek!=last; ++seek)
    {
        genre = (*seek); //���� �������� seek��ġ�� ������ �帣 Ȯ��
        genre->View(); //�帣 ���� ���
    }
}
