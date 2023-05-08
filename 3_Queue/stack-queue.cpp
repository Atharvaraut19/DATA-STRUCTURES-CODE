#include <iostream>
using namespace std;

// Queue implementation
class Queue {
    int *arr;
    int front, rear, size;
public:
    Queue(int s) {
        arr = new int[s];
        size = s;
        front = -1;
        rear = -1;
    }
    bool isFull() {
        return (front == 0 && rear == size - 1);
    }
    bool isEmpty() {
        return (front == -1);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = x;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return -1;
        }
        int x = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return x;
    }
};

// Stack implementation using queue
class Stack {
    Queue q1, q2;
public:
    Stack(int size) : q1(size), q2(size) {}
    void push(int x) {
        q1.enqueue(x);
    }
    int pop() {
        if (q1.isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }
        int x = q2.dequeue();
        while (!q2.isEmpty()) {
            q1.enqueue(q2.dequeue());
        }
        return x;
    }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Original stack: ";
    for (int i = 0; i < 5; i++) {
        cout << s.pop() << " ";
    }

    cout << "\nReversed stack: ";
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    for (int i = 0; i < 5; i++) {
        cout << s.pop() << " ";
    }

    return 0;
}
