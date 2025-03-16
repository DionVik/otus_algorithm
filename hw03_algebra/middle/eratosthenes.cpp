// Алгоритм "Решето Эратосфена" - нахождение кол-ва простых чисел.
// Уровень Middle

#include <iostream>
#include <ctime>

unsigned long long eratosthenes(unsigned long number)
{
    bool no_prime[number + 1];
    unsigned long long count = 0;
    
    for (int i=0; i<(sizeof no_prime / sizeof no_prime[0]); i++)
        no_prime[i] = false;
            
    for (int j=2; j <= number; j++)
    {
        if (!no_prime[j])
        {   
            count++;
            for (int k = j * j; k <= number; k+=j)
            {
                no_prime[k] = true;
            }
        }
    }
    return count;
}

int main()
{
    unsigned long number = 1000000; // число
    unsigned long long result = 0;
    for (int i = 100; i <= number; i*=10)
    {
        time_t start;
        time(&start);
        result = eratosthenes(i);
        time_t end;
        time(&end);
        double duration = difftime(end, start);
        std::cout << "Для числа " << i << " простых " << result;
        std::cout << " длительность = " << duration << std::endl;
    }
	return 0;
}
