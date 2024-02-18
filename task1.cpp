#include "iostream"
#include "vector"

/*Напишите функцию swapvec, принимающую std::vector<int> и указатель на массив переменных типа int (одного размера) и обменивающую значения этих массивов.*/

void swapvec(std::vector<int>& vec, int* arr, int lenght)
{
	for (size_t i = 0; i < lenght; i++)
	{
		int temp = arr[i];
		arr[i] = vec[i];
		vec[i] = temp;
	}
}

void printArrVec(std::vector<int>& vec, int* arr)
{
	std::cout << "vector" << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	std::cout << std::endl;
	std::cout << "array" << std::endl;

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

void task1()
{
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	int arr[] = { 2, 4, 6, 8, 10, 6};

	if (vec.size() == (sizeof(arr) / sizeof(arr[0])))
	{
		std::cout << "До обмена" << std::endl;
		printArrVec(vec, arr);

		std::cout << "После обмена" << std::endl;
		swapvec(vec, arr, vec.size());
		printArrVec(vec, arr);
	} else
	{
		std::cout << "Длина не совподает" << std::endl;
	}
}