// Уровень Junior. 
// Нахождение кол-ва 1 в числе через алгоритм Кернигана

#include <iostream>

unsigned int kernigan(unsigned long long number) {
    unsigned long long mask = number & 0xFFFFFFFF;
    unsigned int count = 0;
    unsigned long long temp = 0;
    while (mask != 0) {
        count++;
        temp = mask - 1;
        mask = mask & temp;
    }
    return count;
} 


int main() {
    std::cout << "Введите целое положительное число: "; 
    char str [3];
    std::cin >> str;
    unsigned long long number = std::stoi(str);
    unsigned int result = kernigan(number);
    
    std::cout << "\n Количество 1: " << result << std::endl;
    return 0;
}
