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
            min = i; //������ ������������ ��������.
        }
    }

    int size_n = (*size) + 1;
    double* ptr_arr_n = (double*)malloc(size_n * sizeof(double));
    if (ptr_arr_n == NULL) {
        printf("������ ��������� ������.\n");
        return ptr_array;
    }

    for (int i = 0; i < min; i++) {
        ptr_arr_n[i] = ptr_array[i]; // �������� �������� �� ������������
    }
    ptr_arr_n[min + 1] = num; // ��������� ����� �����
    for (int i = min + 1; i < *size; i++) {
        ptr_arr_n[i + 1] = ptr_array[i]; // �������� ���������� ��������
    }

    free(ptr_array); // ����������� ������ ������� �������
    *size = size_n; // ��������� ������
    return ptr_arr_n; // ���������� ����� ������
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    char f;
    double* ptr_array;
    int size;

    printf("������� ������ ������� > ");
    scanf_s("%d", &size);

    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        printf("������ ��������� ������.\n");
        return 1; // ��������� ���������, ���� ������ �� ��������
    }
    printf("������� �������� ������.\n");

    while (1) {
        int a;
        do {
            printf("\n����.\n\t1. ��������� ���-�� �������.\n\t2. ������� �����.\n\t3. ����� �������\n\t0. �����\n");
            scanf_s("%d", &a);
            switch (a) {
            case 1:
                full_elements(ptr_array, size);
                printf("������ ������������.\n");
                break;
            case 2: {
                double num;
                printf("������� ����� ��� ������� > ");
                scanf_s("%lf", &num); // ������ ����� ���� double
                ptr_array = insert(ptr_array, &size, num); // ��������� ��������� �� ������
                printf("����� ���������.\n");
                break;
            }
            case 3:
                put_elements(ptr_array, size);
                break;
            case 0:
                free(ptr_array); // ����������� ������ ����� �������
                return 0; // ���������� ���������
            default:
                printf("\n����������� ������� ��������\n");
                break;
            }
        } while (a != 0);
        printf("����������? yes|no > ");
        scanf_s(" %c", &f);
        if (f == 'n') break;
    }

    free(ptr_array); // ����������� ������ ����� �����������
    return 0;
}