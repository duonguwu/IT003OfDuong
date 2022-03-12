#include <iostream>
using namespace std;

struct Node
{
    int numberOfRoom;
    char kindOfRoom;
    int Status;
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

Node *CreateNode (int x, char s, int k){
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->numberOfRoom = x;
    p->kindOfRoom = s;
    p->Status = k;
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
            cout << p->numberOfRoom << " ";
            cout << p->kindOfRoom << " " << p->Status << endl;
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
        char s;
        int k;
        cin >> x;
        cin >> s;
        cin >> k;
        AddTail(l, CreateNode(x,s,k));
        i++;
    }
}

int KindA = 0;
int KindB = 0;

void ThongKeKind(List l){
    for (Node *p = l.head; p != NULL; p = p -> next){
        if (p->kindOfRoom == 'A')
            KindA++;
        if (p->kindOfRoom == 'B')  
            KindB++;
    }
    cout << "So luong phong don la: " << KindA << endl;
    cout << "So luong phong doi la: " << KindB << endl;
}

int yStatus  = 0;
int nStatus = 0;

void ThongKeStatus(List l){
    for (Node *p = l.head; p != NULL; p = p -> next){
        if (p->Status == 1)
            yStatus++;
        if (p->Status == 0)  
            nStatus++;
    }
    cout << "So luong phong da co khach la: " << yStatus << endl;
    cout << "So luong phong chua co khach la: " << nStatus << endl;
}


void CalcMoney(List l){
    int Money = 0;
    for (Node *p = l.head; p != NULL; p = p -> next){
        if (p->Status == 1){
            if (p->kindOfRoom == 'A')
                Money += 200;
            if (p->kindOfRoom == 'B')
                Money += 350;
        }
    }
    cout << "4. Doanh thu cua khach san trong 1 ngay: " << Money << endl;
}

void DeleteRoom(List &l){
    int x;
    cout << "5. Nhap vao so phong cua phong can xoa: ";
    cin >> x;

    Node *Del = NULL;
    Node *Pre = NULL;

    for (Del = l.head; Del->numberOfRoom != x; Del = Del->next){
        Pre = Del;
    }

    if (Del == l.head){
        l.head = l.head->next;
        Del->next = NULL;
        delete(Del);
        Del = NULL;
    }
    else if(Del == l.tail){
        Pre->next = NULL;
        l.tail = Pre;
        delete(Del);
        Del = NULL;
    }
    else{
        Pre->next = Del ->next;
        Del->next = NULL;
        delete(Del);
        Del = NULL;
    }
}

int main(){
    List l;
    int n;

    cout << "1. Nhap vao so phong cua khach san: ";
    cin >> n;

    CreateEmptyList(l);
    CreateList(l,n);

    cout << "2. Danh sach phong khach san: " << endl;
    PrintList(l);

    cout << "3. Thong ke: " << endl;
    ThongKeKind(l);
    ThongKeStatus(l);

    CalcMoney(l);
    DeleteRoom(l);
    PrintList(l);
}

