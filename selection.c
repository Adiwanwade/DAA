// •By taking default as ascending order so smallest
// • First find the smallest element across the array start from the start(first element) and go till the end(last element)
// • swap the smallest element with the first and making it as sorted and unsorted partition
// • Then find next smallest from the unsorted array ans swap it with the first of unsorted and repeat till last
// | 9 | 8 | 7 | 6 | 5 | 4 | 3 |
// | 3 _| 8 | 7 | 6 | 5 | 4 | 9 |
// | 3 | 4 _| 7 | 6 | 5 | 8 | 9 |
// | 3 | 4 | 5 _| 6 | 7 | 8 | 9 |
// | 3 | 4 | 5 | 6 _| 7 | 8 | 9 |
// | 3 | 4 | 5 | 6 | 7 _| 8 | 9 |
// | 3 | 4 | 5 | 6 _| 7 | 8 _| 9 |
// | 3 | 4 | 5 | 6 _| 7 | 8 | 9 _|
// • Subtract and Conquer

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
void selectionSort(struct array *s){
int k,min,loc,j;
for(k=0;k<=(s->size-2);k++){
min=s->arr[k];
loc=k;
for(j=k+1;j<=s->size-1;j++){
if(min>s->arr[j]){
    min=s->arr[j];
    loc=j;
}
}
swap(&(s->arr[k]),&(s->arr[loc]));
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
   selectionSort(s);
    printf("The sorted array is:");
    printArray(s);
    return 0;
}