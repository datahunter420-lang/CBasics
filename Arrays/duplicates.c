/* **H2.** Take an array of N numbers. Remove all duplicates and print the unique elements only.
```
Input:  {1, 3, 2, 3, 1, 5, 2}
Output: {1, 3, 2, 5} */

#include <stdio.h>

void printUnique(int arr[], int size) {
    printf("{ ");

    for (int i = 0; i < size; i++) {
        int isDuplicate = 0;    // flag — assume unique first

        // check if arr[i] appeared before position i
        for (int j =0  ; j <i ; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;    // found a duplicate — no need to keep checking
            }
        }

        if (!isDuplicate) {
            printf("%d ", arr[i]);
        }
    }

    printf("}\n");
}

int main() {
    int elements[] = {1, 3, 2, 3, 1, 5, 2};
    int size = 7;

    printUnique(elements, size);

    return 0;
}



