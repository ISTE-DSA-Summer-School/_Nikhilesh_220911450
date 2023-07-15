#include <iostream>

using namespace std;

int factorial(int* x) {
    if (*x <= 1) {
        return 1;
    } 
    else {
        int temp = *x - 1;
        return (*x) * factorial(&temp);
    }
}

int main()
{
  int x;
  cout << "Enter a number" << endl;
  cin >> x;
//   int *p = &x;
  int  fact = factorial(&x);
  cout << "The factorial of the number is: " << fact;
  return 0;
}