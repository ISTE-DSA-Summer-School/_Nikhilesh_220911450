#include <bits/stdc++.h>
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

int waterStored(int height[], int n)
{
  
    Stack st;
  
    int ans = 0;
  
    for (int i = 0; i < n; i++) {
        while ((!st.isEmpty()) && (height[st.peek()] < height[i])) {
  
            int pop_height = height[st.peek()];
            st.pop();

            if (st.isEmpty())
                break;
  
            int distance = i - st.peek() - 1;
  
            int min_height = min(height[st.peek()], height[i])- pop_height;
  
            ans += distance * min_height;
        }

        st.push(i);
    }
    return ans;
}
  
int main()
{
  
    int arr[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    cout << waterStored(arr, n);
  
    return 0;
}





//original approach

#include <bits/stdc++.h>
using namespace std;

int WaterStored2(vector<int>& arr)
{
	int blocks = 0;
	int n = 0;
	int max_height = 0;

	for (auto height : arr) {
		blocks += height;
		n += 1;
		max_height = max(max_height, height);
	}

	int water = 0;
	int left = 0;
	int right = n - 1;

	for (int i = 1; i <= max_height; i++) {

		while (arr[left] < i)
			left += 1;

		while (arr[right] < i)
			right -= 1;

		water += (right - left + 1);
	}

	water -= blocks;
	return water;
}

int main()
{
	vector<int> arr
		= { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

	cout << WaterStored2(arr) << endl;
	return 0;
}