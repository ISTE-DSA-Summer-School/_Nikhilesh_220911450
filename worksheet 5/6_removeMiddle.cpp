#include <iostream>
#include <vector>
using namespace std;

class Stack{
    private:
        static const int MAX_SIZE = 100;
        int top;
        char a[MAX_SIZE];
    public:
        Stack(){
            top = -1;
        }
        bool isEmpty() {
            return top == -1;
        }
    
        bool isFull() {
                return top == MAX_SIZE - 1;
            }
            void push(char value) {
            if (!isFull()) {
                top++;
                a[top] = value;
            } else {
                cout << "Cannot push " << value << ", stack is full." << endl;
            }
        }
    
        char pop() {
            if (!isEmpty()) {
                char value = a[top];
                top--;
                return value;
            } else {
                cout << "Cannot pop from an empty stack." << endl;
                return '\0';
            }
        }
        
        bool isEqual(const Stack& other) const {
            if (top != other.top)
                return false;
    
            for (int i = 0; i <= top; i++) {
                if (a[i] != other.a[i])
                    return false;
            }
    
            return true;
        }
        
        int peek() {
            if (!isEmpty()) {
                return a[top];
            } else {
                cout << "Stack is empty, cannot get the top element." << endl;
                return -1; 
            }
    }
};


int main()
{
	vector<int> a = {1, 2, 3, 4, 5};
    int size =0;
    Stack stack;
    
    for (int c : a) {
        stack.push(c);
        size ++;
    }
    
    int middle = size / 2;

    Stack temp;

    for (int i = 0; i < middle; i++) {
        temp.push(stack.peek());
        stack.pop();
    }

    stack.pop();

    while (!temp.isEmpty()) {
        stack.push(temp.peek());
        temp.pop();
    }
    
    while (!stack.isEmpty()) {
        cout << stack.peek() << " ";
        stack.pop();
    }
    
	return 0;
}
