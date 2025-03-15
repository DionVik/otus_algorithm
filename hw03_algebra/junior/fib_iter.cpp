// Итеративный алгоритм поиска значения n-ого числа Фибоначчи. 
// Уровень Junior.
#include <iostream>

unsigned long long fib_iter(int n)
{
    if (n <= 1)
        return n;
    unsigned long long fib0 = 0;
    unsigned long long fib1 = 1;
    unsigned long long fib2 = 0;
    for (int i = 2; i <= n; i++)
    {
        fib2 = fib1 + fib0;
        fib0 = fib1;
        fib1 = fib2;
    }
    return fib2;
}

int main()
{
    int num = 15; // порядковый номер числа Фибоначчи
    for (int i = 0; i <= num; i++)
    {
        unsigned long long result = fib_iter(i);
        std::cout << "Число Фибоначчи " << i << " = "<< result << std::endl;
    }
    return 0;
}
