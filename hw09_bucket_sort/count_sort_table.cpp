// Сортировка подсчётом. Вывод в виде таблицы

#include <iostream>
#include <cstdlib>
#include <ctime>

int get_max(int *p, int arr_size) {
    int max = p[0];
    for (int i = 1; i < arr_size; i++) {
        if (p[i] > max) max = p[i];
    }
    return max;
}


void count_sort(int *a, int arr_size) {
    int max = get_max(a, arr_size);
    int *b = new int[max + 1];
    int *c = new int[arr_size];
    
    for (int i = 0; i < arr_size; i++) {
        int value = a[i];
        b[value]++;
    }
    
    int sum = 0;
    int j = 0;
    while (j <= max) {
    // for (int j = 0; j <= max; j++) {
        sum = sum + b[j];
        b[j] = sum;
        j++;
    }
    
    for (int i = arr_size - 1; i >= 0; i--) {
        int value = a[i];
        int index = b[value] - 1;
        b[value]= index;
        c[index] = value;
    }
    
    for (int i = 0; i < arr_size; i++) {
        a[i] = c[i];
    }
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
    
    std::cout << "\nСортировка подсчётом\n";
    for (int i = 0; i < std::size(arr_a); i++) arr_a[i] = rand() % 1000;
    for (int i = 0; i < std::size(arr_b); i++) arr_b[i] = rand() % 1000;
    for (int i = 0; i < std::size(arr_c); i++) arr_c[i] = rand() % 1000;
    for (int i = 0; i < std::size(arr_d); i++) arr_d[i] = rand() % 1000;
    for (int i = 0; i < std::size(arr_e); i++) arr_e[i] = rand() % 1000;
    // массив из 100
    time(&start);
    count_sort(arr_a, std::size(arr_a));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_a) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 1000
    time(&start);
    count_sort(arr_b, std::size(arr_b));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_b) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 10000
    time(&start);
    count_sort(arr_c, std::size(arr_c));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_c) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 100000
    time(&start);
    count_sort(arr_d, std::size(arr_d));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_d) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 1000000
    time(&start);
    count_sort(arr_e, std::size(arr_e));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_e) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    return 0;
}
