// Поиск значения n-ого числа Фибоначчи по ф-ле золотого сечения.
// Уровень Middle.
#include <iostream>
#include <ctime>
#include <cmath>

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
        power2 = power - 1;
        x = in_power(number, power2 / 2);
        result = number * x * x;
    }
    return result;
}

long double fib_golden(unsigned int n)
{
    double fi = (1 + sqrt(5)) / 2;
    long double powered_fi = in_power(fi, n);
    long double fib = powered_fi / sqrt(5) + 1 / 2;
    return fib;
}


int main()
{
    unsigned int n = 20; // порядковый номер числа Фибоначчи
    for (unsigned int i = 1; i <= n; i++)
    { 
        time_t start;
        time(&start);
        long double result = fib_golden(i);
        time_t end;
        time(&end);
        double duration = difftime(end, start);
        std::cout << "Число Фибоначчи " << i << " = "<< result;
        std::cout << " Длительность " << duration << std::endl;
    }
    return 0;
}
