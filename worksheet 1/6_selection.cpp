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
    
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
            swap(arr[min], arr[i]);
    }
      
    cout << "Selection sorted array is" << endl;
      
    printArray(arr, n);
      
    return 0;
}
