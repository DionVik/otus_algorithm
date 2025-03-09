#include <iostream>

unsigned long long int count = 0;

int happy_count(int digits, int sum1, int sum2)
{
    if (digits == 0)
    {
        if (sum1 == sum2)
        {
            count++;
        }
        return 0;
    }
    for (int d1=0; d1<10; d1++)
        for (int d2=0; d2<10; d2++)
            happy_count(digits-1, sum1+d1, sum2+d2);
    return 0;
}

int main()
{
    int digits;
    std::cout << "Введите количество цифр = ";
    std::cin >> digits;
    int sum1 = 0;
    int sum2 = 0;
    happy_count(digits, sum1, sum2);
    std::cout << count << std::endl;
    return 0;
}


