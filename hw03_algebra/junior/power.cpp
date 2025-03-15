// Итеративный O(N) алгоритм возведения числа number в степень power.
// Уровень Junior
#include <iostream>

double in_power(double number, int power)
{
    double result = 1;
	for (int i = 0; i < power; i++)
	{

		result = result * number;
	}
    return result;
}

int main()
{
    double number = 1.00001; // число
    int power = 100000;   // степень
    double result = in_power(number, power);
    std::cout << "Число " << number << " в степени " << power << " = "<< result << std::endl;
	return 0;
}
