#include <iostream>
using namespace std;

#define MAX 100

struct Queue {
    int arr[MAX];
    int headIndex = 0; // Vị trí đầu hàng chờ
    int tailIndex = 0; // Vị trí tiếp theo để thêm phần tử
    int count = 0;     // Số lượng phần tử hiện có
};

// Enqueue: Thêm phần tử vào cuối Queue
void enqueue(Queue &q, int x) {
    if (q.count >= MAX) {
        cout << "Queue day (Overflow)!\n";
        return;
    }
    q.arr[q.tailIndex] = x;
    q.tailIndex = (q.tailIndex + 1) % MAX; // Tăng chỉ số theo dạng mảng vòng
    q.count++;
}

// Dequeue: Lấy và xóa phần tử ở đầu Queue
int dequeue(Queue &q) {
    if (q.count == 0) {
        cout << "Queue rong!\n";
        return -1;
    }
    int val = q.arr[q.headIndex];
    q.headIndex = (q.headIndex + 1) % MAX; // Tăng chỉ số theo dạng mảng vòng
    q.count--;
    return val;
}

// Front: Xem giá trị phần tử ở đầu Queue
int front(Queue q) {
    if (q.count == 0) {
        cout << "Queue rong!\n";
        return -1;
    }
    return q.arr[q.headIndex];
}

// Kiểm tra Queue rỗng
bool isEmpty(Queue q) {
    return q.count == 0;
}

int main() {
    Queue q;

    enqueue(q, 100);
    enqueue(q, 200);
    enqueue(q, 300);

    cout << "Front hien tai: " << front(q) << endl;        
    cout << "Lay ra (Dequeue): " << dequeue(q) << endl;    
    cout << "Front sau Dequeue: " << front(q) << endl;      

    return 0;
}
