#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
double* full_elements(double* ptr_array, int size, int x)
{
	double* temp_ptr = ptr_array;
	for (int i = 0; i < size; i++)
	{
		*temp_ptr += abs(exp(1) - 2) - pow(x + 0.1, 2);
		temp_ptr++;
	}
	return temp_ptr;
}
int put_elements(double* ptr_array, int size)//������� �����
{
	for (int i = 0; i < size; i++)
	{
		printf("\n������� ������ �������� %.2lf", *ptr_array);
		ptr_array++;
	}
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

int delete_k(double* ptr_arr, int size, int k) {

	/* ptr_arr - ����� �������

	   size - ����� ���������

	   k - ������ ���������� ��������  */

	int n = size - 1;

	for (int i = k; i < (size - 1); i++) ptr_arr[i] = ptr_arr[i + 1];

	return n;//���������� ����� ��������� �������

}

void main()
{
	setlocale(LC_CTYPE, "RUS");
	double *ptr_array;
	int size, x;

	printf("������� ������ ������� > ");
	scanf_s("%d", &size);
	printf("������� �������� � ��� ���������� ������� >");
	scanf_s("%d", &x);
	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL)
	{
		printf("������ ������� �����.");
		return -1;
	}
	full_elements(ptr_array,size,x);
	calc_elements(ptr_array, size);
	put_elements(ptr_array, size);
	free(ptr_array);

}