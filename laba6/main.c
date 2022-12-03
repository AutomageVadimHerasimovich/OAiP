#include <stdio.h>
#include "F.h"

int main(){int tsk,retry; do{
        printf("Выберете № задания : \x1b[37;40m[1]\x1b[33;0m  \x1b[37;40m[2]\x1b[33;0m\n");
        check_tsk(&tsk);
        if (tsk==1){
        int n, *arr, *bubbl, *bb, t1 = 0, t2 = 0, t3=0;
        float final, start = clock();
        clock_t nn = clock(), kk;
        printf("\x1b[36mВведите размер массива: ");
        size(&n);
        arr=memory(n, arr);
        bubbl=memory(n, bubbl);
        bb= memory(n,bb);
        printf("\x1b[33mВыберете тип ввода массива :\n\x1b[31m1\x1b[33m-Ручной ввод\n\x1b[31m2\x1b[33m-Заполнение псевдослучайными числами\n");
        check_12(arr, bubbl, bb, n);
        printf("\n\x1b[33mИсходный массив:\n");
        print_arr(arr, n);
        arr=mem(n, arr);
        kk=clock();
        printf("\n\n\x1b[33mОтсортированный слиянием массив:\n");
        merge(arr, n, &t1);
        arr=mem(n,arr);
        zamena(arr,bubbl,n);
        bubbl=mem(n,bubbl);
        print_arr(bubbl, n);
        printf("\n\n\x1b[33mОбратная сортировка слиянием:\n");
        revers_merge(arr, n, &t3);
        arr=mem(n, arr);
        zamena(arr,bubbl,n);
        bubbl=mem(n, bubbl);
        print_arr(bubbl, n);
        printf("\n\n\x1b[33mОтсортированный пузырьком массив:\n");
        bubble(n, bb, &t2);
        bb=mem(n,bb);
        zamena(bb,bubbl,n);
        bubbl=mem(n,bubbl);
        print_arr(bubbl, n);
        printf("\n\n\x1b[33mВремя до сортировок = \x1b[32m%i\x1b[33m(мс)\n\n\x1b[33mВремя сортировки массива слиянием = \x1b[32m%i\x1b[33m(мс)\n\n\x1b[33mВремя сортировки массива пузырьком = \x1b[32m%i\x1b[33m(мс)\n\nВремя сортировки массива слиянием в худшем случае = \x1b[32m%i\x1b[33m(мс)\n\n\x1b[33m",(kk - nn) * 1000 / CLOCKS_PER_SEC, t1, t2, t3);
        sravn(t1, t2);
        free(arr);
        final = clock();
        printf("\n\n\x1b[33mЗатраченное время на выполнение всего алгоритма в секундах :\x1b[31m%.3f\n\n",(final - start) / CLOCKS_PER_SEC);
        printf("Хотите выбрать другое задание?\n\x1b[30;47m[1]\x1b[33;0m-Да\t\x1b[30;47m[0]\x1b[33;0m-Нет\n");
        check_imp(&retry);}
        else{
            int n,m,**arr2;
            size_2(&n,&m);
            arr2=memory_2(n, m);
            printf("\n\x1b[33mВыберете тип ввода массива :\n\x1b[31m1\x1b[33m-Ручной ввод\n\x1b[31m2\x1b[33m-Заполнение псевдослучайными числами\n");
            check_12_2(arr2, n, m);
            printf("\n\x1b[33mНачальная матрица:\n\n");
            printarr_2(arr2, n, m);
            vybor_sort(arr2, n, m);
            printf("\n\x1b[33mОтсортированная матрица:\n\n");
            printarr_2(arr2, n, m);
            freee(n, arr2);
            printf("\n\x1b[31mХотите выбрать другое задание?\n\x1b[30;47m[1]\x1b[33;0m-Да\t\x1b[30;47m[0]\x1b[33;0m-Нет\n");
            check_imp(&retry);
        }
    }
    while (retry == 1);
}