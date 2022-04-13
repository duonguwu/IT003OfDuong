#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct Stack
{
    Node* head;
    Node* tail;
};

Node *CreateNode(int x){
    Node *p = new Node;
    if(p == NULL)
        exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateEmptyStack(Stack &s){
    s.head = NULL;
    s.tail = NULL;
}

bool IsEmpty(Stack s){
    if(s.head == NULL)
        return true;
    return false;
}

void Push(Stack &s){
    int x;
    cout << "Nhap x = ";
    cin >> x;
    Node *p = CreateNode(x);
    if(s.head == NULL){
        s.head = s.tail = p;
    }
    else{
        s.tail ->next = p;
        s.tail = p;
    }
}

void Pop(Stack &s){
    if(IsEmpty(s)){
        cout << "Danh sach rong.";
    }
    else{
        Node *p = s.head;
        for(p; p != NULL; p = p ->next){
            Node *pre;
            Node *last = s.tail;
            if(pre->next = last){
                s.tail = pre;
                delete last;
                break;
            }
        }
    }
}

void PrintTop(Stack s){
    if(IsEmpty(s)){
        cout << "Danh sach rong.";  
    }
    else   
        cout << s.tail->data << endl;
}

void Print(Stack s){
    for (Node *p = s.head; p != NULL; p = p->next){
        cout << p->data << " ";
    }
    cout << endl;
}

int main(){
    Stack s;
    int x;
    CreateEmptyStack(s);
    do{
    cout << "\n============MENU===========\n";
    cout << "\n2. Kiem tra stack rong.";
    cout << "\n3. Kiem tra stack full.";
    cout << "\n4. Day mot phan tu vao stack.";
    cout << "\n5. Lay ra mot phan tu trong stack.";
    cout << "\n6. Xuat ra phan tu Top cua stack.";
    cout << "\n============END============\n";
    Print(s);
    cout << "\n===========================\n";
    
        cout << "\nNhap lua chon: ";
        cin >> x;
        switch (x)
        {
        case 1:
            Print(s);
            break;
        case 2:
            if(IsEmpty(s))
                cout << "Rong.";
            else  
                cout << "Khong rong.";
            break;
        case 3:

        case 4:
            Push(s);
            break;
        case 5:
            Pop(s);
            break;
        case 6: 
            PrintTop(s);
            break;
        }
    }  while (x != 0);
}


