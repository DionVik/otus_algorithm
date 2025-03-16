// Рекурсивный алгоритм возведения числа number в степень 
//power с разбиением на множители.
// Уровень Middle

#include <iostream>
#include <ctime>

long double in_power(double number, int power)
{
    double result = 0;
    long double x = 0;
    int power2 = 0;
    
    if (power==0)
        return 1;
    if (power == 1)
        return number;
    if ((power % 2) == 0)
    {
        x = in_power(number, power / 2);
        result = x * x;
    }
    else
    {
        // power2 = power - 1;
        // x = in_power(number, power2 / 2);
        // result = number * x * x;
        result = number * in_power(number, power - 1);
    }
    return result;
}

int main()
{
    long double number = 2; // число
    int power = 10;   // степень
    long double result = 0;
    for (int i = 1; i <= power; i++)
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
