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
	printf("������� ������ ������� > ");
	scanf_s("%d", &size);

	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL)
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
			printf("\n����.\n\t1.��������� ���-�� �������.\n\t2.����� ���-�� �������.\n\t3.�������� ��-�� ����������� ������� ���-�.\n\t4.������������ ����-�� �����.\n\t0.�����\n");
			scanf_s("%d", &a);
			switch (a)
			{
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
				double h;
				printf("������� ������ �������� > ");
				scanf_s("%d", &k);
				printf("������� �������� > ");
				scanf_s("%lf", &h);
				delete_k(ptr_array, size, k, h);
				printf("������� ������.");
				break;
			}
			case 4:
			{
				calc_elements(ptr_array, size);
				printf("������� ����� ���������.");
				break;
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