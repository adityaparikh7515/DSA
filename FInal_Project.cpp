#include <iostream>
using namespace std;

// --------------------- Node Structure ---------------------
class Element {
public:
    int data;          // stores the integer
    Element* link;     // pointer to next node

    // Constructor initializes data and link
    Element(int val) {
        data = val;
        link = NULL;
    }
};

// --------------------- Linked List Structure ---------------------
class Chain {
public:
    Element* start;   // first node pointer
    Element* last;    // last node pointer

    // default constructor initializes empty list
    Chain() {
        start = last = NULL;
    }

    // insert value at end of the list
    void pushBack(int num) {
        Element* fresh = new Element(num);

        if (start == NULL) {
            start = last = fresh;
        } else {
            last->link = fresh;
            last = fresh;
        }
    }

    // insert value at a specific position
    void insertAt(int num, int pos) {
        Element* fresh = new Element(num);
        int idx = 1;

        // insert at beginning
        if (start == NULL || pos <= 1) {
            fresh->link = start;
            start = fresh;

            if (last == NULL) last = fresh;
            return;
        }

        Element* temp = start;
        while (temp->link != NULL && idx < pos - 1) {
            temp = temp->link;
            idx++;
        }

        fresh->link = temp->link;
        temp->link = fresh;

        if (fresh->link == NULL) {
            last = fresh;
        }
    }

    // display linked list values
    void display() {
        Element* ptr = start;
        cout << "List: ";
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->link;
        }
        cout << "NULL\n";
    }
};

// --------------------- Merge Sort ---------------------
void combine(int nums[], int lo, int mid, int hi) {
    int leftLen = mid - lo + 1;
    int rightLen = hi - mid;

    int left[leftLen], right[rightLen];

    for (int i = 0; i < leftLen; i++)
        left[i] = nums[lo + i];
    for (int j = 0; j < rightLen; j++)
        right[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = lo;

    while (i < leftLen && j < rightLen) {
        if (left[i] <= right[j]) {
            nums[k++] = left[i++];
        } else {
            nums[k++] = right[j++];
        }
    }

    while (i < leftLen) {
        nums[k++] = left[i++];
    }
    while (j < rightLen) {
        nums[k++] = right[j++];
    }
}

void mergeSortAlgo(int nums[], int lo, int hi) {
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        mergeSortAlgo(nums, lo, mid);
        mergeSortAlgo(nums, mid + 1, hi);

        combine(nums, lo, mid, hi);
    }
}

// --------------------- Binary Search ---------------------
void binaryFind(int nums[], int len, int key) {
    int low = 0, high = len - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == key) {
            cout << "Located at index: " << mid << "\n";
            return;
        } else if (nums[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Not found.\n";
}

// --------------------- Quick Sort ---------------------
void swapVals(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int split(int nums[], int low, int high) {
    int pivot = nums[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (nums[j] < pivot) {
            i++;
            swapVals(nums[i], nums[j]);
        }
    }
    swapVals(nums[i + 1], nums[high]);
    return i + 1;
}

void quickSortAlgo(int nums[], int low, int high) {
    if (low < high) {
        int pi = split(nums, low, high);

        quickSortAlgo(nums, low, pi - 1);
        quickSortAlgo(nums, pi + 1, high);
    }
}

void printList(int nums[], int n) {
    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;
}

// --------------------- Main Menu ---------------------
int main() {
    Chain obj;
    int choice;

    do {
        cout << "Menu:\n1. Create linked list\n2. Show linked list\n3. Binary Search\n4. Merge Sort\n5. Quick Sort\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                int total, input;
                cout << "How many nodes? ";
                cin >> total;

                for (int i = 0; i < total; i++) {
                    cout << "Enter value " << i + 1 << ": ";
                    cin >> input;
                    obj.pushBack(input);
                }
                cout << "List built successfully.\n";
                break;
            }

            case 2:
                obj.display();
                break;

            case 3: {
                int len, target;
                cout << "Size of array: ";
                cin >> len;

                int arr[100];
                cout << "Enter " << len << " numbers: ";
                for (int i = 0; i < len; i++) {
                    cin >> arr[i];
                }

                // bubble sort before binary search
                for (int i = 0; i < len; i++) {
                    for (int j = i + 1; j < len; j++) {
                        if (arr[i] > arr[j]) {
                            int tmp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = tmp;
                        }
                    }
                }

                cout << "Sorted Array: ";
                for (int i = 0; i < len; i++) cout << arr[i] << " ";
                cout << endl;

                cout << "Enter element to search: ";
                cin >> target;

                binaryFind(arr, len, target);
                break;
            }

            case 4: {
                int len;
                cout << "Size of array: ";
                cin >> len;

                int arr[100];
                cout << "Enter " << len << " numbers: ";
                for (int i = 0; i < len; i++) {
                    cin >> arr[i];
                }

                mergeSortAlgo(arr, 0, len - 1);

                cout << "After Merge Sort: ";
                for (int i = 0; i < len; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }

            case 5: {
                int len;
                cout << "Size of array: ";
                cin >> len;

                int arr[100];
                cout << "Enter " << len << " numbers: ";
                for (int i = 0; i < len; i++) {
                    cin >> arr[i];
                }

                quickSortAlgo(arr, 0, len - 1);
                printList(arr, len);
                break;
            }

            case 0:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid input, try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

