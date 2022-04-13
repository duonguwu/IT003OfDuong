#include <iostream>
using namespace std;


struct Node  // Khai báo Node
{
    int info;
    Node *next;
};

struct List{  // Khai báo list
    Node *head; 
    Node *tail;
};

void CreateEmptyList(List &l){ // Tạo danh sách rỗng
    l.head = NULL;
    l.tail = NULL;
}

Node *CreateNode(int x){ // Tạo Node
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->next = NULL;
    return p;
}

void PrintList(List l){ // In danh sách
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

void AddHead(List &l, Node *p){  // Thêm đầu
    if(l.head == NULL){     // Phải kiểm tra danh sách có rỗng hay không
        l.head = p;
        l.tail = l.head;
        // hoặc là l.head = l.tail = p;
    }
    else{
        p->next = l.head;
        l.head = p;
    }
}

void AddTail(List &l, Node *p){ // Thêm cuối
    if(l.head = NULL){   // Kiểm tra tương tự thêm đầu
        l.head = p;
        l.tail = l.head;
    }
    else{
        l.tail->next = p;
        l.tail = p;
    }
}

void CreateList(List &l)  // Nhập 
{
    int n;
    cout << "Nhap vao so luong Node: ";
    cin >> n;
    int i = 1;
    while (i <= n){
        int x;
        cin >> x;
        AddHead(l, CreateNode(x));
        i++;
    }
}

void CreateListbyKeyBoard(List &l)  // Nhập từ bàn phím, bấm -99 để ngừng nhập
{
    cout << " Nhap danh sach, nhap -99 de ket thuc.\n";
    bool i = true;
    while (i == true)
    {
        int x;
        cout << "Nhap node: ";
        cin >> x;
        if (x == -99)
        {
            i = false;
            continue;
        }
        AddHead(l, CreateNode(x));
    }
}

