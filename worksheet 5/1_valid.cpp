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

bool isValid(string s) {
    Stack stack;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } 
        else if (!stack.isEmpty()) {
            char topChar = stack.peek();
            if ((c == ')' && topChar == '(') ||
                (c == '}' && topChar == '{') ||
                (c == ']' && topChar == '[')) {
                stack.pop();
            } 
            else {
                return false;
            }
        } 
        else {
            return false;
        }
    }

    return stack.isEmpty();
}


int main()
{
	string s;
	cout << "Input string of characters: " << endl;
	getline(cin, s);
	if(isValid(s))
	    cout << "String is valid";
	else 
	    cout << "String is invalid";
    
	return 0;
}
