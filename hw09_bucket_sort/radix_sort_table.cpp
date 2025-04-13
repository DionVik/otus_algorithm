// Поразрядная сортировка. Вывод в виде таблицы

#include <iostream>
#include <cstdlib>
#include <ctime>

void radix_sort(int *a, int arr_size) {
    const int base = 10; // основание с.с.
    const int digits_count = 3; // макс. кол-во цифр в числе
    int radix = 0; // номер разряда цифры
    int r = 1; // значение основания с.с. в степени radix
    int *c = new int[arr_size];
    for (int d = 0; d < digits_count; d++) {
        int *b = new int[base];
        for (int i = 0; i < base; i++) b[i] = 0;
        
        for (int i = 0; i < arr_size; i++) {
            int digit = (a[i] / r) % base;
            b[digit]++;
        }
        
        int sum = 0;
        int j = 0;
        while (j < base) {
            sum = sum + b[j];
            b[j] = sum;
            j++;
        }
        
        for (int i = arr_size - 1; i >= 0; i--) {
            int digit = (a[i] / r) % base;
            int index = b[digit] - 1;
            b[digit]= index;
            c[index] = a[i];
        }
        
        for (int i = 0; i < arr_size; i++) {
            a[i] = c[i];
        }
        r *= base;
        delete [] b;
    }
    delete [] c;
}

int main(){
    time_t start;
    time_t end;
    double duration;
    int arr_a[100];
    int arr_b[1000];
    int arr_c[10000];
    int arr_d[100000];
    int arr_e[1000000];
    
    std::cout << "\nПоразрядная сортировка\n";
    for (int i = 0; i < std::size(arr_a); i++) arr_a[i] = rand() % 1000;
    for (int i = 0; i < std::size(arr_b); i++) arr_b[i] = rand() % 1000;
    for (int i = 0; i < std::size(arr_c); i++) arr_c[i] = rand() % 1000;
    for (int i = 0; i < std::size(arr_d); i++) arr_d[i] = rand() % 1000;
    for (int i = 0; i < std::size(arr_e); i++) arr_e[i] = rand() % 1000;
    // массив из 100
    time(&start);
    radix_sort(arr_a, std::size(arr_a));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_a) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 1000
    time(&start);
    radix_sort(arr_b, std::size(arr_b));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_b) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 10000
    time(&start);
    radix_sort(arr_c, std::size(arr_c));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_c) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 100000
    time(&start);
    radix_sort(arr_d, std::size(arr_d));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_d) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 1000000
    time(&start);
    radix_sort(arr_e, std::size(arr_e));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_e) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    return 0;
}
