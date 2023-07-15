#include <iostream>

using namespace std;

void matrixInput(int* a, int m, int n) {
   for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
         cin >> *(a + r * n + c);
      }
   }
}


void matrixPrint(int* a, int m, int n) {
   for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
         cout << *(a + r * n + c) << " ";
      }
      cout << endl;
   }
}

void matrixMultiply(int* a, int* b, int m1, int n1, int m2, int n2, int* d) {
   if (n1 != m2) {
      cout << "Matrices cannot be multiplied" << endl;
      return;
   }

   for (int r = 0; r < m1; r++) {
      for (int c = 0; c < n2; c++) {
         int sum = 0;
         for (int i = 0; i < n1; i++) {
            sum += *(a + r * n1 + i) * *(b + i * n2 + c);
         }
         *(d + r * n2 + c) = sum;
      }
   }
}


int main()
{
    int m1, n1, m2, n2;
    cout << "Enter dimensions of the both matrices:" << endl;
    cin >> m1 >> n1 >> m2 >> n2;

    int a[m1][n1], b[m2][n2], ans[m1][n2];

    if (m2 != n1) {
        cout << "Matrices cannot be multiplied" << endl;
        return 0;
    }

    cout << "Enter first matrix:" << endl;
    matrixInput((int*)a, m1, n1);

    cout << "Enter second matrix:" << endl;
    matrixInput((int*)b, m2, n2);

    matrixMultiply((int*)a, (int*)b, m1, n1, m2, n2, (int*)ans);

    cout << "Product is:" << endl;
    matrixPrint((int*)ans, m1, n2);
    
    return 0;
}
