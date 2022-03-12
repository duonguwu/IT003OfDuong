#include <iostream>
#include <math.h>
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
void CreateEmptyList(List &l){
    l.head =NULL;
    l.tail = NULL;
}
// Tạo dslk đơn gồm N node
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

void input(List &l, int n)
{
    int i = 1;
    while (i <= n)
    {
        int x;
        cin >> x;
        AddTail(l, CreateNode(x));
        i++;
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
int PrimeNum(int x){
    if (n < 2)
        return 0;
    for(int i = 2; i <= sqrt(n); i++)
    
        if(n % i == 0)
        return 0;
    return 1;
}
int countPrime(List l){
    int count = 0;
    for (NODE *p = l.head; p != NULL; p = p ->next){
        if (PrimeNum(p->info) == 1) count++;
    }
    cout << count << endl;
}

void sum(List l){
    int sum = 0;
    for (NODE *p = l.head; p != NULL; p = p->next){
        if(p->info %2==0){
            sum +=p->info;
        }
    }
    cout << "Tong cac so chan la: " << sum << endl;
}
int main(){
    List l;
    int n;
    cout << "Nhap n: ";
    cin >> n;
    CreateEmptyList(l);
    input(l,n);
    cout << "Danh sach lien ket: " << endl;
    PrintList(l);
}
