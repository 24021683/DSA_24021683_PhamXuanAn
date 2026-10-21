#include <iostream>
using namespace std;

#define MAX 100

struct Stack {
    int arr[MAX];
    int topIndex = -1; // -1 nghĩa là Stack đang rỗng
};

// Push: Thêm phần tử vào đỉnh Stack
void push(Stack &s, int x) {
    if (s.topIndex >= MAX - 1) {
        cout << "Stack day (Overflow)!\n";
        return;
    }
    s.arr[++s.topIndex] = x;
}

// Pop: Lấy và xóa phần tử ở đỉnh Stack
int pop(Stack &s) {
    if (s.topIndex == -1) {
        cout << "Stack rong!\n";
        return -1;
    }
    return s.arr[s.topIndex--];
}

// Top: Xem giá trị phần tử ở đỉnh Stack
int top(Stack s) {
    if (s.topIndex == -1) {
        cout << "Stack rong!\n";
        return -1;
    }
    return s.arr[s.topIndex];
}

// Kiểm tra Stack rỗng
bool isEmpty(Stack s) {
    return s.topIndex == -1;
}

int main() {
    Stack s;

    push(s, 100);
    push(s, 200);
    push(s, 300);

    cout << "Top hien tai: " << top(s) << endl;        
    cout << "Lay ra (Pop): " << pop(s) << endl;         
    cout << "Top sau khi Pop: " << top(s) << endl;     

    return 0;
}
