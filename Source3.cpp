#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
node* khoiTaoNode(int data) {
	node* p = new node;
	p->data = data;
	p->next = NULL;
	return p;
}
node* addPT(node* p, int data) {
	node* temp = khoiTaoNode(data);
	p->next = temp;
	return temp;
}
void xuatPT(node* l) {
	while (l != NULL) {
		cout << l->data << " ";
		l = l->next;
	}
}
int main(){
	int n, data;
	cout << "Nhap n = ";
	cin >> n;
	cout << "Nhap phan tu dau tien: ";
	cin >> data;
	node* l = khoiTaoNode(data);
	node* p = l;
	for (int i = 1; i < n; i++) {
		//node* p = l;
		cout << "Nhap pt tiep: ";
		cin >> data;
		p = addPT(p, data);
	}
	xuatPT(l);
}
