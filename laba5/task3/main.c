#include "Arrays.h"
#include <time.h>
int main(){

    int  row, col, **arr;
    int start= clock();
    size(&row,&col);
    arr = memory(row,col);
    printf("Выберете тип ввода массива :\n1-Ручной ввод\n2-Заполнение псевдослучайными числами\n");
    ch12(arr,row,col);
    printf("\n\x1b[33mИсходный массив :\n");
    printarr(arr, row, col);
    printf("\n\x1b[33mРедактированный массив :\n");
    deleter(arr, row, col);
    freememi(row, arr);
    int fin=clock();
    printf("%d",(fin-start)/1000);
}