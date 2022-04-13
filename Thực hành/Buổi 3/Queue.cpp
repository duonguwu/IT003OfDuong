#include <iostream>
using namespace std;


struct Node
{
    int info;
    Node *next;
};

struct Queue{
    Node *head;
    Node *tail;
};

void CreateEmptyQueue(Queue &q){
    q.head = NULL;
    q.tail = NULL;
}

Node *CreateNode(int x){
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->next = NULL;
    return p;
}

void PrintQueue(Queue q){
    Node *p;
    if (q.head == NULL){
        cout << "Rong.";
    }
    else{
        p = q.head;
        while(p){
            cout << p->info << " ";
            p = p -> next;
        }
    }
}

void AddHead(Queue &q, Node *p){
    if(q.head == NULL){
        q.head = p;
        q.tail = q.head;
    }
    else{
        p->next = q.head;
        q.head = p;
    }
}

void AddTail(Queue &q, Node *p){
    if(q.head = NULL){
        q.head = p;
        q.tail = q.head;
    }
    else{
        q.tail->next = p;
        q.tail = p;
    }
}

void CreateQueue(Queue &q, int n)
{
    int i = 1;
    while (i <= n){
        int x;
        cin >> x;
        AddHead(q, CreateNode(x));
        i++;
    }
}

bool IsEmpty(Queue q){
    if(q.head == NULL)
        return true;
    return false;
}

void PrintFront(Queue q){
    if(IsEmpty(q)){
        cout << "Danh sach rong.";  
    }
    else{
        cout << "Rear: " << q.head->info << endl;
        cout << "Front: " << q.tail->info << endl;
    }
}

void EnQueue(Queue &q){
    int x;
    cout << "Nhap Node muon chen vao: ";
    cin >> x;
    Node *p = CreateNode(x);
    if(q.head = NULL){
        q.head = p;
        q.tail = q.head;
    }
    else{
        q.tail->next = p;
        q.tail = p;
    }
}



int main(){
    Queue q;
    int x;
    CreateEmptyQueue(q);
    do{
    cout << "\n============MENU===========\n";
    cout << "\n1. In ra Queue.";
    cout << "\n2. Kiem tra queue rong.";
    cout << "\n3. Kiem tra queue full.";
    cout << "\n4. Day mot phan tu vao queue.";
    cout << "\n5. Lay ra mot phan tu trong queue.";
    cout << "\n6. Xuat ra phan tu Rear va Front cua queue.";
    cout << "\n============END============\n";
    cout << "\tRear\t->\tFront" << endl;
    PrintQueue(q);
    cout << "\n===========================\n";
    
        cout << "\nNhap lua chon: ";
        cin >> x;
        switch (x)
        {
        case 1:
            PrintQueue(q);
            break;
        case 2:
            if(IsEmpty(q))
                cout << "Rong.";
            else  
                cout << "Khong rong.";
            break;
        case 3:

        case 4:
            EnQueue(q);
            break;
        case 5:
            
            break;
        case 6: 
            PrintFront(q);
            break;
        }
    }  while (x != 0);
}