#include <stdio.h>

    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);
    int arr[N];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    int firstLargest, secondLargest;
    if (N >= 2) {
        firstLargest = secondLargest = arr[0];

        for (int i = 1; i < N; ++i) {
            if (arr[i] > firstLargest) {
                secondLargest = firstLargest;
                firstLargest = arr[i];
            } else if (arr[i] > secondLargest && arr[i] != firstLargest) {
                secondLargest = arr[i];
            }
        }
        if (firstLargest == secondLargest) {
            printf("All elements are the same or there is no distinct second largest element.\n");
        } else {
            printf("The FIRST LARGEST = %d\n", firstLargest);
            printf("The SECOND LARGEST = %d\n", secondLargest);
        }
    } else {
        printf("The array should have at least two elements.\n");
    }

    return 0;
}
