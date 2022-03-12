#include <iostream>
using namespace std;

struct NODE
{
    int info;
    NODE* next;
};
struct List
{
    NODE *head;
    NODE *tail;
};

// Khởi tạo ds rỗng
void CreateEmptyList(List &l){
    l.head =NULL;
    l.tail = NULL;
}
//  Tạo 1 node có info = x
NODE* CreateNode(int x){
    NODE* p = new NODE;
    if(p==NULL)
        exit(1);
    p->info=x;
    p->next=NULL;
    return p;
}

void AddHead(List &L, NODE* p)
{
    if(L.head==NULL){
        L.head=p;
        L.tail=L.head;
    }
    else
    {
        p->next=L.head;
        L.head=p;
    }
}

void AddTail(List &L,NODE* p)
{
    if(L.head==NULL)
    {
        L.head=p;
        L.tail=L.head;
    }
    else
    {
        L.tail->next=p;
        L.tail=p;
    }
}

void PrintList(List l)
{
    NODE *p;
    if(l.head==NULL)
        cout<<"rong";
    else
    {
        p=l.head;
        while(p){
            cout<<p->info<<" ";
            p=p->next;
        }
    }
}
int main()

{

    List l;

    CreateEmptyList(l);  

    AddTail(l,CreateNode(1));

    AddTail(l,CreateNode(2));

    AddTail(l,CreateNode(3));

    AddHead(l,CreateNode(4));

    AddHead(l,CreateNode(5));

    PrintList(l);

    return 0;

}