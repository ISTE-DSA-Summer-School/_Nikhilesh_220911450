#include <iostream>
using namespace std;

int maxSubarraySum(int* arr, int size) {
    int maxSum = *arr;
    int currentSum = *arr;
    int maxIndex;
    for (int i = 1; i < size; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        // maxSum = max(maxSum, currentSum);
        if(maxSum < currentSum){
            maxSum = currentSum;
            maxIndex = i;
        }
        
    }
    cout << maxIndex << endl;
    return maxSum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 3, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubarraySum(arr, size);

    cout << "Maximum sum of a subarray: " << maxSum << endl;

    return 0;
}

