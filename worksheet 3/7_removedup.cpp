#include <iostream>

using namespace std;

int removeDuplicates(int* arr, int size) {
    if (size == 0)
        return 0;

    int temp = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[temp]) {
            temp++;
            arr[temp] = arr[i];
        }
    }

    return temp + 1;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    int newSize = removeDuplicates(arr, size);

    cout << endl << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "New Length: " << newSize << endl;

    return 0;
}