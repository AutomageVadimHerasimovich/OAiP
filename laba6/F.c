#ifndef TASK1_F_H
#define TASK1_F_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void size(int *n){
    int p;
    while (scanf("%d", &p) != 1 || getchar() != '\n' || p>999999 || p<1 || p % 1 != 0){
        printf("Неверный ввод. Попробуйте ещё раз.\n");
        fflush(stdin);
    }
    *n = p;
}

void size_2(int *n, int* m){
    int p, b;
    printf("\x1b[36mВведите количество строк : ");
    while (scanf("%d", &p) != 1 || getchar() != '\n' || p>999999 || p<1 || p % 1 != 0){
        printf("Неверный ввод. Попробуйте ещё раз.\n");
        fflush(stdin);
    }
    *n = p;
    printf("\x1b[36mВведите количество столбцов : ");
    while (scanf("%d", &b) != 1 || getchar() != '\n' || b>999999 || b<1 || b % 1 != 0){
        printf("Неверный ввод. Попробуйте ещё раз.\n");
        fflush(stdin);
    }
    *m = b;
}

void* memory(int n, int*arr){
    arr=(int*)malloc(n * sizeof(int));
    return arr;
}

void check_tsk(int *p){
    int n;
    while (scanf("%d", &n) != 1 || getchar() != '\n' || n%1!= 0 || n<1 || n>2){
        printf("Неверный ввод. Попробуйте ещё раз : ");
        fflush(stdin);
    }
    *p=n;
}

void check_imp(int *p){
    int n;
    while (scanf("%d", &n) != 1 || getchar() != '\n' || n%1!= 0 || n<0 || n>1){
        printf("Неверный ввод. Попробуйте ещё раз : ");
        fflush(stdin);
    }
    *p=n;
}

void scan_arr(int *arr, int n){
    for (int i = 0; i < n; i++){
        while (scanf("%d", &*(arr + i)) != 1 || getchar() != '\n' || *(arr + i) % 1 != 0){
            printf("Неверный ввод. Попробуйте ещё раз : ");
            fflush(stdin);
        }
    }
}

void print_arr(int *arr, int n){
    for (int i = 0; i < n; i++){
        printf("\x1b[35m%d\x1b[0m ", *(arr + i));
    }
}

void* mem(int n, int* arr){
    arr=(int*)realloc(arr, n*sizeof(int));
    return arr;
}

void rand_arr(int*arr, int* bubbl, int* bb, int n){
    srand(time(NULL));
    for (int i = 0; i < n; ++i){
        *(arr + i) = rand() % 201-100;
    }
    for (int i = 0; i < n; ++i){
        *(bubbl + i) = *(arr + i);
    }
    for (int i = 0; i < n; ++i){
        *(bb + i) = *(arr + i);
    }
}

void check_12(int *arr, int* bubbl, int* bb, int row){
    int yn;
    while (scanf("%d", &yn) != 1 || yn > 2 || yn < 1 || yn % 1 != 0 || getchar() != '\n'){
        printf("Неверный ввод. Попробуйте ещё раз : ");
        fflush(stdin);
    }
    if(yn==1){
        printf("\nВведите элементы массива : \n");
        scan_arr(arr, row);
    }
    else rand_arr(arr, bubbl, bb, row);
}

void poloz(int* arr, int n, int* p) {
    int i, j, count = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            for (j = i; j < n; j++) {
                arr[j] = arr[j + 1];
            }
            n--;
            i--;
            count++;
        }
    }
    *p = count;
}

void merge(int* a, int num, int *t1){
    int p;
    poloz(a, num,&p);
    num-=p;
    int rght, rend, i, j, m, *b=(int*)malloc(num*sizeof(int));
    clock_t S=clock();
    for (int k = 1; k < num; k *= 2){
        for (int left = 0; left + k < num; left += k * 2){
            rght = left + k;
            rend = rght + k;
            if (rend > num)
                rend = num;
            m = left; i = left; j = rght;
            while (i < rght && j < rend){
                if (a[i] <= a[j]){
                    b[m] = a[i]; i++;
                }
                else{b[m] = a[j]; j++;}
                m++;
            }
            while (i < rght){
                b[m] = a[i];
                i++; m++;
            }
            while (j < rend){
                b[m] = a[j];
                j++; m++;
            }
            for (m = left; m < rend; m++){
                a[m] = b[m];
            }
        }
    }
    clock_t F=clock();
    free(b);
    *t1=(F-S)*1000/CLOCKS_PER_SEC;
    num+=p;
}

void revers_merge(int* a, int num, int* t3){
    int rght, rend, i, j, m, *b=(int*)malloc(num * sizeof(int));
    int p;
    poloz(a, num,&p);
    num-=p;
    clock_t S=clock();
    for(int k=1;k<num;k*=2){
        for(int left = 0; left + k < num; left += k * 2){
            rght = left + k;
            rend = rght + k;
            if (rend > num)
                rend = num;
            m = left; i = left; j = rght;
            while (i < rght && j < rend){
                if (a[i] >= a[j]){
                    b[m] = a[i]; i++;
                }
                else{b[m] = a[j]; j++;}
                m++;
            }
            while (i < rght){
                b[m] = a[i];
                i++; m++;
            }
            while (j < rend){
                b[m] = a[j];
                j++; m++;
            }
            for (m = left; m < rend; m++){
                a[m] = b[m];
            }
        }
    }
    free(b);
    clock_t F=clock();
    num+=p;
    *t3=(F-S)*1000/CLOCKS_PER_SEC;
}

void zamena(int* arr, int* bubbl, int n) {
    for (int i = 0, z = 0; i < n; i++) {
        if (bubbl[i] > 0) {
            bubbl[i] = arr[z];
            z++;
        }
    }
}

void bubble(int n, int* arr, int* t2){
    int i,j,a,p,m;
    poloz(arr, n, &p);
    m=n;
    n-= p;
    clock_t F,S;
    S = clock() * 1000 / CLOCKS_PER_SEC;
    for (i = 0; i < n - 1; i++) { // выбор верхней границы массива
        for (j = n - 1; j > i; j--) // просмотр массива ”снизу” ”вверх”
        {
            if (arr[j - 1] > arr[j]) // условие замены выполнено
            {
                a = arr[j - 1]; // замена j-1 и j элементов
                arr[j - 1] = arr[j];
                arr[j] = a;
            }
        }
    }
    F= clock() * 1000 / CLOCKS_PER_SEC;
    *t2 =F-S;
    n=m;
}

void sravn(int t1, int t2) {
    if (t1 < t2) {
        printf("Сортировка \x1b[34;40mслиянием\x1b[33;0m \x1b[31;40mбыстрее\x1b[33;0m сортировки \x1b[37;40mпузырьком\x1b[33;0m\n");
    }
    else if (t2 < t1) {
        printf("Сортировка \x1b[37;40mпузырьком\x1b[33;0m \x1b[31;40mбыстрее\x1b[33;0m сортировки \x1b[34;40mслиянием\x1b[33;0m\n");
    }
    else {
        printf("Две сортировки по времени \x1b[34;40mравны\x1b[0;0m\n");
    }
}

///*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*///
///*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*///
///*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*///
///*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*///
///*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*///

void* memory_2(int n, int m)
{
    int** matr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        *(matr + i) = (int*)calloc(m, sizeof(int));
    return matr;
}
void* freee(int n, int** matr) {
    for (int i = 0; i < n; i++)
        free(*(matr + i));
    free(matr);
}

void printarr_2(int** matr, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("\x1b[35m%5d", *(*(matr + i) + j));
        }
        printf("\n");
    }
}

void scanarr_2(int** matr, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Введите элемент [%d][%d]\n", i + 1, j + 1);
            while (scanf("%d", *(matr + i) + j) != 1) {
                printf("Ошибка. Попробуйте снова:\n");
                rewind(stdin);
            }
        }
    }
}

void randarr_2(int** matr, int n, int m){
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            *(*(matr + i) + j) = rand()%6-1;
        }
    }
}

void vybor_sort(int** matr, int n, int m){
    int num, max, count;
    long min = INTMAX_MAX, maks = INTMAX_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (*(*(matr + i) + j) > maks) {
                maks = *(*(matr + i) + j);
            }
            if (*(*(matr + i) + j) < min) {
                min = *(*(matr + i) + j);
            }
        }
    }
    for (int k = 0; k < m; k++) {
        num = k;
        max = 0;
        for (int j = k; j < m; j++) {
            count = 0;
            for (int z = min; z < maks; z++) {
                int temp = 0;
                for (int i = 0; i < n; i++) {
                    if (matr[i][j] == z) {
                        temp++;
                    }
                }
                if (temp > count) {
                    count = temp;
                }
            }
            if (count > max) {
                max = count;
                num = j;
            }
        }
        if (num != k) {
            for (int i = 0; i < n; i++) {
                int t = matr[i][k];
                matr[i][k] = matr[i][num];
                matr[i][num] = t;
            }
        }
    }
    for (int i = 0; i < n; i++){
        *(matr + i) = realloc(*(matr + i), m * sizeof(int));
    }
}

void check_12_2(int *arr,int row, int col){
    int yn;
    while (scanf("%d", &yn) != 1 || yn > 2 || yn < 1 || yn % 1 != 0 || getchar() != '\n'){
        printf("Неверный ввод. Попробуйте ещё раз : ");
        fflush(stdin);
    }
    if(yn==1){
        printf("\nВведите элементы массива : \n");
        scanarr_2(arr, row, col);
    }
    else randarr_2(arr, row, col);
}

#endif //TASK1_F_H
