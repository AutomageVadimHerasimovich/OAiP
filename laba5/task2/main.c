#include "Arrays.h"
int main(){
	int  row, col, **arr;
    size(&row,&col);
    arr = memory(row,col);
	printf("Выберете тип ввода массива :\n1-Ручной ввод\n2-Заполнение псевдослучайными числами\n");
    ch12(arr,row,col);
	printf("\nИсходный массив :\n");
    printarr(arr, row, col);
    deleter(arr, row, col);
	col--;
	printf("\nРедактированный массив :\n");
    printarr(arr, row, col);
    freememi(row,arr);
}