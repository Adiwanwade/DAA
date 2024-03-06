#include <stdio.h>
#include <stdlib.h>

struct array
{
    int score;
    int time;
    int id;
};

int cmp(const void *a, const void *b)
{
    double r1 = ((double)((struct array *)a)->score) / ((struct array *)a)->time;
    double r2 = ((double)((struct array *)b)->score) / ((struct array *)b)->time;
    return (r1 < r2) - (r1 > r2);
}

double maxScore(struct array s[], int maxtime, int size)
{
    qsort(s, size, sizeof(struct array), cmp);

    int cur_weight = 0;
    double final_val = 0.0;
    for (int i = 0; i < size; i++)
    {
        if (cur_weight + s[i].time <= maxtime)
        {
            cur_weight += s[i].time;
            final_val += s[i].score;
            printf("%d\t",s[i].id);
        }
        else
        {
            int remain = maxtime - cur_weight;
            final_val += s[i].score * ((double)remain / s[i].time);
            printf("%d\t",s[i].id);
            break; 
        }
    }
    return final_val;
}

int main()
{
    int i = 0;
    int maxtime, size;

    printf("Enter the number of subjects: ");
    scanf("%d", &size);
    struct array s[size];

    printf("Enter the score of each topic: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &(s[i].score));
    }

    printf("Enter the time of each topic: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &(s[i].time));
    }
     for (i = 0; i < size; i++)
    {
        s[i].id=i+1;
    }


    printf("Enter the maximum time: ");
    scanf("%d", &maxtime);
printf("The selected topics are:");
    double maximumScore = maxScore(s, maxtime, size);
    printf("\nThe maximum score is:%f", maximumScore);

    return 0;
}
