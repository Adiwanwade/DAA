#include <stdio.h>
#include <stdlib.h>

struct Talk {
    int startTime;
    int endTime;
    int id;
};

int compareTalks(const void *a, const void *b) {
    return ((struct Talk *)a)->endTime - ((struct Talk *)b)->endTime;
}

void scheduleTalks(struct Talk talks[], int n) {
    
    qsort(talks, n, sizeof(struct Talk), compareTalks);

    
    int i = 0;
    printf("Selected talks:\n");
    printf("Talk %d: Start Time = %d, End Time = %d\n",talks[i].id, talks[i].startTime, talks[i].endTime);

    
    for (int j = 1; j < n; j++) {
      
        if (talks[j].startTime >= talks[i].endTime) {
            printf("Talk %d: Start Time = %d, End Time = %d\n",talks[j].id, talks[j].startTime, talks[j].endTime);
            i = j; 
        }
    }
}

int main() {
    int n;
    printf("Enter the number of talks: ");
    scanf("%d", &n);

    struct Talk talks[n];

   
    for (int i = 0; i < n; i++) {
        printf("Enter start time and end time for Talk %d: ", i + 1);
        talks[i].id=i+1;
        scanf("%d %d", &talks[i].startTime, &talks[i].endTime);
    }
    

    scheduleTalks(talks, n);

    return 0;
}
