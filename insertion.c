// • By taking default as ascending order
// • Consider first element as sorted
// • Pick one element put it in its right position and then pick another put it in its correct position.
// • repeat this until all are sorted
// • _ one to pick 
// | 9 | 8 _| 7 | 6 | 5 | 4 | 3 |
// | 8 | 9 | 7 _| 6 | 5 | 4 | 3 |
// | 7 | 8 | 9 | 6 _| 5 | 4 | 3 |
// | 6 | 7 | 8 | 9 | 5 _| 4 | 3 |
// | 5 | 6 | 7 | 8 | 9 | 4 _| 3 |
// | 4 | 5 | 6 | 7 | 8 | 9 | 3 _|
// | 3 | 4 | 5 | 6 | 7 | 8 | 9 _|

// like playing cards

#include<stdio.h>
#include<stdlib.h>
struct array{
    int size;
    int*arr;
};
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void insertionSort(struct array*s) {
 int i, key, j;
    for (i = 1; i < s->size; i++) 
    {
        key = s->arr[i];
        j = i - 1;
 
        /* Move elements of s->arr[0..i-1], 
           that are greater than key, 
           to one position ahead of 
           their current position */
        while (j >= 0 && s->arr[j] > key) 
        {
            s->arr[j + 1] = s->arr[j];
            j = j - 1;
        }
        s->arr[j + 1] = key;
    }    
}

void printArray(struct array* s) {
  for (int i = 0; i < s->size; i++) {
    printf("%d  ", s->arr[i]);
  }
  printf("\n");
}


int main(){
    int i=0;
    struct array *s=(struct array*)malloc(sizeof(struct array));
    printf("Enter the size of array:");
    scanf("%d",&(s->size));
    s->arr=(int*)malloc(s->size*sizeof(int));
    printf("Enter the elements of array:\n");
    for(i=0;i<s->size;i++){
        scanf("%d",&(s->arr[i]));
    }
   insertionSort(s);
    printf("The sorted array is:");
    printArray(s);
    return 0;
}
// _________________________________________
// • Depends on structure or content?    
// • ->Both because of flag
// • Internal/External sort algorithm?
// • ->Internal- O(1)
// • Stable/Unstable sort algorithm ?
// • ->stable with flag
// • Best case time complexity?
// • ->O(n) 
// • Worst case time complexity ?
// • ->O(n²)
// • Algorithmic Approach?
// • ->Subtract and Conquer
//             n
//            / \
//          1    n-1
//               /  \
//             1     n-2