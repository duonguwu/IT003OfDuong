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
void Pop(Stack &s, int &value)
{
    if (s.Top == NULL)
    {
        return;
    }
    else
    {
        Node *p = s.Top;
        value = p->data;
        s.Top = s.Top->next;
        delete p;
        p = NULL;
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

int main(){
    Stack a, b, c;
    CreateEmptyStack(a);
    CreateEmptyStack(b);
    CreateEmptyStack(c);
    int x;
    Push(a, 1);
    Push(a, 2);
    Push(a, 3);
    do{
        cout << "\n============MENU===========\n";
        cout << "\n1. A -> B";
        cout << "\n2. B -> A";
        cout << "\n3. B -> C";
        cout << "\n4. C -> B";
        cout << "\n5. C -> A";
        cout << "\n6. A -> C";
        cout << "\n============END============\n";
        cout << "\nStack A: ";
        Print(a);
        cout << "\nStack B: ";
        Print(b);
        cout << "\nStack C: ";
        Print(c);
        cout << "\n===========================\n";
    } while (x != 0);
}