#include "Book.h"
#define MAX_BOOK    10000
#define swap(x,y) {Element temp =x; x=y; y=temp;}

typedef Book *Element;
typedef int (*Compare)(Element , Element); 


void sequential_sort(Element *base, int n, Compare compare)//���� ����(base:�迭�� ���� �ּ�, n: ���� ��, compare:�� ��)
{
    int i, j;
    for(i = 0; i<n; i++) //�ݺ�(i:=0->n)
    {
        for( j=i+1; j<n; j++)//�ݺ�(j:=i+1->n)
        {
            if(compare(base[i],base[j])>0)//����(compare(base[i], base[j]) > 0)
            {
                swap(base[i],base[j]); //��ȯ(base[i],base[j])
            }
        }
    }
}

Book *books[MAX_BOOK]={0};
void SimulationInit()
{
    char title[MAX_TIT_LEN+1]="";
    char author[MAX_AUT_LEN+1]="";
    int i = 0;
    for(i=0; i<MAX_BOOK; ++i)
    {
        sprintf_s(title, sizeof(title), "%010d",rand());
        sprintf_s(author, sizeof(author), "%010d",rand());
        books[i] = New_Book(title,author,rand());
    }
}
int CompareByTitle(Book *book1,Book *book2)
{
    return Book_CompareTitle(book1,book2->title);
}
int CompareByNum(Book *book1,Book *book2)
{
    return Book_CompareNum(book1,book2->num);
}
void ListBook(int n)
{
    int i = 0;
    for(i=0; i<n; ++i)
    {
        Book_View(books[i]);
    }
}
void Simulation1()
{
    sequential_sort(books,10,CompareByTitle);
    printf("--------�����-------\n");
    ListBook(10);
    sequential_sort(books,10,CompareByNum);
    printf("--------��ȣ��-------\n");
    ListBook(10);
}
void Simulation2()
{
    clock_t st,et;
    st = clock();
    sequential_sort(books,MAX_BOOK/10,CompareByTitle);
    et=clock();
    printf("%d�� ���Ŀ� �ɸ� �ð�:%d\n",MAX_BOOK/10,et-st);
    st = clock();
    sequential_sort(books,MAX_BOOK,CompareByTitle);
    et=clock();	
    printf("%d�� ���Ŀ� �ɸ� �ð�:%d\n",MAX_BOOK,et-st);
}
void SimulationClear()
{
    int i = 0;
    for(i=0; i<MAX_BOOK; ++i)
    {
        Delete_Book(books[i]);
    }
}
int main()
{
    SimulationInit();
    Simulation1();
    Simulation2();
    SimulationClear();
    return 0;
}
