#include <iostream>
using namespace std;

class Queue {
public:    int front, rear, max_size;
public:   int* arr;

    // Queue constructor
    Queue(int c) {
        front = rear = 0;
        max_size = c;
        arr = new int;
    }

    // ham kiem tra rong
    bool isEmpty() {
        if (front == rear) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (rear == max_size) {
            return true;
        }
        return false;
    }

    // phuong thuc enQueue
    void enQueue(int data) {
        if (isFull()) {
            cout << "\nFull\n";
            return;
        } else {
            arr[rear++] = data;
        }
    }

    // phuong thuc deQueue
    void deQueue() {
        if (isEmpty()) {
            cout << "\nQueue is empty";
            return;
        } else {
            // nếu Queue không rỗng thì đẩy toàn bộ Queue trước rear lên phía trước (front) 1 ô
            for (int i = 0; i < rear - 1; i++) {
                arr[i] = arr[i + 1];
            }
            rear--;
        }
    }

    // phuong thuc in Queue
    void printQueue() {
        if (isEmpty()) {
            cout << "\nQueue is empty\n";
            return;
        }

        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // phuong thuc tim ra kich thuoc hien tai cua Queue
    int queueSize() {
        return rear - front;
    }

    // phuong thuc peek
    void peek() {
        if (isEmpty()) {
            cout << "\nQueue is empty\n";
        }
        cout << "peek: " << arr[rear] << endl;
    }
};


int main() {
    Queue queue(10);

    queue.enQueue(5);
    queue.enQueue(10);
    queue.enQueue(15);
    queue.enQueue(20);
    queue.enQueue(25);
    queue.enQueue(35);
    queue.enQueue(40);
    queue.enQueue(45);
    queue.enQueue(50);
    queue.enQueue(55);

    queue.deQueue();

    queue.printQueue();
    cout << "size = " << queue.queueSize();
}