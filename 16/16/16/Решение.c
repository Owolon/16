#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define XMAX 10
#define XMIN -10

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

int delete_k(double* ptr_array, int size, int k)
{

	int n = size - 1;
	for (int i = k; i < (size - 1); i++)
	{
		ptr_array[i] = ptr_array[i + 1];
	}
	return n;
}
int delete(double* ptr_array, int size, double nach)
{
	int n = size - 1;
	for (int i = 0; i < (size - 1); i++)
	{
		if (*ptr_array >= nach)
		{
			ptr_array[i] = ptr_array[i + 1];
		}
	}
	return n;
}
int* insert(int* ptr_array, int* size, int index, int num)
{
	int size_n = (*size) + 1;
	if (ptr_array == NULL) 
		return NULL;
	int* ptr_arr_n = (int*)realloc(ptr_array, size_n * sizeof(int));
	if ((ptr_arr_n) == NULL) 
		return ptr_array;
	ptr_array = ptr_arr_n;
	for (int i = size_n - 1; i > index; i--)
		ptr_array[i] = ptr_array[i - 1];
	ptr_array[index] = num;
	*size = size_n;
	return ptr_array;
}
void main()
{
	setlocale(LC_CTYPE, "RUS");
	char f;
	double* ptr_array;
	double* array;
	int size;
	printf("Введите размер массива > ");
	scanf_s("%d", &size);

	ptr_array = (double*)malloc(size * sizeof(double)); //Новая область памяти массив
	if (ptr_array == NULL)
	{
		printf("Ошибка выделения памяти.");
	}
	else
	{
		printf("Успешно");
	}
	array = (double*)malloc(size * sizeof(double)); //Новая область памяти массив
	if (array == NULL)
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
			printf("\nМеню.\n\t1.Генерация дин-го массива.\n\t2.Вывод зна-ий массива.\n\t3.Удаление эл-та.\n\t4.Удаление эл-ов превыщающих заданое зна-е\n\t5.Отбрасывание дроб-ой части.\n\t6.Вставка зна-я\n\t0.Выход\n");
			scanf_s("%d", &a);
			switch (a)
			{
				double h;
				printf("Введите значение > ");
				scanf_s("%lf", &h);
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
				printf("Введите индекс удаляемого элемента > ");
				scanf_s("%d", &k);
				delete_k(ptr_array, size, k);
				printf("Элемент удален.");
				break;
			}
			case 4:
			{
				double nach;
				printf("Введите число (удаляться будут большие знач-я) > ");
				scanf_s("%lf", &nach);
				delete(ptr_array, size, nach);
				printf("Элементы удалены.");
				break;
			}
			case 5:
			{
				calc_elements(ptr_array, size);
				printf("Дробная часть отброшена.");
				break;
			}
			case 6:
			{
				int index;
				int num;
				insert(ptr_array, size, index, num);
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