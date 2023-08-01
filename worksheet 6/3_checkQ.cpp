#include <iostream>
#include <queue>
using namespace std;

class Queue {
private:
    queue<int> q;

public:
    // Function to enqueue an element into the queue
    void enqueue(int data) {
        q.push(data);
    }

    // Function to dequeue an element from the queue
    void dequeue() {
        if (!q.empty()) {
            q.pop();
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return q.empty();
    }

    // Function to get the front element of the queue
    int front() {
        if (!q.empty()) {
            return q.front();
        }
        return -1; // Return -1 if the queue is empty
    }

    // Function to get the size of the queue
    int size() {
        return q.size();
    }

    // Function to check if the element is present in the queue
    bool isElementInQueue(int target) {
        bool found = false;
        queue<int> tempQueue;

        // Process the queue until it is empty
        while (!q.empty()) {
            // Dequeue the front element
            int frontElement = q.front();
            q.pop();

            // Check if the element is the target element
            if (frontElement == target) {
                found = true;
            }

            // Enqueue the front element to the temporary queue
            tempQueue.push(frontElement);
        }

        // Restore the original queue contents from the temporary queue
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

    // Adding elements to the queue
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // Checking if 3 is present in the queue
    int targetElement = 3;
    bool isPresent = q.isElementInQueue(targetElement);

    if (isPresent) {
        cout << targetElement << " is present in the queue." << endl;
    } else {
        cout << targetElement << " is not present in the queue." << endl;
    }

    return 0;
}
