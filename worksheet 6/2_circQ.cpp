#include <iostream>
using namespace std;

#define MAX_SIZE 5

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == (rear + 1) % MAX_SIZE);
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = data;
        cout << data << " enqueued successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        int data = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }

        cout << data << " dequeued successfully." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        int i = front;
        cout << "Queue elements: ";
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue queue;
    int choice, data;

    do {
        cout << "-----------------------" << endl;
        cout << "Circular Queue Program" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                queue.enqueue(data);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
