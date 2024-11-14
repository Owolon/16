#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define XMAX 1
#define XMIN -1

double* full_elements(double* ptr_array, int size)
{
	double* temp_ptr = ptr_array;
	for (int i = 0; i < size; i++)
	{
		*temp_ptr = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
		temp_ptr++;
	}
	return temp_ptr;
}
double* put_elements(double* ptr_array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%.1lf\n", *ptr_array);
		ptr_array++;
	}
	return 0;
}
double* calc_elements(double* ptr_array, int size)
{
	for (int i = 0; i < size; i++)
	{
		*ptr_array = (int)*ptr_array;
		ptr_array++;
	}
	return ptr_array;
}

int delete_k(double* ptr_array, int size, int k, double h)
{

	int n = size - 1;
	for (int i = 0; i < (size - 1); i++)
	{
		if (1)
		{
			ptr_array[i] = ptr_array[i + 1];
		}
	}
	return n;
}

void main()
{
	setlocale(LC_CTYPE, "RUS");
	char f;
	double* ptr_array;
	int size;
	printf("Введите размер массива > ");
	scanf_s("%d", &size);

	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL)
	{
		printf("Ошибка выделения памяти.");
	}
	else
	{
		printf("Успешно");
	}
	while (1)
	{
		int a;

		do {
			printf("\nМеню.\n\t1.Генерация дин-го массива.\n\t2.Вывод зна-ий массива.\n\t3.Удаление эл-ов превыщающих заданое зна-е.\n\t4.Отбрасывание дроб-ой части.\n\t0.Выход\n");
			scanf_s("%d", &a);
			switch (a)
			{
			case 1:
			{
				full_elements(ptr_array, size);
				printf("Массив сгенерирован.");
				break;
			}
			case 2:
			{
				put_elements(ptr_array, size);
				break;
			}
			case 3:
			{
				int k;
				double h;
				printf("Введите индекс элемента > ");
				scanf_s("%d", &k);
				printf("Введите значение > ");
				scanf_s("%lf", &h);
				delete_k(ptr_array, size, k, h);
				printf("Элемент удален.");
				break;
			}
			case 4:
			{
				calc_elements(ptr_array, size);
				printf("Дробная часть отброшена.");
				break;
			}
			case 0:
			{
				break;
			}
			default:
				printf("\nНе правильно введено зна-е");
				break;
			}
		} while (a != 0);
		printf("Продолжить? yes|no > ");
		scanf_s("% c", &f, sizeof(f));
		if (f == 'n') break;
	}
}