#include <iostream>

using namespace std;

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
int main()
{
  int x, y;
  cout << "Enter two numbers" << endl;
  cin >> x >> y;
  swap(x, y);
  cout << "After swapping: " << endl << x << endl << y;
  return 0;
}
