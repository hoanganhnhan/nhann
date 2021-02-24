
#include <iostream>
using namespace std;
//khai bao node
struct node {
	int data;
	node* pNext;
};
typedef struct node NODE;
//khai bao ds
struct list {
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;
//khoi tao danh sach
void khoiTaoDS(LIST& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
//khoi tao node
NODE* khoiTaoNode(int data) {
	NODE* p = new NODE;
	if (p == NULL) {
		cout << "Khong cin bo nho";
		return NULL;
	}
	else {
		p->data = data;
		p->pNext = NULL;
		return p;
	}
}
void themDLvaoCuoiNode(LIST& l, NODE* p) {
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
	int n;
	LIST l;
	khoiTaoDS(l);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		NODE* p = khoiTaoNode(temp);
		themDLvaoCuoiNode(l, p);
	}
	xuatDS(l);
	//return 0;
}