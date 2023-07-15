#include <iostream>

using namespace std;

void reverseDigits(int* x) {
    int rev = 0;
    
    while (*x != 0) {
        int rem = *x % 10;
        rev = rev * 10 + rem;
        *x /= 10;
    }
    
    *x = rev;
}

int main()
{
  int x;
  cout << "Enter a number" << endl;
  cin >> x;
  reverseDigits(&x);
  cout << "The number with digits reversed is: " << x;
  return 0;
}