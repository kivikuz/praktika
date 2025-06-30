#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <limits.h>

int InputArray();
void selectionSort(int a[], int size);
void Generator(int a[], int size1);
void ResultWrite(int a[], int size1);

int main() {
    int* a, size;
    srand(time(0));
    setlocale(LC_ALL, "Rus");

    size = InputArray();
    a = (int*)malloc(size * sizeof(int));

    Generator(a, size);

    clock_t start = clock();
    selectionSort(a, size);
    clock_t stop = clock();

    ResultWrite(a, size);

    printf("Время выполнения алгоритма: %.3f секунд\n", ((double)(stop - start)) / CLOCKS_PER_SEC);
    free(a);
    return 0;
}

int InputArray() {
    int input;
    while (1) {
        printf("Введите размер массива: ");

        if (scanf("%d", &input) != 1) {
            // Очистка буфера ввода при ошибке
            while (getchar() != '\n');
            printf("Ошибка: введено не число. Пожалуйста, введите целое число.\n");
            continue;
        }

        if (input < 2) {
            printf("Ошибка: значение должно быть не меньше 2.\n");
        }
        else {
            break;
        }
    }
    return input;
}