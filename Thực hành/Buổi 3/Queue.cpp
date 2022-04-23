// STT: 42
// Họ và tên: Nguyễn Dương
// Buổi 03 - Bài 2


#include <iostream>
using namespace std;


struct Node
{
    int info;
    Node *next;
};

struct Queue{
    Node *front;
    Node *rear;
};

void CreateEmptyQueue(Queue &q){
    q.front = NULL;
    q.rear = NULL;
}

Node *CreateNode(int x){
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->next = NULL;
    return p;
}

bool IsEmpty(Queue q){
    if(q.front == NULL)
        return true;
    return false;
}

void PrintFront(Queue q){
    if(IsEmpty(q)){
        cout << "Danh sach rong.";  
    }
    else{
        cout << "Rear: " << q.front->info << endl;
        cout << "Front: " << q.rear->info << endl;
    }
}

void EnQueue(Queue &q, int x){
    
    Node *p = CreateNode(x);
    if(IsEmpty(q)){
        q.front = p;
        q.rear = q.front;
    }
    else{
        q.rear->next = p;
        q.rear = p;
    }
}

bool DeQueue(Queue &q, int x){
    if(IsEmpty(q))
        return false;
    x = q.front->info;
    q.front = q.front->next;
    if(q.front == NULL)
        q.rear == NULL;
    return true;
}

void PrintQueue(Queue q){
    Node *p;
    if (q.front == NULL){
        cout << "Rong.";
    }
    else{
        p = q.front;
        for (p; p != NULL; p = p -> next)
            cout << p->info << " ";
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
            int k;
            cout << "Nhap Node muon chen vao: ";
            cin >> k;
            EnQueue(q,k);
            break;
        case 5:
            if(DeQueue(q,x))
                cout << "Phan tu lay duoc la: " << x << endl;
            else 
                cout <<"Stack rong." << endl;
            break;
        case 6: 
            PrintFront(q);
            break;
        }
    }  while (x != 0);
}
