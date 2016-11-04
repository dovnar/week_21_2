#include <stdio.h>
#include <iostream>

int main()
{
	char* filePath1 = "filePath1.txt";
	char* filePath2 = "filePath2.txt";
	int const bufSize = 120;
	FILE* file1 = fopen(filePath1, "rb+"); 
	FILE* file2 = fopen(filePath2, "rb+");
	if (file1 == nullptr)
	{
		std::cout << "can't open file 1: " << filePath1 << std::endl;
		return 1;
	}
	if (file2 == nullptr)
	{
		std::cout << "can't open file 2: " << filePath2 << std::endl;
		return 1;
	}
	fseek(file1, bufSize, SEEK_END);
	int sizeFile = ftell(file1);
	char* buffer1 = new char[bufSize];
	char* buffer2 = new char[bufSize];

	int objCount = 0;
	fseek(file1, 0, SEEK_SET);
	do
	{
		memset(buffer1, 0, bufSize);
		memset(buffer2, 0, bufSize);
		objCount = fread(buffer2, bufSize, 1, file2);
		objCount = fread(buffer1, bufSize, 1, file1);
		if (strstr(buffer1, buffer2) == 0)
		{
			std::cout << "file 1: " << buffer1 << std::endl << std::endl << "file 2: " << buffer2 << std::endl << std::endl;
		}
	} while (objCount > 0);


	fflush(file1);
	int closeResult = fclose(file1);	// flush
	if (closeResult == 0)
	{
		file1 = nullptr;
	}
	fflush(file2);
	closeResult = fclose(file2);	// flush
	if (closeResult == 0)
	{
		file2 = nullptr;
	}
	delete[] buffer1;
	delete[] buffer2;
}



/*Дано два текстовых фаила.? Выяснить, совпадают ли их строки. Если нет, то вывести несовпадающую строку из каждого фаи?ла.*/