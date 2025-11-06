#include <stdio.h>
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; 
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid; 
    } else if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, right, target);
    } else {
        return binarySearch(arr, left, mid - 1, target);
    }
}
int main() {
    int size, target;
    printf("Enter the number of elements (sorted): ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements in sorted order:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, 0, size - 1, target);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
} 
