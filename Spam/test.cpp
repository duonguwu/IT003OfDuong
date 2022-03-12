#include <iostream>
#include <stdio.h>
using namespace std;

struct Book
{
    char Name[50];
    char Actor[50];
    char Date[12];
};

void InputInfoBook(Book &a){
    cin.ignore();
    cin.getline(a.Name,50);
    cin.getline(a.Actor,50);
    cin.getline(a.Date,12);
}

void InputListBook(Book A[], int &n){
    cout << "Nhap so luong quyen sach: ";
    cin >> n;
    cout << "Nhap vao thong tin cua cac quyen sach: " << endl;
    for (int i = 0; i < n; i++){
        InputInfoBook(A[i]);
    }
}

void OutputInfoBook(Book a){
    cout << a.Name << "\t";
    cout << a.Actor << "\t";
    cout << a.Date << endl;
}

void OutputListBook(Book A[], int n){
    cout << "Danh sach cac cuon sach hien co la: " << endl;
    for (int i = 0; i < n; i++){
        OutputInfoBook(A[i]);
    }
}

int main(){
    Book A[100];
    int n;

    InputListBook(A, n);
    OutputListBook(A, n);
}