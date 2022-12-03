#include <stdlib.h>
#include <stdio.h>
#define Norm \x1b[0m
#define Blue \x1b[31;34m
void size(int *n)
{
    int p;
    while (scanf("%d", &p) != 1 || getchar() != '\n' || p>99999 || p<1 || p % 1 != 0){
        printf("Неверный ввод. Попробуйте ещё раз.\n");
        fflush(stdin);
    }
    *n = p;
}

int* memory(int n){
   int *arr=(int*)malloc(n * sizeof(int));
    return arr;
}

void scanarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        while (scanf("%d", &*(arr + i)) != 1 || getchar() != '\n' || *(arr + i) % 1 != 0)
        {
            printf("Неверный ввод. Попробуйте ещё раз : ");
            fflush(stdin);
        }
    }
}

void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\x1b[34m%d\x1b[0m ", *(arr + i));
    }
}

void deleter2num(int* arr, int n, int* count){
    int i,j,p=0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > 9 && arr[i] < 100 || arr[i]>-100 && arr[i]<-9){
            for (j = i; j < n-1; j++){
                arr[j] = arr[j + 1];
            }
            arr[j]=NULL;
            p++;
            i--;
        }
    }
    *count = p;
}

int* mem(int n, int* arr){
    arr=(int*)realloc(arr, n*sizeof(int*));
    return arr;
}