// STT: 42
// Họ và tên: Nguyễn Dương
// Buổi 03 - Bài 3

#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node* next;
};

struct Stack
{
    Node* Top;
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

void Push(Stack &s, int x)
{
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
    if (IsEmpty(s))
        cout << "<\t>";
    else{
        cout << "<\t";
    for (Node *p = s.Top; p != NULL; p = p->next){
        cout << p->data << "\t";
    }
    cout << "\t>";
    }
}

bool Swap(Stack &a, Stack &b){
    if(a.Top == NULL){
        return false;
    }
    else{
        int value;
        Pop(a, value);
        Push(b, value);
        return true;
    }
}

// 6 1 4 6 2 3 6
int main(){
    Stack a, b, c;
    CreateEmptyStack(a);
    CreateEmptyStack(b);
    CreateEmptyStack(c);
    int x;

    do{
        cout << "\n============MENU===========\n";
        cout << "\n0. Creating Tower.";
        cout << "\n1. A -> B";
        cout << "\n2. B -> A";
        cout << "\n3. B -> C";
        cout << "\n4. C -> B";
        cout << "\n5. C -> A";
        cout << "\n6. A -> C";
        cout << "\n7. 6 1 4 6 2 3 6";
        cout << "\n============END============\n";
        
        cout << "\nStack A: ";
        Print(a);
        cout << "\nStack B: ";
        Print(b);
        cout << "\nStack C: ";
        Print(c);
        cout << "\n===========================\n";

        cout << "Nhap vao lua chon: ";
        cin >> x;

        switch (x)
        {
        case 0:
            int n;
            cout << "Nhap vao so tang cua thap: ";
            cin >> n;
            for (int i = n; i > 0; i--){
                Push(a, i);
            }
            break;
        case 1:
            Swap(a,b);
            break;
    
        case 2:
            Swap(b,a);
            break;
        case 3:
            Swap(b,c);
            break;
        case 4:
            Swap(c,b);
            break;
        case 5:
            Swap(c,a);
            break;
        case 6:
            Swap(a,c);
            break;
        }
    
    } while (x != 99);
    
}
    
