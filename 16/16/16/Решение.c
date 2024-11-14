#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define XMAX 100
#define XMIN -100

double* full_elements(double* ptr_array, int size)
{
	double* temp_ptr = ptr_array;
	for (int i = 0; i < size; i++)
	{
		*temp_ptr = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
		temp_ptr++;
	}
	ptr_array=temp_ptr;
	return ptr_array;
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
double* put(double* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%.1lf\n", *array);
		array++;
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

double* delete(double* ptr_array, double* array, int size,  double nach)
{
	for (int i = 0; i < size; i++)
	{
		if (*ptr_array < nach)
		{
			*array = *ptr_array;
			array++;
		}
		else
		{
			*array = 0.;
			array++;
		}
		ptr_array++;
	}
	return array;
}
int* insert(int* ptr_array, int* size, int num)
{
	int min = 0;
	for (int i = 0; i < *size; i++)
	{
		if (min < *ptr_array)
		{
			min = i;//Индекс минимального значения.
		}
	}
	int size_n = (*size) + 1;
	if (ptr_array == NULL)
		printf("Ошибка выделения памяти.");
		return NULL;
	int* ptr_arr_n = (int*)malloc(size_n * sizeof(int));
	if (ptr_arr_n == NULL)
		return ptr_array;
	ptr_array = ptr_arr_n;
	for (int i = size_n - 1; i > min; i--)//Увеличение массива
		ptr_arr_n[i] = ptr_arr_n[i - 1];
	ptr_arr_n[min+1] = num;
	*size = size_n;
	return ptr_arr_n;
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
		printf("\nУспешно");
	}


	while (1)
	{
		int a;

		do {
			printf("\nМеню.\n\t1.Генерация дин-го массива.\n\t2.Вывод зна-ий массива.\n\t3.Удаление эл-та.\n\t4.Удаление эл-ов превыщающих заданое зна-е\n\t5.Отбрасывание дроб-ой части.\n\t6.Вставка числа.\n\t0.Выход\n");
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
				delete(ptr_array, array, size, nach);
				put(array, size);
				ptr_array = array;
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
				int num;
				printf("Введите число для вставки > ");
				scanf_s("%d", &num);
				insert(ptr_array, size, num);
				put(ptr_array, size);
				printf("Число добавлено.");
				break;
			}
			case 0:
			{
				free(ptr_array);
				free(array);
				printf("Память освобождена.");
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