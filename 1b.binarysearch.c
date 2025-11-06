#include <stdio.h>
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int arr[] = {2, 4, 10, 15, 18, 25, 32, 35, 40, 42, 50};  // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);  // Size of the array
    int target;
    printf("Enter the number to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, size, target);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }
    return 0;
}
