#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int* memory(int n, int m)
{
    int **arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        *(arr + i) = (int*)calloc(m, sizeof(int));
    return arr;
}

void* freememi(int n, int**arr){
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

void printarr(int** arr, int n,int col){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < col; j++) {
            printf("\x1b[35m%5d\t\x1b[0m", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void scanarr(int** arr, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Введите элемент массива [%d][%d] : ", i + 1, j + 1);
            while (scanf("%d", *(arr + i) + j) != 1 || getchar() != '\n') {
                printf("Неверный ввод. Попробуйте ещё раз : ");
                fflush(stdin);
            }
        }
    }
}

void randarr(int** arr, int n, int m){
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            *(*(arr + i) + j) = rand() % 201-100;
        }
    }
}

int* mem(int n, int* arr){
    arr=(int*)realloc(arr, (n)*sizeof(int*));
    return arr;
}

void deleter(int** arr, int n, int col){
    int max = 0, colmax = 0;
    for (int j = 0; j < col; j++){
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += *(*(arr + i) + j);
            if (sum > max) {
                max = sum;
                colmax = j;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = colmax; j < col-1; j++) {
            *(*(arr + i) + j) = *(*(arr + i) + j + 1);
        }
        arr=mem(n,arr);
    }
}

void size(int* row, int* col){
    printf("Введите количество строк : ");
    int p,o;
    while (scanf("%d", &p) != 1 || p > 100 || p < 1 || p % 1 != 0 || getchar() != '\n'){
        printf("Неверный ввод. Попробуйте ещё раз : ");
    }
    printf("Введите количество столбцов : ");
    *row = p;
    while (scanf("%d", &o) != 1 || o > 100 || o < 1 || o % 1 != 0 || getchar() != '\n'){
        printf("Неверный ввод. Попробуйте ещё раз : ");
    }
    *col = o;
}

void ch12(int *arr,int row, int col){
    int yn;
    while (scanf("%d", &yn) != 1 || yn > 2 || yn < 1 || yn % 1 != 0 || getchar() != '\n'){
        printf("Неверный ввод. Попробуйте ещё раз : ");
        fflush(stdin);
    }
    if(yn==1){
        printf("\nВведите элементы массива : \n");
        scanarr(arr, row, col);
    }
    else randarr(arr, row, col);
}