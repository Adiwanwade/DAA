// • By taking default as ascending order so smallest first
// • if the Adjacent elements are not in order like the one towards left should be smaller than the one on right
// • repeat this until all are sorted
// | 9 | 8 | 7 | 6 | 5 | 4 | 3 |
// | 8 | 9 | 7 | 6 | 5 | 4 | 3 |
// | 8 | 7 | 9 | 6 | 5 | 4 | 3 |
// | 8 | 7 | 6 | 9 | 5 | 4 | 3 |
// | 8 | 7 | 6 | 5 | 9 | 4 | 3 |
// | 8 | 7 | 6 | 5 | 4 | 9 | 3 |
// | 8 | 7 | 6 | 5 | 4 | 3 | 9 |
// 
// | 8 | 7 | 6 | 5 | 4 | 3 | 9 |
// | 7 | 8 | 6 | 5 | 4 | 3 | 9 |
// | 7 | 6 | 8 | 5 | 4 | 3 | 9 |
// | 7 | 6 | 5 | 8 | 4 | 3 | 9 |
// | 7 | 6 | 5 | 4 | 8 | 3 | 9 |
// | 7 | 6 | 5 | 4 | 3 | 8 | 9 |

// • Subtract and Conquer
// • right to left  sort

// without flag
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
void bubbleSort(struct array*s) {
 int i, j, temp;  
   for(i = 0; i < s->size; i++)    
    {    
      for(j = i+1; j < s->size; j++)    
        {    
            if(s->arr[j] < s->arr[i])    
            {    
               swap(&(s->arr[j]),&(s->arr[i]));   
            }     
        }     
    }     
}
// ------------------------------------------------------
//  With flag 

// void bubbleSort(struct array*s) {
//  int i, j, temp,flag;  
//    for(i = 0; i < s->size; i++)    
//     {    flag=0; 
//       for(j = i+1; j < s->size; j++)    
//         {    
//             if(s->arr[j] < s->arr[i])    
//             {    
//                swap(&(s->arr[j]),&(s->arr[i]));
//                   flag=1;
//             }     
//         }
//     if(!flag){
//          break;
//     }     
//     }     
// }
//-------------------------------------------------------
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
   bubbleSort(s);
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
// • ->O(n) with flag and without flag O(n²) 
// • Worst case time complexity ?
// • ->O(n²)
// • Algorithmic Approach?
// • ->Subtract and Conquer
//             n
//            / \
//         n-1    1
//       /   \
//     n-2     1