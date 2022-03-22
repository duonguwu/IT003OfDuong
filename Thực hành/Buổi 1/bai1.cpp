// STT: 42
// Họ và tên: Nguyễn Dương
// Buổi 01 - Bài 1
// Ghi chú: Câu 33 và câu 38 em chạy trên máy của bạn em được, nhưng trên máy
// của em thì chạy không được. Em cũng không biết tại sao. Nếu có lỗi gì mong
// thầy thông cảm ạ. Em xin cảm ơn!!
#include <iostream>
#include <time.h>
using namespace std;

struct Node
{
    int info;      //Lưu dữ liệu 
    Node *next;    //Lưu địa chỉ của Node đứng sau
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

Node *CreateNode(int x){
    Node *p = new Node;     //Cấp phát vùng nhớ
    if(p==NULL) exit(1);    //Tìm thư viện chứa nó
    p->info = x;            //Gán giá trị cho Node
    p->next = NULL;
    return p;
}


void PrintList11(List l){
    Node *p;
    if (l.head == NULL){
        cout << "Rong.";
    }
    else{
        p = l.head;
        while (p){
            cout << p->info << " ";
            p = p->next;
        }
    }
}

void PrintList12(List l){
    Node *p;
    if (l.head == NULL){
        cout << "Rong.";
    }
    else{
        p = l.head;
        while (p){
            cout << p->info << " " << p << endl;
            p = p->next;
        }
    }
}

void Print13(List l){
    Node *head, *tail;
    head = l.head;
    tail = l.tail;
    cout << head->info << " " << head << endl;
    cout << tail->info << " " << tail << endl;
}

bool Ktra14(List l){
    Node *p;
    if (l.head == NULL){
        return true;
    }
    return false;
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

void CreateList(List &l)
{   
    int n;
    cout << "Nhap so luong Node: ";
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int x;
        cin >> x;
        AddTail(l, CreateNode(x));
        i++;
    }
}

void PrintList111(List &l, int n){
    for(Node *i = l.head; i != NULL; i = i->next){
        cout << i->info << "\t";
    }
    cout << endl;
}

void Random6(List &l){
    srand(time(0));
    int i = 1;
    int n = 39 + rand()%21;
    cout << "Gia tri cua n = " << n << endl;
    while (i <= n)
    {
        int x = -99 + rand()%199;
        AddHead(l, CreateNode(x));
        i++;
    }
    PrintList11(l);
    cout << endl;
}

void nodeThuN15(List l){
    int k;
    cout << "Nhap k: ";
    cin >> k;
    Node *p = l.head;
    int i = 1;
    while (p != NULL){
        if(i == k){
            cout << p->info;
            break;
        }
        i++;
        p = p->next;
    }
}

void TimKiemNode16(List l){
    int k;
    cout << "Nhap gia tri cua Node can tim: ";
    cin >> k;
    Node *p = l.head;
    for (p;p != NULL; p = p->next){
        if(p->info == k){
            cout << l.head;
            break;
        }
        cout << NULL;
    }
}

void TimKiemNode17(List l){
    int k;
    cout << "Nhap gia tri cua Node can tim: ";
    cin >> k;
    Node *p = l.head;
    for (p;p != NULL; p = p->next){
        if(p->info == k){
            cout << p << " ";
        }
        else
        cout << 0;
    }
}

void SumOfNode18(List l){
    int sum = 0;
    Node *p = l.head;
    for (p;p != NULL; p = p->next){
        sum += p->info;
    }
    cout << sum;
}

void LenOfList19(List l){
    int len = 0;
    Node *p = l.head;
    for (p;p != NULL; p = p->next){
        len++;
    }
    cout << len << endl;
}

void Count20(List l){
    int Chan = 0, Le = 0;
    Node *p = l.head;
    for (p;p != NULL; p = p->next){
        if (p->info % 2 == 0){
            Chan++;
        } else Le++;
    }
    cout << "Chan: " << Chan << endl;
    cout << "Le: " << Le << endl;
}

void Count21(List l){
    int Am = 0, Duong = 0;
    Node *p = l.head;
    for (p;p != NULL; p = p->next){
        if (p->info >= 0){
            Duong++;
        } else Am++;
        
    }
    cout << "Duong: " << Duong << endl;
    cout << "Am: " << Am << endl;
}

void FindMaxMin22(List l){
    Node *max = l.head;
    Node *min = l.head;
    Node *p = l.head;
    for (p;p != NULL; p = p->next){
        if (p->info >= max->info) max = p;
        if (p->info <= min->info) min = p;
    }
    cout << "Max: " << max->info << endl;
    cout << "Min: " << min->info << endl;
}

void Cau23(List l){
    Node *max = l.head;
    Node *min = l.head;
    Node *p = l.head;
    for (p;p != NULL; p = p->next){
        if(max->info > 0){
            max = l.head->next;
            if( p->info >= max->info && p->info < 0) max = p;
        }
    }
    cout << "So am lon nhat: " << max->info;
}

void Cau24(List l){
    
}

void Cau32(List l){
    if (l.head != NULL){
        Node *p = l.head;
        l.head = l.head->next;
        delete p;
    } else l.tail == NULL;
    PrintList11(l);
}

void Cau33(List l){
    Node *p;
    for (p = l.head; p != NULL; p = p->next){
        if(p->next == l.tail){
            delete l.tail;
            p->next = NULL;
            l.tail = p;
        }
    }
    PrintList11(l);
}

void Cau37(List l){
    for (Node *p = l.head; p != NULL; p = p->next){
        p->info = NULL;
        p->next = NULL;
    }
    cout << l.head->info;
    PrintList11(l);
}

void HoanVi(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void Cau38(List l){
    Node *i, *j;
    //Tang dan
    for(i = l.head; i != l.tail; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if (i->info > j->info){
                HoanVi(i->info, j ->info);
            }
        }
    }
    cout << "Danh sach tang dan: ";
    PrintList11(l);
    //Giam dan
    for(i = l.head; i != l.tail; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if (i->info < j->info){
                HoanVi(i->info, j ->info);
            }
        }
    }
    cout << "\nDanh sach giam dan: ";
    PrintList11(l);
}

int main(){
    List l;
    int n;
    CreateEmptyList(l);
    cout << "Tao List tu nhap tu ban phim or Random." << endl;
    cout << "1. Tu nhap danh sach " << "\n2. Random." << endl;
    cin >> n;
    if (n == 1){
        CreateList(l);
    }
    else if (n == 2){
        Random6(l);
    }
    
    cout << "=================MENU================\n";
	cout << "1. Xay dung cau truc node va cau truc danh sach lien ket don\n";
	cout << "2. Ham tao lien ket don va dia chi node tu 1 so nguyen\n";
	cout << "3. Chen Node vao dau\n";
	cout << "4. Chen Node vao cuoi\n";
	cout << "5. Ham nhap gia tri cho ds tu ban phim\n";
	cout << "6. Nhap gia tri ds random\n";
	cout << "11. In danh sach da nhap\n";
    PrintList11(l);
	cout << "\n12. In danh sach kem dia chi da nhap\n";
    PrintList12(l);
	cout << "\n\n13. In gia tri node dau va cuoi kem dia chi\n"; 
    Print13(l);
	cout << "\n\n14. Kiem tra danh sach rong"; 
    Ktra14(l);
	cout << "\n\n15. Node thu n\n"; 
    nodeThuN15(l);
    cout << "\n\n16. Tim kiem Node co gia tri XTra ve dia chi Node dau tien.\n"; 
    TimKiemNode16(l);
    cout << "\n\n17. Tim kiem Node co gia tri X. Tra ve dia chi Node.\n"; 
    TimKiemNode17(l);
    cout << "\n\n18. Tinh tong cac Node trong danh sach\n"; 
    SumOfNode18(l);
    cout << "\n\n19. Do dai cua danh sach\n"; 
    LenOfList19(l);
    cout << "\n\n20. Dem so luong Node chan va le\n"; 
    Count20(l);
    cout << "\n\n21. Dem so luong so am va so duong\n"; 
    Count21(l);
    cout << "\n\n22. Tim Max va Min\n"; 
    FindMaxMin22(l);
    
    cout << "\n\n32. Xoa Node dau tien\n"; 
    Cau32(l);
    cout << "\n\n33. Xoa Node cuoi cung\n"; 
    Cau33(l);
    cout << "\n\n38. Sap xep danh sach tang giam\n"; 
    Cau38(l);
}   




// void Menu() {
// 	cout << "=================MENU================\n";
// 	cout << "1. Xay dung cau truc node va cau truc danh sach lien ket don\n";
// 	cout << "2. Ham tao lien ket don va dia chi node tu 1 so nguyen\n";
// 	cout << "3. Chen Node vao dau\n";
// 	cout << "4. Chen Node vao cuoi\n";
// 	cout << "5. Ham nhap gia tri cho ds tu ban phim\n";
// 	cout << "6. Nhap gia tri ds random\n";
// 	cout << "11. In danh sach da nhap\n";
// 	cout << "12. In danh sach kem dia chi da nhap\n";
// 	cout << "13. In gia tri node dau va cuoi kem dia chi\n";
// 	cout << "14. Kiem tra danh sach rong";
// 	cout << "15. Node thu n\n";
//     cout << "16. Tim kiem Node co gia tri XTra ve dia chi Node dau tien.\n";
//     cout << "17. Tim kiem Node co gia tri X. Tra ve dia chi Node.\n";
//     cout << "18. Tinh tong cac Node trong danh sach\n";
//     cout << "19. Do dai cua danh sach\n";
//     cout << "20. Dem so luong Node chan va le\n";
//     cout << "21. Dem so luong so am va so duong\n";
//     cout << "22. Tim Max va Min\n";
//     cout << "32. Xoa Node dau tien\n";
//     cout << "33. Xoa Node cuoi cung\n";
//     cout << "38. Sap xep danh sach tang giam\n";
// 	cout << "=====================================\n";
// }

// void CreateListMenu(){
//     cout << "Tao List tu nhap tu ban phim or Random." << endl;
//     cout << "1. Tu nhap danh sach " << "\n2. Random.";
//     int n;
//     List l;
//     cin >> n;
//     if (n == 1){
//         CreateList(l);
//     }
//     else if (n == 2){
//         Random6(l);
//     }
// }

// void Choose(){
//     List l;
//     cout << "Menu hoat dong tu 11 tro di" << endl;
//     cout << "Moi chon menu: ";
//     int n;
//     cin >> n;
//     switch (n)
//     {
//     case 5:
//         CreateList(l);
//     case 6: 
//         Random6(l);
//     case 11:
//         CreateList(l);
//         PrintList11(l);
//         break;
//     case 12:
//         PrintList12(l);
//         break;
//     case 13:
        
//         Print13(l);
//         break;
//     case 14:
        
//         Ktra14(l);
//         break;
//     case 15: 
        
//         nodeThuN15(l);
//         break;
//     case 16:
        
//         TimKiemNode16(l);
//         break;  
//     case 17:
        
//         TimKiemNode17(l);
//     case 18:
//         CreateList(l);
//         SumOfNode18(l);
//         break;
//     case 19: 
//         LenOfList19(l);
//         break;
//     case 20: 
//         Count20(l);
//         break;
//     case 21:
//         Count21(l);
//         break;
//     case 22:
//         FindMaxMin22(l);
//         break;
//     }
// }