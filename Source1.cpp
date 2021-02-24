#include <iostream>
using namespace std;
//khai bao node
struct node {
	int data;
	node* pNext; //con tro tro den node
};
typedef struct node NODE;
//khai bao danh sach
struct list {
	node* pHead;
	node* pTail;
};
typedef struct list LIST;
//khoi tao ds
void khoiTaoDS(LIST &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
//khoi tao node
NODE* khoiTaoNode( int data) {
	NODE* p = new NODE;
	if (p == NULL) {
		cout << "\nKhong con bo nho";
		return NULL;
	}
	else {
		p->data = data;
		p->pNext = NULL;
		return p;
	}
}
void themVaoDau(LIST& l, NODE* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void themVaoCuoi(LIST& l, NODE* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}

}
void xuatDS(LIST& l) {
	for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
		cout << k->data << " ";
	}
}
int main() {
	LIST l;
	khoiTaoDS(l);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		NODE* p = khoiTaoNode(temp);
		themVaoCuoi(l, p);
	}
	xuatDS(l);
}