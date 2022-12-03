#ifndef TASK2__ARRAYS_H
#define TASK2__ARRAYS_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int* memory(int n, int m);
void printarr(int** arr, int n,int col);
void scanarr(int** arr, int n, int m);
void randarr(int** arr, int n, int m);
void deleter(int** arr, int n, int col);
void size(int* row, int* col);
void ch12(int *arr, int n,int m);
int* mem(int** arr, int counter);
void* freememi(int n, int**arr);

#endif //TASK2__ARRAYS_H
