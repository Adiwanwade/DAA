// • By taking default as ascending order
// • Divide into two until only one is remaining as sorted and then merge the sorted

//                              | 9 | 8 | 7 | 6 | 5 | 4 | 3 |
//                                  /                   \
//                                                     
//                       | 9 | 8 | 7  |                 | 6 | 5 | 4 | 3 |
//                      /              \                /                \  
//
//               |9 | 8 |              |7|           |6|5|                |4|3|    
//
//              /        \              |            /   \                 /   \
//          |9|         |8|            |7|         |6|    |5|           |4|   |3|  
//
//               \    /                 |             \  /                \   /
//                |8|9|                |7|            |5|6|               |3|4| 
//
//                        \           /                       \            /
//                          |7|8|9|                            |3|4|5|6| 
//
//                                 \                          /   
//
//                                        |3|4|5|6|7|8|9|

#include<stdio.h>
#include<stdlib.h>
struct array{
    int size;
    int*arr;
};

// Merges two subArrays of arr[]. 
// First subArray is arr[l..m] 
// Second subArray is arr[m+1..r] 
void merge(struct array*s, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    // Create temp arrays 
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = s->arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = s->arr[m + 1 + j]; 
  
    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subArray 
    i = 0; 
  
    // Initial index of second subArray 
    j = 0; 
  
    // Initial index of merged subArray 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            s->arr[k] = L[i]; 
            i++; 
        } 
        else { 
            s->arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        s->arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        s->arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void mergeSort(struct array*s, int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and r 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(s, l, m); 
        mergeSort(s, m + 1, r); 
  
        merge(s, l, m, r); 
    } 
} 

void printArray(struct array* s) {
  for (int i = 0; i < s->size; i++) {
    printf("%d  ", s->arr[i]);
  }
  printf("\n");
}


int main(){
//     int i=0;
//     struct array *s=(struct array*)malloc(sizeof(struct array));
//     printf("Enter the size of array:");
//     scanf("%d",&(s->size));
//     s->arr=(int*)malloc(s->size*sizeof(int));
//     printf("Enter the elements of array:\n");
//     for(i=0;i<s->size;i++){
//         scanf("%d",&(s->arr[i]));
//     }
//    mergeSort(s,0,s->size-1);
//     printf("The sorted array is:");
//     printArray(s);
//     return 0;


 int i = 0;
    struct array *s = (struct array *)malloc(sizeof(struct array));

    // Open the file for reading
    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1;
    }

    // Read the size of the array from the file
    fscanf(file, "%d", &(s->size));

    // Allocate memory for the array
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Read the elements of the array from the file
    for (i = 0; i < s->size; i++) {
        fscanf(file, "%d", &(s->arr[i]));
    }

    // Close the file
    fclose(file);

    // Perform merge sort
    mergeSort(s, 0, s->size-1);

    // Print the sorted array
    printf("The sorted array is:");
    printArray(s);

    // Free allocated memory
    free(s->arr);
    free(s);

    return 0;

}
// _________________________________________
// Depends on structure or content ?
// • Structure
// Internal/External sort algorithm ?
// • External
// Stable/Unstable sort algorithm ?
// • Stable
// Best case time complexity ?
// • O(nlogn)
// Worst case time complexity ?
// • O(nlogn)
// • Algorithmic Approach?
// • Divide and Conquer
//                  n
//              /       \
//            n/2        n/2
//           /  \       /  \
//          n/4  n/4   n/4  n/4   
          