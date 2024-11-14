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
	printf("������� ������ ������� > ");
	scanf_s("%d", &size);

	ptr_array = (double*)malloc(size * sizeof(double)); //����� ������� ������ ������
	if (ptr_array == NULL)
	{
		printf("������ ��������� ������.");
	}
	else
	{
		printf("�������");
	}
	array = (double*)malloc(size * sizeof(double)); //����� ������� ������ ������
	if (array == NULL)
	{
		printf("������ ��������� ������.");
	}
	else
	{
		printf("�������");
	}
	while (1)
	{
		int a;

		do {
			printf("\n����.\n\t1.��������� ���-�� �������.\n\t2.����� ���-�� �������.\n\t3.�������� ��-��.\n\t4.�������� ��-�� ����������� ������� ���-�\n\t5.������������ ����-�� �����.\n\t6.������� ���-�\n\t0.�����\n");
			scanf_s("%d", &a);
			switch (a)
			{
				double h;
				printf("������� �������� > ");
				scanf_s("%lf", &h);
			case 1:
			{
				full_elements(ptr_array, size);
				printf("������ ������������.");
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
				printf("������� ������ ���������� �������� > ");
				scanf_s("%d", &k);
				delete_k(ptr_array, size, k);
				printf("������� ������.");
				break;
			}
			case 4:
			{
				double nach;
				printf("������� ����� (��������� ����� ������� ����-�) > ");
				scanf_s("%lf", &nach);
				delete(ptr_array, size, nach);
				printf("�������� �������.");
				break;
			}
			case 5:
			{
				calc_elements(ptr_array, size);
				printf("������� ����� ���������.");
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
				printf("\n�� ��������� ������� ���-�");
				break;
			}
		} while (a != 0);
		printf("����������? yes|no > ");
		scanf_s("% c", &f, sizeof(f));
		if (f == 'n') break;
	}
}