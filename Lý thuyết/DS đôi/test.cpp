#include <iostream>
using namespace std;

struct Node{
    int info;
    Node *pre;
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

Node *CreateNode (int x){
    Node *p = new Node;
    if(p==NULL) exit(1);
    p->info = x;
    p->pre = NULL;
    p->next = NULL;
    return p;
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

void CreateList(List &l, int n){
    int i = 1;
    while (i <= n)
    {
        int x;
        cin >> x;
        AddTail(l, CreateNode(x));
        i++;
    }
}

void PrintList(List l){
    Node *p;
    if(l.head == NULL){
        cout << "Rong.";
    }
    else{
        p = l.tail;
        while(p){
            cout << p->info << " ";
            p = p->pre;
        }
    }
}

void SmallerThanX(List l, int x){
    for (Node *p = l.head; p != NULL; p = p -> next){
        if (p->info < x) cout << p->info << " ";
    }
}

int main(){
    List l;
    int n;
    int x;

    cout << "1. Nhap vao so phan tu cua list: ";
    cin >> n;

    CreateEmptyList(l);
    CreateList(l,n);

    cout << "2. Danh sach lien ket la: ";
    PrintList(l);
    cout << endl;
    cout << "3. Nhap x: "; cin >> x;
    cout << "Cac Node co info nho hon x: ";
    SmallerThanX(l,x);
}