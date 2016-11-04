#include <stdio.h>
#include <iostream>

int main()
{
	char* filePath = "tekst.txt";
	int const bufSize = 1;
	FILE* file = fopen(filePath, "r+t"); 
	if (file == nullptr)
	{
		std::cout << "can't open file: " << filePath << std::endl;
		return 1;
	}

	char* buffer = new char[bufSize];
	int objCount = 0;
	do
	{
		memset(buffer, 0, bufSize);
		objCount = fread(buffer, 1, 1, file);
		int temp = (int)buffer;
		std::cout << buffer << " = ";
		buffer[0] += '3';
		std::cout << buffer << "; ";
		fwrite(buffer, 1, 1, file);
	} while (objCount > 0);

	std::cout << std::endl;

	fflush(file);
	int closeResult = fclose(file);	// flush
	if (closeResult == 0)
	{
		file = nullptr;
	}

	delete[] buffer;

}




/*Дан текстовыи? фаи?л. Зашифровать его, используя шифр Цезаря. Результат записать в другои? фаи?л.
Шифр Цезаря — один из древнеи?ших шифров. При шифровании каждыи? символ заменяется другим, отстоящим от него в алфавите на фиксированное число позиции?. 
Пример
Шифрование с использованием ключа: 3  
Оригинальныи? текст: Съешь же еще? этих мягких французских булок, да выпеи? чаю.
Шифрованныи? текст: Фэзыя и?з зьи ахлш пве?нлш чугрщцкфнлш дцосн, жг еютзм ъгб. */