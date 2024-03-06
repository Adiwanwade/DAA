#include<stdio.h>
#include<stdlib.h>
struct array{
    int size;
    int*arr;
};


void merge(struct array*s, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    
    int t[n1], t1[n2]; 
  
     
    for (i = 0; i < n1; i++) 
        t[i] = s->arr[l + i]; 
    for (j = 0; j < n2; j++) 
        t1[j] = s->arr[m + 1 + j]; 
  
     
    i = 0; 
  
 
    j = 0; 
   
    k = l; 
    while (i < n1 && j < n2) { 
        if (t[i] <= t1[j]) { 
            s->arr[k] = t[i]; 
            i++; 
        } 
        else { 
            s->arr[k] = t1[j]; 
            j++; 
        } 
        k++; 
    } 
  
    
    while (i < n1) { 
        s->arr[k] = t[i]; 
        i++; 
        k++; 
    } 
  
   
    while (j < n2) { 
        s->arr[k] = t1[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(struct array*s, int l, int r) 
{ 
    if (l < r) { 
        
        int m = l + (r - l) / 2; 
  
      
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

 int i = 0;
    struct array *s = (struct array *)malloc(sizeof(struct array));

    
    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1;
    }

  
    fscanf(file, "%d", &(s->size));

    
    s->arr = (int *)malloc(s->size * sizeof(int));

 
    for (i = 0; i < s->size; i++) {
        fscanf(file, "%d", &(s->arr[i]));
    }

   
    fclose(file);

   
    mergeSort(s, 0, s->size-1);

    
    printf("The sorted array is:");
    printArray(s);

   
    free(s->arr);
    free(s);

    return 0;

}

          