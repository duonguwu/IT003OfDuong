// STT: 42
// Họ và tên: Nguyễn Dương
// Buổi 03 - Bài 1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct Stack
{
    Node *Top;
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
    s.Top = NULL;
}

bool IsEmpty(Stack s){
    if(s.Top == NULL)
        return true;
    return false;
}

void Push(Stack &s){
    int x;
    cout << "Nhap x = ";
    cin >> x;
    Node *p = CreateNode(x);
    if (s.Top == nullptr)
    {
        s.Top = p;
    }
    else
    {
        p->next = s.Top;
        s.Top = p;
    }
}

bool Pop(Stack &s, int &value)
{
    if (s.Top == NULL)
    {
        return false;
    }
    else
    {
        Node *p = s.Top;
        value = p->data;
        s.Top = s.Top->next;
        delete p;
        p = NULL;
        return true;
    }
}

void PrintTop(Stack s){
    if(IsEmpty(s)){
        cout << "Danh sach rong.";  
    }
    else   
        cout << s.Top->data << endl;
}

void Print(Stack s){
    for (Node *p = s.Top; p != NULL; p = p->next){
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
            int value;
            Pop(s, value);
            cout << "Phan tu duoc lay ra la: " << value << endl;
            break;
        case 6: 
            cout << "Phan tu Top cua Stack la: ";
            PrintTop(s);
            break;
        }
    }  while (x != 0);
    cout << "\n===========================\n";
}


