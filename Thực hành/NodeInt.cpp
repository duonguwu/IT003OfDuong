#include <iostream>
using namespace std;


struct Node
{
    int info;
    Node *next;
};

struct List{
    Node *head;
    Node *tail;
};

void CreateEmptyList(List &l){
    l.head = NULL;
    l.tail = NULL;
}

Node *CreateNode(int x){
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->next = NULL;
    return p;
}

void PrintList(List l){
    Node *p;
    if (l.head == NULL){
        cout << "Rong.";
    }
    else{
        p = l.head;
        while(p){
            cout << p->info << " ";
            p = p -> next;
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
        l.head = p;
    }
}

void AddTail(List &l, Node *p){
    if(l.head = NULL){
        l.head = p;
        l.tail = l.head;
    }
    else{
        l.tail->next = p;
        l.tail = p;
    }
}

void CreateList(List &l, int n)
{
    int i = 1;
    while (i <= n){
        int x;
        cin >> x;
        AddHead(l, CreateNode(x));
        i++;
    }
}

