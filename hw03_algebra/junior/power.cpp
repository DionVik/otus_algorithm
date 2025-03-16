// Итеративный O(N) алгоритм возведения числа number в степень power.
// Уровень Junior

#include <iostream>
#include <ctime>

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
    long double number = 1.001; // число
    int power = 1000;   // степень
    long double result = 0;
    for (int i = 10; i <= power; i*=10)
    {
        time_t start;
        time(&start);
        result = in_power(number, i);
        time_t end;
        time(&end);
        double duration = difftime(end, start);
        std::cout << "Число " << number << " в степени " << i <<" = "<< result << " длительность = " << duration << std::endl;
    }
    return 0;
}
