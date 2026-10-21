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

// Enqueue: Chèn vào cuối danh sách liên kết
void enqueue(Node *&dau, int x) {
    Node *p = taoNode(x);

    if (dau == NULL) {
        dau = p;
        return;
    }

    Node *q = dau;
    while (q->next != NULL)
        q = q->next;

    q->next = p;
}

// Dequeue: Lấy và xóa phần tử ở đầu danh sách liên kết
int dequeue(Node *&dau) {
    if (dau == NULL) {
        cout << "Queue rong!\n";
        return -1;
    }

    Node *p = dau;
    int val = p->data;
    dau = dau->next;
    delete p;
    return val;
}

// Front: Xem phần tử ở đầu hàng đợi
int front(Node *dau) {
    if (dau == NULL) {
        cout << "Queue rong!\n";
        return -1;
    }
    return dau->data;
}

// Kiểm tra Queue rỗng
bool isEmpty(Node *dau) {
    return dau == NULL;
}

int main() {
    Node *queue = NULL;

    enqueue(queue, 100);
    enqueue(queue, 200);
    enqueue(queue, 300);

    cout << "Front hien tai: " << front(queue) << endl;      
    cout << "Gia tri lay ra (Dequeue): " << dequeue(queue) << endl;
    cout << "Front sau khi dequeue: " << front(queue) << endl;    

    return 0;
}
