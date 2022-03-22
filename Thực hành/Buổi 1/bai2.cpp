// STT: 42
// Họ và tên: Nguyễn Dương
// Buổi 01 - Bài 2

#include <iostream>
using namespace std;


struct Sinhvien
{
    int ID;
    char Name[50];
    double GPA;
};

struct Node
{   
    Sinhvien *data;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

void CreateEmptyList(List &l){
    l.head = NULL;
    l.tail = NULL;
}

Node *CreateNode(Sinhvien *x){
    Node *p = new Node;     
    if(p==NULL) exit(1);  
    p->data = x;            
    p->next = NULL;
    return p;
}

void PrintList11(List l){
    Node *p = l.head;
    if (l.head == NULL){
        cout << "Rong.";
    }
    else{
        while (p != NULL)
        {
            Sinhvien *sv = p->data;
            cout << sv->ID << " " << sv->Name << " " << sv->GPA << endl;
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
        l.tail = p;
    }
}

Sinhvien *Input(){
    Sinhvien *sv = new Sinhvien;
    cout << "Nhap ID: ";
    cin >> sv->ID;
    cin.ignore();
    cout << "Nhap ho va ten: ";
    gets(sv->Name);
    cout << "Nhap GPA: ";
    cin >> sv->GPA;
    return sv;
}

void CreateList(List &l)
{   
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        Sinhvien *x = Input();
        AddTail(l, CreateNode(x));
        i++;
    }
}

void Cau12(List l){
    Node *p;
    Sinhvien *max = l.head->data;
    for (p = l.head->next; p != NULL; p = p->next){
        Sinhvien *sv = p->data;
        if(max->GPA < sv->GPA){
            max = sv;
        }
    }
    cout << max->ID << " " << max->Name << " " << max->GPA << endl;
}

void Cau13(List l){
    Node *p;
    Sinhvien *max = l.head->data;
    for (p = l.head->next; p != NULL; p = p->next){
        Sinhvien *sv = p->data;
        if(max->GPA > sv->GPA){
            max = sv;
        }
    }
    cout << max->ID << " " << max->Name << " " << max->GPA << endl;
}

void Cau9(List l){
    int x;
    cout<<"Nhap ID cua Sinh vien can tim: ";
    cin >> x;
    Node *p = l.head;
    while (p != NULL)
    {
        Sinhvien *sv = p->data;
        if (sv->ID == x){
            cout << sv->ID << " " << sv->Name << " " << sv->GPA << endl;
        }
    }
    
}

void Cau15(List &l)
{
    int x;
    cout<<"Nhap ID cua Sinh vien can xoa: ";
    cin >> x;
    Node *del = l.head;
    Node *pre =NULL;
    while(del != NULL){
        Sinhvien *sv = del->data;
        if(sv->ID == x)
            break;
        pre = del;
        del = del->next;
    }
    if (del == NULL){
        cout << "Khong tim thay ID: " << x;
    }
    else{
        if(del == l.head){
            l.head = l.head->next;
            del->next = NULL;
            delete del;
            del = NULL;
        }
        else{
            pre->next = del->next;
            del->next = NULL;
            delete del;
            del = NULL;
        }
    }
    PrintList11(l);
}

int main(){
    List l;
    CreateEmptyList(l);
    CreateList(l);
    cout << "Danh sach sinh vien la: "<< endl;
    PrintList11(l);
    cout << "Sinh vien co GPA cao nhat la: " << endl;
    Cau12(l);
    cout << "Sinh vien co GPA thap nhat la: " << endl;
    Cau13(l);
    // cout << "Tim kiem sinh vien: " << endl;
    // Cau9(l);
    cout << "Xoa sinh vien: " << endl;
    Cau15(l);
    
}