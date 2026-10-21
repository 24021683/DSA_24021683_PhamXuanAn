#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* taoNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// Push: Chèn vào đầu danh sách liên kết
void push(Node *&dau, int x) {
    Node *p = taoNode(x);
    p->next = dau;
    dau = p;
}

// Pop: Lấy và xóa phần tử ở đầu danh sách liên kết
int pop(Node *&dau) {
    if (dau == NULL) {
        cout << "Stack rong!\n";
        return -1;
    }
    Node *p = dau;
    int val = p->data;
    dau = dau->next;
    delete p;
    return val;
}

// Top: Lấy giá trị của phần tử trên cùng
int top(Node *dau) {
    if (dau == NULL) {
        cout << "Stack rong!\n";
        return -1;
    }
    return dau->data;
}

// Kiểm tra Stack rỗng
bool isEmpty(Node *dau) {
    return dau == NULL;
}

int main() {
    Node *stack = NULL;

    push(stack, 100);
    push(stack, 200);
    push(stack, 300);

    cout << "Top hien tai: " << top(stack) << endl;    
    cout << "Gia tri lay ra (Pop): " << pop(stack) << endl; 
    cout << "Top sau khi pop: " << top(stack) << endl;  

    return 0;
}
