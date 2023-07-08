#include <iostream>
using namespace std;
  
void printArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   cout << arr[i] << " ";
  
   cout << endl;
} 
  

int main() 
{
    int arr[100];
    int n;
    cout << "enter length of array";
    cin >> n;
    cout << "Enter array";
    for(int l=0;l <n;l++){
        cin >> arr[l];
    }
    
    printArray(arr, n);
    
    int i, j, k;
    for (i = 1; i < n; i++) {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
      
    cout << "Insertion sorted array is" << endl;
      
    printArray(arr, n);
      
    return 0;
}
