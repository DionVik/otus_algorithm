// Рекурсивный алгоритм поиска значения n-ого числа Фибоначчи. Уровень Junior.
#include <iostream>

unsigned long long fib_recurs(int n)
{
    unsigned long long result = 0;
    if (n <= 1)
        return n;
    else
        result = fib_recurs(n-1) + fib_recurs(n-2);
    return result;
}

int main()
{
    int num = 15; // порядковый номер числа Фибоначчи
    for (int i = 0; i <= num; i++)
    {
        unsigned long long result = fib_recurs(i);
        std::cout << "Число Фибоначчи " << i << " = "<< result << std::endl;
    }
    return 0;
}
