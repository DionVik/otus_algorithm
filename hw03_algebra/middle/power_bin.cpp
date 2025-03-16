// Итерационный бинарный алгоритм возведения в степень
// Уровень Middle

#include <iostream>
#include <ctime>

long double bin_power(double number, unsigned int power)
{
    long double result = 1; // результат
    double a = number; // начальное основание степени 
    unsigned int x = power;  // представление показателя степени
    while (x != 0)
    {
        if (x & 1) // если правая цифра двоичного представления = 1
            result = result * a;
        a = a * a;
        x >>= 1;  // уменьшаем показатель степени
    }
    return result;
}

int main()
{
    double number = 4; // число
    unsigned int power = 20;   // степень
    long double result = 0;
    for (unsigned int i = 1; i <= power; i++)
    {
        time_t start;
        time(&start);
        result = bin_power(number, i);
        time_t end;
        time(&end);
        double duration = difftime(end, start);
        std::cout << "Число " << number << " в степени " << i <<" = "<< result << " длительность = " << duration << std::endl;
    }
	return 0;
}
