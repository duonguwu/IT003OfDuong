#include <iostream>
#include <cmath>
using namespace std;

struct NODE{
    int info;
    NODE* next;
};

struct List{
    NODE *head;
    NODE *tail;
};

void CreateEmptyList(List &l){
    l.head=NULL;
    l.tail=NULL;
}

NODE* CreateNode(int x){
    NODE* p = new NODE;
    if(p==NULL)
        exit(1);
    p->info=x;
    p->next=NULL;
    return p;
}
void PrintList(List l)
{
    NODE *p;
    if(l.head==NULL)
        cout<<"rong";
    else
    {
        for(NODE*p=l.head;p!=NULL;p=p->next)
            cout<<p->info<<" ";
    }
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

void type(List &l)
{
    cout<<"nhap n:";
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        AddTail(l,CreateNode(x));
    }
}

int checkinc(int n)
{
    int k=n;
    int socuoi=k%10;
    k=k/10;
    while(k!=0)
    {
        int kecuoi=k%10;
        k/=10;
        if(socuoi<=kecuoi)
            return 0;
        else
            socuoi=kecuoi;
    }
    return 1;
}

int Countinc(List &l)
{
    int cnt=0;
    for(NODE*p=l.head;p!=NULL;p=p->next)
        if(checkinc(p->info))
            cnt++;
    return cnt;
}

void InsertafterQ(List &l,NODE *p, NODE*q)
{
        p->next=q->next;
        q->next=p;
        if(l.tail==q)
            l.tail=p;
}

void Addnodex(List &l, NODE*NEW)
{
    for(NODE*p=l.head;p!=NULL;p=p->next)
    {
        NODE*k=p->next;
        if(NEW->info<=p->info){
            AddHead(l,NEW);
            break;
        }
        if(NEW->info>p->info&&NEW->info<=k->info){
            InsertafterQ(l,NEW,p);
            break;
        }
        if(p==l.tail)
            AddTail(l,NEW);
    }
}

void Printodd(List l)
{
    for(NODE*p=l.head;p!=NULL;p=p->next->next)
        cout<<p->info<<" ";
}

void Printone(List l)
{
    for(NODE*p=l.head;p!=NULL;p=p->next){
            int dem=0;
        for(NODE*k=l.head;k!=NULL;k=k->next)
            if(k->info==p->info)
                dem++;
        if(dem==1)
            cout<<p->info<<" ";
    }
}

NODE* Findmax(List l)
{
    NODE*MAX=l.head;
    for(NODE*p=l.head;p!=NULL;p=p->next)
        if(p->info>MAX->info)
            MAX=p;
    return MAX;
}

NODE* Findmin(List l)
{
    NODE*MIN=l.head;
     for(NODE*p=l.head;p!=NULL;p=p->next)
        if(p->info<MIN->info)
            MIN=p;
     return MIN;
}

bool Checkevenlist(List l)
{
    for(NODE*p=l.head;p!=NULL;p=p->next)
        if(p->info%2!=0)
            return false;
    return true;
}

int length(List l)
{
    int length=0;
    for(NODE*p=l.head;p!=NULL;p=p->next)
        length++;
    return length;
}
bool Checksymlist(List l)
{
    int a[length(l)],i=0;
    for(NODE*p=l.head;p!=NULL;p=p->next){
        a[i]=p->info;
        i++;
        }
    for(int i=0;i<length(l);i++)
        if(a[i]!=a[length(l)-i-1])
            return false;
    return true;
}

void Sortlist(List l)
    {
    for(NODE*p=l.head;p!=NULL;p=p->next)
        for(NODE*Q=p->next;Q!=NULL;Q=Q->next)
            if(p->info>Q->info)
            {
                int temp=p->info;
                p->info=Q->info;
                Q->info=temp;
            }

}

void DelNODEx(List &l)
{
    int x;
    cout<<"nhap info cua NODE can xoa: ";
    cin>>x;
    NODE*DEL=NULL,*PRE=NULL;
    for(DEL=l.head;DEL->info!=x;DEL=DEL->next)
        PRE=DEL;
    if(DEL==l.head)
    {
        l.head=l.head->next;
        DEL->next=NULL;
        delete(DEL);
        DEL=NULL;
    }
    else if(DEL==l.tail)
    {
        PRE->next=NULL;
        l.tail=PRE;
        delete(DEL);
        DEL=NULL;
    }
    else
    {
        PRE->next=DEL->next;
        DEL->next=NULL;
        delete(DEL);
        DEL=NULL;
    }
}

int main()
{
    List l;
    CreateEmptyList(l);
    type(l);
    DelNODEx(l);
    PrintList(l);
}