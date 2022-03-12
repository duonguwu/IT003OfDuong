#include <iostream>
using namespace std;

struct Node
{
    int info;
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

Node *CreateNode(int x){
    Node *p = new Node;
    if(p==NULL)
        exit(1);
    p->info = x;
    p->next = NULL;
    return p;
}

void PrintList(List l){
    Node *p;
    if(l.head == NULL){
        cout << "Rong.";
    }
    else{
        p = l.head;
        while(p){
            cout << p->info << " ";
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

void CreateList(List &l, int n)
{
    int i = 1;
    while (i <= n)
    {
        int x;
        cin >> x;
        AddTail(l, CreateNode(x));
        i++;
    }
}

void Input(List &l, int n){
    int i = 1;
    while (i <= n){
        int x;
        cin >> x;
        AddTail(l, CreateNode(x));
        i++;
    }
}

bool sotang(int n){
    while (n > 0)
    {
        int x = n % 10;
        n /= 10;
        int y = n % 10;
        if (y >= x)
            return false;
    }
    return true;
}

void InNodeViTriLe(List l){
    for (Node *p = l.head; p != NULL; p = p->next->next){
        cout << p->info << " ";
    }
}

int NodeSoTang(List l){
    int dem = 0;
    for (Node *p = l.head; p != NULL; p = p->next)
    {
        if (sotang(p->info) == true)
            dem++;
    }
    return dem;
}

void PrintOne(List l)
{
    for(Node *p = l.head; p != NULL; p = p -> next){
        int dem=0;
        for(Node* k=l.head; k != NULL; k=k->next)
            if(k->info==p->info)
                dem++;
        if(dem==1)
            cout << p -> info <<" ";
    }
}

int Max(List l){
    Node *p;
    int Max = l.head->info;
    for (Node *p = l.head; p != NULL; p = p->next){
        p = p -> next;
        if(Max < p->info){
            Max = p->info;
        }       
    }
    return Max;
}

int Min(List l){
    Node *p;
    int Min = l.head->info;
    for (Node *p = l.head; p != NULL; p = p->next){
        p = p -> next;
        if(Min > p->info){
            Min =  p->info;
        }
        
    }
    return Min;
}

bool KiemTraSoChan(List l){
    int count = 0;
    for (Node *p = l.head; p != NULL; p = p->next){
        if (p -> info % 2 != 0){
            count++;
        }
    }
    if (count == 0 ) return true;   
    return false;
}

int Lenght(List l){
    int len = 0;
    for (Node *p = l.head; p != NULL; p = p -> next)
        len++;
    return len;
}

bool CheckMyList(List l){
    int a[Lenght(l)];
    int i = 0;
    for (Node *p = l.head; p != NULL; p = p -> next){
        a[i] = p -> info;
        i++;
    }
    for (int i = 0; i < Lenght(l); i++){
        if (a[i] != a[Lenght(l) - i - 1])
            return false;
    }
    return true;
}

void SapXepTang(List l){
    for (Node* p = l.head; p != NULL; p = p -> next){
        for (Node* k = p->next; k != NULL; k = k -> next){
            if (p -> info >= k ->info){
                int t = p -> info;
                p -> info = k -> info;
                k-> info = t;
            }
        }
    }
    PrintList(l);
}

int main(){
    List l;
    int n;

    cout << "1. Nhap vao so phan tu cua list: ";
    cin >> n;

    CreateEmptyList(l);
    CreateList(l,n);

    cout << "2. Danh sach lien ket la: ";
    PrintList(l);
    cout << endl;

    cout << "3. So luong Node co info la so tang la: " << NodeSoTang(l) << endl;

    cout << "4. Cac node o vi tri le: "; 
    InNodeViTriLe(l);
    cout << endl;
    
    cout << "5. Nhung Node co info xuat hien 1 lan la: ";
    PrintOne(l);
    cout << endl;

    cout << "6. Node co gia tri info lon nhat la: " << Max(l) << endl;
    cout << "   Node co gia tri info nho nhat la " << Min(l) << endl;

    cout << "7. L la danh sach chua toan so CHAN: ";
    if (KiemTraSoChan(l)) cout << "Dung";
    else cout << "Sai";
    cout << endl;

    cout << "8. L la danh sach DOI XUNG: ";
    if(CheckMyList(l)) cout << "Dung";
    else cout << "Sai";
    cout << endl;

    cout << "9. Mang sau khi sap xep tang dan la: ";
    SapXepTang(l);
    cout << endl;

    return 0;
}