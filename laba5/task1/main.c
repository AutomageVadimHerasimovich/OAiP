#include "arrays.h"
int main(){
    int  n, count=0, *arr=NULL;
    printf("Введите размер массива : ");
    size(&n);
    arr=memory(n);
    printf("\nВведите элементы массива : \n");
    scanarr(arr, n);
    printf("\nИсходный массив : \n");
    printarr(arr,n);
    deleter2num(arr, n, &count);
    n-=count;
    arr=mem(n, arr);
    printf("\nРедактированный массив : \n");
    printarr(arr, n);
    free(arr);
    return 0;
}