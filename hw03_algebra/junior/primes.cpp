// Находим кол-во простых чисел методом перебора делителей 
// в диапазоне от 0 до n включительно. Уровень Junior.
#include <iostream>
#include <ctime>
#include <cmath>

bool is_prime(unsigned long long p)
// Перебираем все делители
{
    for (unsigned long long d = 2; d < p; d++)
    {
        if ((p % d) == 0)
            return false;
    }
    return true;
}

bool is_prime2(unsigned long long p)
// Перебираем все делители с проверкой на чётность 
{
    if ((p % 2) == 0)
            return false;
    for (unsigned long long d = 2; d < p; d++)
    {
        if ((p % d) == 0)
            return false;
    }
    return true;
}

bool is_prime3(unsigned long long p)
// Перебираем только нечётные делители с проверкой на чётность
{
    if ((p % 2) == 0)
            return false;
    for (unsigned long long d = 3; d < p; d += 2)
    {
        if ((p % d) == 0)
            return false;
    }
    return true;
}

bool is_prime4(unsigned long long p)
// Перебираем только нечётные делители с проверкой на чётность до p/2
{
    if ((p % 2) == 0)
            return false;
    for (unsigned long long d = 3; d < p/2; d += 2)
    {
        if ((p % d) == 0)
            return false;
    }
    return true;
}

bool is_prime5(unsigned long long p)
// Перебираем только нечётные делители с проверкой на чётность до sqrt(2)
{
    int sqrt_p = sqrt(p);
    if ((p % 2) == 0)
            return false;
    for (unsigned long long d = 3; d <= sqrt_p; d += 2)
    {
        if ((p % d) == 0)
            return false;
    }
    return true;
}

unsigned long long count_primes(unsigned long long n)
{
    unsigned long long counter = 0;
    for (unsigned long long i = 1; i <= n; i++)
    {
        if (is_prime5(i))  // функция имеет несколько вариантов
            counter += 1;
    }
    return counter;
}

int main()
{
    unsigned int n = 1000000;
    for (unsigned long long i = 1000; i <= n; i *= 10)
    { 
        time_t start;
        time(&start);
        unsigned long long result = count_primes(i);
        time_t end;
        time(&end);
        double duration = difftime(end, start);
        std::cout << i << " " << result << " " << duration  << " сек." << std::endl;
    }
    return 0;
}
