#include <iostream>
using namespace std;
  

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start]; 
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    } 
}     
  

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
      
    reverseArray(arr, 0, n-1);
      
    cout << "Reversed array is" << endl;
      
    printArray(arr, n);
      
    return 0;
}