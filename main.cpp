#include <iostream>
#include "long_class.h"
#include <string.h>
using namespace std;

int main(int argc, char* argv[])
{
	char *file1 = argv[1]; // укзательна на первый элемент массива аргументов
	char *file2 = argv[3];
	char *file3 = argv[4];
	char *file4 = NULL; // не обязательно наличие -b
	bool flag = 0;
	bool flag_mul = 0; 
	bool flag_sum = 0;
	bool flag_sub = 0;

	int bin = 0; //логич. переменная для бинарного файла

	if (argc == 6)
	{
		if (!strcmp(argv[5], "-b"))// если пятый аргумент равен -b, то работаем с бинарными файлами
			bin = 1;
		else
			file4 = argv[5];
	}

	if (argc == 7)
	{
		bin = 1;
		file4 = argv[6];
	}

	long_class A, B, mod;

	if (bin == 1)
	{
		A.read_bin_file_class(file1);
		B.read_bin_file_class(file2);
		if (file4 != NULL)
			mod.read_bin_file_class(file4);
	}
	else
	{
		A.read_file_class(file1);
		B.read_file_class(file2);
		if (file4 != NULL)
			mod.read_file_class(file4);
	}

	long_class c;
	if (argv[2][0] == '+')
	{
		flag_sum = 1;
		c = A + B;
	}

	if (argv[2][0] == '-')
	{
		flag_sub = 1;
		c = A - B;
	}

	if (argv[2][0] == '*')
	{
		flag_mul = 1;
		c = A * B;
	}

	if (argv[2][0] == '/')
	{
		flag = 1;
		c = A / B;
	}

	if (argv[2][0] == '%')
		c = A % B;

	if (file4 != NULL) // если задан файл с модулем, то результат любой операции нужно разделить по этому модулю
		c = c % mod;

	if (argv[2][0] == '^')
	{
		if (file4 == NULL)
			c = A ^ B;
		else
			c = involution_module_class(A, B, mod);
	}

	if (bin == 1)
		c.write_bin_file_class(file3, flag, flag_mul, flag_sum, flag_sub);
	else
		c.write_file_class(file3);

	return 0;
}