#include <iostream>
using namespace std;

struct Worker
{
    char Id[50];
    char Name[100];
    int Date;
    int Amount;
};

struct Node
{
    Worker *data;
    Node *next;
    Node *pre;
};

struct List
{
    Node *head;
    Node *tail;
};

void CreateEmptyList(List l){
    l.head = NULL;
    l.tail = NULL;
}

Node *CreateNode(Worker *a){
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->data = a;
    p->next = NULL;
    p->pre = NULL;
    return p;
}

void PrintList(List l){
    Node *p = l.head;
    if (l.head == NULL){
        cout << "Rong.";
    }
    else{
        while (p != NULL)
        {
            Worker *wk = p->data;
            cout << wk->Id << " " << wk->Name << " " << wk->Date << " " << wk->Amount << endl;
            p = p->next;
        }
        
    }
}

void AddHead(List &l, Node *p){
    if(l.head == NULL){
        l.head = p;
        l.tail = l.head;
    }
    else{
        p->next = l.head;
        l.head->pre = p;
        l.head = p;
    }
}

void AddTail(List &l, Node *p){
    if(l.head == NULL){
        l.head = p;
        l.tail = l.head;
    }
    else{
        l.tail->next = p;
        p->pre = l.tail;
        l.tail = p;
    }
}

Worker *Input(){
    Worker *a = new Worker;
    cout << "ID: ";
    cin.ignore();
    cin.getline(a->Id, 50);
    cout << "Name: ";
    cin.getline(a->Name, 100);
    cout << "Date: ";
    cin >> a->Date;
    cout << "Amount of products: ";
    cin >> a->Amount;
    return a;
}

void CreateList(List &l)
{   
    int n;
    cout << "Nhap so luong cong nhan: ";
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        Worker *x = Input();
        AddHead(l, CreateNode(x));
        i++;
    }
}

void FindMax(List l){
    Node *max = l.head;
    Node *p = l.head->next;
    for(p; p != NULL; p = p->next){
        if (max->data->Amount < p->data->Amount){
            max = p;
        }
    }   
    for(Node *k = l.head; k != NULL; k = k -> next){
        if (k->data->Amount == max->data->Amount){
            cout << k->data->Id << " " << k->data->Name << " " << k->data->Date << " " << k->data->Amount << endl;
        }
    }
}

int main(){
    List l;
    CreateEmptyList(l);
    CreateList(l);
    cout << "Danh sach cong nhan: " << endl;
    PrintList(l);
    cout << "Cong nhan co luong san pham nhieu nhat la: ";
    FindMax(l);
}