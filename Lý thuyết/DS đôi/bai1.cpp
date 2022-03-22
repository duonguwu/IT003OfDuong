#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node
{
    char info;
    Node* next;
    Node* pre;
};

struct List
{
    Node* head;
    Node* tail;
};

void CreateEmptyList(List &l)
{
    l.head=NULL;
    l.tail=NULL;
}

Node* CreateNode(char a)
{
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->info = a;
    p->next=NULL;
    p->pre=NULL;
    return p;
}
void AddHead(List &l, Node*p)
{
    if(l.head == NULL)
        l.head = p,
        l.tail = l.head;
    else
    {
        p->next=l.head;
        l.head->pre=p;
        l.head=p;
    }
}

void AddTail(List &l, Node*p)
{
    if(l.head == NULL)
        l.head = l.tail = p;
    else
    {
        p->pre=l.tail;
        l.tail->next=p;
        l.tail=p;
    }
}
// Cau 2
void Input(List &l)
{
    int n;
    int i = 1;
    cout << "Nhap so luong Node: ";
    cin >> n;
    while (i <= n){
        char x;
        cin >> x;
        AddHead(l, CreateNode(x));
        i++;
    }
}
// Cau 3
void Count(List l){

}

int Len(List l){
    int len = 0;
    for (Node *p = l.head; p != NULL; p = p -> next)
        len++;
    return len;
}

// Cau 4
bool KiemTraDoiXung(List l){
    int n = 0;
    Node *k = l.tail;
    for (Node *p = l.head; n < Len(l)/2; p = p -> next){
        if(p->info != k->info){
            return false;
            break;
        }
        n++;
        k = k->pre;
    }
    return true;
}

void Cau4(List l){
    if(KiemTraDoiXung(l) == true){
        cout << "Danh sach doi xung." << endl;
    }
    else{ 
        cout << "Danh sach khong doi xung." << endl;
    }
}

// Cau 5
void SortList (List l){
    for (Node *p = l.head; p != NULL; p = p->next){
        for (Node *k = p; k != NULL; k = k -> next){
            if(p->info > k->info){
                char a;
                a = p->info;
                p->info = k->info;
                k->info = a;
            }
        }
    }
}

// Cau 6
int ViTri(List l, char x){
    int count = 1;
    for (Node *p = l.head; p != NULL; p = p->next){
        if (p->info <= x){
            if (p->next->info >= x){
                return count;
            }
        }
        else if(p->info > x)
            return count;
        else 
            return Len(l);
        count++;
    }
    
}


void PrintList(List l){
    Node *p = l.head;   
    if (p == NULL){
        cout << "Rong." << endl;
    }
    else{
        while  (p != NULL){
            cout << p->info << " ";
            p = p->next;
        }
    }
}

int main(){
    List l;
    CreateEmptyList(l);
    cout << "Cau 2: ";
    Input(l);
    cout << "\nCau 4: ";
    Cau4(l);
    cout << "\nCau 5: ";
    SortList(l);
    PrintList(l);
    cout << "\nCau 6: Nhap info cua Node can them: ";
    char x;
    cin >> x;
    cout << "Vi tri thich hop de them X vao la: " << ViTri(l, x) << endl;


}