#include <iostream>
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
};


int main()
{
	string input;
    cout << "Enter a string: ";
    getline(cin, input);

    Stack stack;

    for (char c : input) {
        stack.push(c);
    }

    string rev;
    while (!stack.isEmpty()) {
        rev += stack.pop();
    }
    cout << "Reversed string: " << rev << endl;
    
	return 0;
}