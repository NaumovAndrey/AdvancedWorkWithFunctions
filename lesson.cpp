#include "iostream"
#include <string>
#include "vector"

/**/
int power(int num, int deg = 2)
{
	int res = 1;
	for (size_t i = 0; i < deg; i++)
	{
		res *= num;
	}
	return res;
}

void foo(int i = 1, float j = 2.5, std::string text = "hello world")
{
	std::cout << i << " " << j << " " << text << std::endl;
}

void link()
{
	int i = 10;
	int& j = i;
	const int& k = i;

	j = 20;
	// k = 20; не скомпелируется, k - является константным значением
	std::cout << i << std::endl; //поменяли значение i по ссылке j
	std::cout << &i << " " << &j << " " << k << std::endl; //ссылка на один и тотже объект
}

/*функция */
void linkParam(int i)
{
	i += 10;
	std::cout << i << std::endl;
}

void linkParam2(int* i)
{
	*i += 10;
}

void linkParam3(int& i)
{
	i += 15;
}

void linkM()
{
	int i = 25;
	linkParam(i);
	std::cout << "передача не изменяемой переменной " << i << std::endl; // передали переменную которая может изменена в функции, но не в основном коде
	linkParam2(&i);
	std::cout << "передача ссылки " << i << std::endl; // передали ссылку которая может изменена в функции и в основном коде (поменяет значение по ссылке), для этого функция должна принимать ссылку { void linkParam2(int* i) }
	linkParam3(i);
	std::cout << "передача ссылки " << i << std::endl; // передача псевдонима, который также ссылается на од
}

void vector1(std::vector<int>& vec)
{
	std::cout << "второстепенная функция" << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
		vec[i] *= 2;
	}
	std::cout << std::endl;
}

void vector0()
{
	std::vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector1(a); // изменяем основной вектор по ссылке без указателя и копирования вектора
	std::cout << "основная функция" << std::endl;

	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

int fib(int n)
{
	if (n == 0 || n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}

void recursia()
{
	for (size_t i = 0; i < 20; i++)
	{
		std::cout << fib(i) << " ";
	}
	std::cout << std::endl;
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int gcd(int a, int b)
{
	if (b > a) swap(a, b);
	if (a % b == 0)  return b;
	return gcd(b, a % b);
}

void lesson()
{
	//std::cout << power(2, 3);
	//foo();
	//link();
	//linkM();
	//vector0();
	//recursia();
	std::cout << gcd(1320, 144);
}