#include <iostream>
using namespace std;



struct node {
    int data; 
    node* pNext; 
};
typedef struct node NODE;


struct list {
    NODE* pHead; 
    NODE* pTail; 
};
typedef struct list LIST;


void khoiTaoDanhSach(LIST& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}


NODE* khoiTaoNode(int data) {
    NODE* p = new NODE; 
    if (p == NULL) {
        cout << "\nKhong con bo nho\n"; 
        return NULL;
    }
    else {
        p->data = data;
        p->pNext = NULL;
        return p;
    }
}


void themVaoDau(LIST &l, NODE* p) {
   
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p; 
    }
    else {
       
        p->pNext = l.pHead;
        
        l.pHead = p;
    }
}
void themVaoCuoi(LIST &l, NODE* p) {

    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    }
    else {
        l.pTail->pNext = p;

        l.pTail = p;
    }
}
void xuatDanhSach(LIST &l) {
    for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
        cout << k->data << " ";
    }
}
void timMin( LIST &l) {
    int nhoNhat = l.pHead->data;
    for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
        if (k->data < nhoNhat)
            nhoNhat = k->data;
    }
    cout << "\nSo nho nhat: " << nhoNhat;
}
int main() {
    LIST l;
    khoiTaoDanhSach(l);
    
    int soLuong;
    cout << "\nNhap so luong: ";
    cin >> soLuong;
    for (int i = 0; i < soLuong; i++) {
        int soNguyen;
        cin >> soNguyen;
        NODE* p = khoiTaoNode(soNguyen);
       // themVaoDau(l, p);
        themVaoCuoi(l, p);
    }
    xuatDanhSach(l);
    timMin(l);
    return 0;
}