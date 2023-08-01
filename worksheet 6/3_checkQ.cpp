#include <iostream>
#include <queue>
using namespace std;

class Queue {
private:
    queue<int> q;

public:
    void enqueue(int data) {
        q.push(data);
    }

    void dequeue() {
        if (!q.empty()) {
            q.pop();
        }
    }

    bool isEmpty() {
        return q.empty();
    }

    int front() {
        if (!q.empty()) {
            return q.front();
        }
        return -1; 
    }

    int size() {
        return q.size();
    }

    bool isElementInQueue(int target) {
        bool found = false;
        queue<int> tempQueue;

        while (!q.empty()) {
            int frontElement = q.front();
            q.pop();

            if (frontElement == target) {
                found = true;
            }

            tempQueue.push(frontElement);
        }

        while (!tempQueue.empty()) {
            int tempFront = tempQueue.front();
            tempQueue.pop();
            q.push(tempFront);
        }

        return found;
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    int targetElement = 3;
    bool isPresent = q.isElementInQueue(targetElement);

    if (isPresent) {
        cout << targetElement << " is present in the queue." << endl;
    } else {
        cout << targetElement << " is not present in the queue." << endl;
    }

    return 0;
}
