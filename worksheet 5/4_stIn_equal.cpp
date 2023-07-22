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
        
        bool isEqual(const Stack& other) const {
            if (top != other.top)
                return false;
    
            for (int i = 0; i <= top; i++) {
                if (a[i] != other.a[i])
                    return false;
            }
    
            return true;
        }
};

bool Check(string a, string b){
    
    Stack stack1;
    Stack stack2;
    

    for (char c : a) {
        if(c != '#')
            stack1.push(c);
        else if(!stack1.isEmpty())
            stack1.pop();
    }
    for (char c : b) {
        if(c != '#')
            stack2.push(c);
        else if(!stack2.isEmpty())
            stack2.pop();
    }
    return stack1.isEqual(stack2);
}


int main()
{
	string a,b;
    cout << "Enter input 1: " << endl;
    getline(cin, a);
    cout << "\nEnter input 2:" << endl;
    getline(cin, b);

    if(Check(a,b))
        cout << "Inputs are equal" << endl;
    else
        cout << "Inputs are not equal" << endl;
	return 0;
}