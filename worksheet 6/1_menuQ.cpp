#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full. Cannot enter." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear++;
        arr[rear] = data;
        cout << data << " Put in queue." << endl;
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
            front++;
        }

        cout << data << " dequeued successfully." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    int choice, data;

    do {
        cout << "---------------------" << endl;
        cout << "Queue Implementation" << endl;
        cout << "---------------------" << endl;
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
