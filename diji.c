#include<stdio.h>
#include <limits.h>
#include<stdlib.h>
struct twoarray{
int row;
int col;
int **arr;
};
struct array{
int size;
int *arr;
};
int minDistance(struct array *dist, struct array *sptSet)
{
int min = INT_MAX, min_index;
int v;
for ( v = 0; v < dist->size; v++)
{
if (sptSet->arr[v] == 0 && dist->arr[v] <= min)
{
min = dist->arr[v];
min_index = v;
}
}
return min_index;
}
void printSolution(struct array *dist)
{ int i;
printf("Vertex \t Distance from Source\n");
for (i = 0; i < dist->size; i++)
{
printf("%d \t %d\n", i, dist->arr[i]);
}
}
void dijkstra(struct twoarray *s, int src)
{
struct array* dist=(struct array*)malloc(sizeof(struct array));
dist->size=s->row;
dist->arr=(int*)malloc(dist->size*sizeof(int));
struct array*sptSet =(struct array*)malloc(sizeof(struct array));
sptSet->size=s->row;
sptSet->arr=(int*)malloc(sptSet->size*sizeof(int));
int i,count,v;
for ( i = 0; i < s->row; i++)
{
dist->arr[i] = INT_MAX;
sptSet->arr[i] = 0;
}
dist->arr[src] = 0;
for ( count = 0; count < (s->row - 1); count++)
{
int u = minDistance(dist, sptSet);
sptSet->arr[u] = 1;
for (v = 0; v < s->row; v++)
{
if (!sptSet->arr[v] && s->arr[u][v] && dist->arr[u] != INT_MAX &&
dist->arr[u] + s->arr[u][v] < dist->arr[v])
{
dist->arr[v] = dist->arr[u] + s->arr[u][v];
}
}
}
printSolution(dist);
}
int main()
{
int i,j;
struct twoarray *s=(struct twoarray*)malloc(sizeof(struct twoarray));
printf("Enter the number of rows:");
scanf("%d",&(s->row));
printf("Enter the number of Columns:");
scanf("%d",&(s->col));
printf("Enter the elements of adjacency matrix:\n");
s->arr=(int**)malloc(sizeof(int*)*(s->row));
for (i = 0; i < s->row; i++) {
s->arr[i] = (int*) malloc(s->col * sizeof(int));
if (s->arr[i] == NULL) {
printf("Memory allocation failed!");
return -1;
}
}
for (i = 0; i < s->row; i++) {
for (j = 0; j < s->col; j++) {
scanf("%d", &(s->arr[i][j]));
}
}
printf("Enter the source node:");
int source = 0;
scanf("%d",&source);
dijkstra(s, source);
return 0;
}