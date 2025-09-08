#include <iostream>
using namespace std;

// Function to combine two sorted subarrays into one sorted section
void combine(int data[], int start, int mid, int end) {
    int leftSize = mid - start + 1;   // size of first subarray
    int rightSize = end - mid;        // size of second subarray

    int leftArr[leftSize], rightArr[rightSize]; // temporary arrays

    // copy elements into left array
    for (int p = 0; p < leftSize; p++)
        leftArr[p] = data[start + p];

    // copy elements into right array
    for (int q = 0; q < rightSize; q++)
        rightArr[q] = data[mid + 1 + q];

    int i = 0, j = 0, k = start;

    // merge back into original array
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            data[k] = leftArr[i];
            i++;
        } else {
            data[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // add remaining from left side
    while (i < leftSize) {
        data[k] = leftArr[i];
        i++;
        k++;
    }

    // add remaining from right side
    while (j < rightSize) {
        data[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive merge sort
void mergeSortAlgo(int data[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergeSortAlgo(data, start, mid);     // sort left
        mergeSortAlgo(data, mid + 1, end);   // sort right

        combine(data, start, mid, end);      // merge
    }
}

// Linear search: check every index for target
void linearSearch(int nums[], int length, int target) {
    int foundCount = 0;
    for (int i = 0; i < length; i++) {
        if (nums[i] == target) {
            cout << "Found at index " << i << "\n";
            foundCount++;
        }
    }
    if (foundCount == 0) {
        cout << "Element not present\n";
    }
}

// Binary search: works on sorted array
void binarySearch(int nums[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == key) {
            cout << "Found at index: " << mid << "\n";
            return;
        } else if (nums[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Element not found\n";
}

int main() {
    int option;

    do {
        cout << "Menu:\n1. Selection Sort\n2. Merge Sort\n3. Linear Search\n4. Binary Search\n0. Exit\n";
        cin >> option;

        switch (option) {
            case 1: {
                // Selection Sort
                int n;
                cout << "Enter size: ";
                cin >> n;

                int values[100];
                cout << "Enter " << n << " numbers: ";
                for (int i = 0; i < n; i++) {
                    cin >> values[i];
                }

                // selection sort logic
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (values[i] > values[j]) {
                            int temp = values[i];
                            values[i] = values[j];
                            values[j] = temp;
                        }
                    }
                }

                cout << "Sorted: ";
                for (int i = 0; i < n; i++) {
                    cout << values[i] << " ";
                }
                cout << endl;
                break;
            }

            case 2: {
                // Merge Sort
                int n;
                cout << "Enter size: ";
                cin >> n;

                int values[100];
                cout << "Enter " << n << " numbers: ";
                for (int i = 0; i < n; i++) {
                    cin >> values[i];
                }

                mergeSortAlgo(values, 0, n - 1);

                cout << "After Merge Sort: ";
                for (int i = 0; i < n; i++) {
                    cout << values[i] << " ";
                }
                cout << endl;
                break;
            }

            case 3: {
                // Linear Search
                int n, target;
                cout << "Enter size: ";
                cin >> n;

                int arr[100];
                cout << "Enter " << n << " numbers: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                cout << "Enter value to search: ";
                cin >> target;

                linearSearch(arr, n, target);
                break;
            }

            case 4: {
                // Binary Search
                int n, target;
                cout << "Enter size: ";
                cin >> n;

                int arr[100];
                cout << "Enter " << n << " numbers: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                // simple bubble sort before binary search
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }

                cout << "Sorted Array: ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;

                cout << "Enter value to search: ";
                cin >> target;

                binarySearch(arr, n, target);
                break;
            }

            case 0:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid input, try again.\n";
                break;
        }

    } while (option != 0);

    return 0;
}

