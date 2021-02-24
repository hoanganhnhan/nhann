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
node* addPTcuoi(node* p, int x) {
	node* l = p;
	while (l->next != NULL) {
		l = l->next;
	}
	node* them = addPT(l, x);
	//temp->data = x;
	//temp->next = NULL;
	l->next = them;
	return p;
}
node* addPTdau(node* p, int data) {
	node* temp = khoiTaoNode(data);
	temp->next = p;
	p = temp;
	return temp;
}
node* addPTk(node* p, int k, int x) {
	node* canAdd = p;
		for (int i = 0; i < k - 1; i++) {
			canAdd = canAdd->next;
		}
		node* temp = khoiTaoNode(x);
		temp->next = canAdd->next;
		canAdd->next = temp;
		return p;
}

void xuatPT(node* p) {
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}
int main() {
	int n, k, x, data;
	cout << "Nhap n = ";
	cin >> n;
	cout << "Nhap phan tu dau tien: ";
	cin >> data;
	node* dautien = khoiTaoNode(data);
	node* p = dautien;
	for (int i = 1; i < n; i++) {
		cout << "Nhap phan tu tiep theo: ";
		cin >> data;
		p = addPT(p, data);
	}
	cout << "Nhap vi tri can chen: ";
	cin >> k;
	cout << "Nhap phan tu can chen: ";
	cin >> x;
	if (k == 0) {
		dautien = addPTdau(dautien, x);
	}
	else {
		if (k == n) {
			dautien = addPTcuoi(dautien, x);
		}
		else {
			dautien = addPTk(dautien, k, x);
		}
	}
	xuatPT(dautien);
	return 0;
}