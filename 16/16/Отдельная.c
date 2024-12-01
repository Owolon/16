#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define XMAX 1
#define XMIN -1

double* full_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = XMIN + (double)(rand()) / RAND_MAX * (XMAX - XMIN);
    }
    return ptr_array;
}

void put_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.1lf\n", ptr_array[i]);
    }
}

double* insert(double* ptr_array, int* size, double num) {
    int min = 0;
    for (int i = 1; i < *size; i++) {
        if (ptr_array[i] < ptr_array[min]) {
            min = i; //Индекс минимального значения.
        }
    }

    int size_n = (*size) + 1;
    double* ptr_arr_n = (double*)malloc(size_n * sizeof(double));
    if (ptr_arr_n == NULL) {
        printf("Ошибка выделения памяти.\n");
        return ptr_array;
    }

    for (int i = 0; i < min; i++) {
        ptr_arr_n[i] = ptr_array[i]; // Копируем элементы до минимального
    }
    ptr_arr_n[min + 1] = num; // Вставляем новое число
    for (int i = min + 1; i < *size; i++) {
        ptr_arr_n[i + 1] = ptr_array[i]; // Копируем оставшиеся элементы
    }

    free(ptr_array); // Освобождаем память старого массива
    *size = size_n; // Обновляем размер
    return ptr_arr_n; // Возвращаем новый массив
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    char f;
    double* ptr_array;
    int size;

    printf("Введите размер массива > ");
    scanf_s("%d", &size);

    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1; // Завершаем программу, если память не выделена
    }
    printf("Успешно выделена память.\n");

    while (1) {
        int a;
        do {
            printf("\nМеню.\n\t1. Генерация дин-го массива.\n\t2. Вставка числа.\n\t3. Вывод массива\n\t0. Выход\n");
            scanf_s("%d", &a);
            switch (a) {
            case 1:
                full_elements(ptr_array, size);
                printf("Массив сгенерирован.\n");
                break;
            case 2: {
                double num;
                printf("Введите число для вставки > ");
                scanf_s("%lf", &num); // Читаем число типа double
                ptr_array = insert(ptr_array, &size, num); // Обновляем указатель на массив
                printf("Число добавлено.\n");
                break;
            }
            case 3:
                put_elements(ptr_array, size);
                break;
            case 0:
                free(ptr_array); // Освобождаем память перед выходом
                return 0; // Завершение программы
            default:
                printf("\nНеправильно введено значение\n");
                break;
            }
        } while (a != 0);
        printf("Продолжить? yes|no > ");
        scanf_s(" %c", &f);
        if (f == 'n') break;
    }

    free(ptr_array); // Освобождаем память перед завершением
    return 0;
}