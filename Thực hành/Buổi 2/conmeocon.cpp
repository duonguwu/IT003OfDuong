#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

void CreateEmptyList (List &l){
    l.head = NULL;
    l.tail = NULL;
}

Node *CreateNode(int x){
    Node *p = new Node;
    if(p == NULL)
        exit(1);
    p->info = x;
    p->next = NULL;
    return p;
}

void AddHead(List &l, Node *p){
    if (l.head == NULL){
        l.head = p;
        l.tail = l.head;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}


void AddTail(List &l, Node *p){
    if (l.head == NULL){
        l.head = p;
        l.tail = l.head;
    }
    else 
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void CreateList(List &l){
    int n;
    int i = 1;
    cout << "Nhap so luong Node: ";
    cin >> n;
    while (i <= n){
        int x;
        cin >> x;
        AddTail(l, CreateNode(x));
        i++;
    }
}

void DeleteHead(List &l){
    Node *p = l.head;
    l.head = l.head->next;
    delete p;
}

void FindTail(Node *p){
    for (Node * i = l.head; i != NULL; i = i->next)
    {
        p = i;
        if (p->next->next == NULL)
            break;
    }
    return p;
}

void PrintList(List l){
    Node *p = l.head;   
    if (p == NULL){
        cout << "Rong." << endl;
    }
    else{
        while  (p != NULL){
            cout << p->info << " ";
            p = p->next;
        }
    }
}

int main(){
    List l;
    CreateEmptyList(l);
    CreateList(l);
    DeleteHead(l);
    PrintList(l);
}