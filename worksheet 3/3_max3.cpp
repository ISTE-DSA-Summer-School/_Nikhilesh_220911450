#include <iostream>

using namespace std;

int* max(int* x, int* y, int* z) {
    if (*x >= *y && *x >= *z) {
        return x;
    } else if (*y >= *x && *y >= *z) {
        return y;
    } else {
        return z;
    }
}
 
int main()
{
  int x, y, z;
  cout << "Enter three numbers" << endl;
  cin >> x >> y >> z;
  int* maxnum = max(&x,&y,&z);
  cout << "The maximum amongst the three numbers is: " << *maxnum;
  return 0;
}
