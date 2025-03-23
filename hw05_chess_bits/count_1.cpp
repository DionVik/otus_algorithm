// Уровень Junior. 
// Нахождение кол-ва 1 в числе

#include <iostream>

unsigned int count_1(unsigned long long number) {
    unsigned long long mask = number & 0xFFFFFFFF;
    unsigned int count = 0;
    while (mask != 0) {
        if (mask & 0x1) { 
            count++;
        }
        mask = mask >> 1;
    }
    return count;
} 


int main() {
    std::cout << "Введите целое положительное число: "; 
    char str [3];
    std::cin >> str;
    unsigned long long number = std::stoi(str);
    unsigned int result = count_1(number);
    
    std::cout << "\n Количество 1 =  " << result << std::endl;
    return 0;
}
