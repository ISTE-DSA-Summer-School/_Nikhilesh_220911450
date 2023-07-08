
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
    
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
      
    cout << "Bubble sorted array is" << endl;
      
    printArray(arr, n);
      
    return 0;
}
