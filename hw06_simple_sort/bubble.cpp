// Уровень Junior. Сортировка методом пузырька. 

#include <iostream>
#include <cstdlib>
#include <ctime>

int bubble(int *p, int arr_size) {
    int chg = 0; // кол-во обменов
    for (int i = 0; i < arr_size; i++) {
        bool not_swap = true;
        for (int j = arr_size - 1; j > i; j--) {
            if (p[j] < p[j-1]) {
                chg++;
                int temp = p[j];
                p[j] = p[j-1];
                p[j-1] = temp;
                not_swap = false;
            }
        }
        if (not_swap == true) break;
    }
    return chg;
}

int main() {
    time_t start;
    time_t end;
    double duration;
    int arr_a[100];
    int arr_b[1000];
    int arr_c[10000];
    int changes;
   
    std::cout << "\nСортировка пузырьком\n";
    for (int i = 0; i < std::size(arr_a); i++) arr_a[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_b); i++) arr_b[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_c); i++) arr_c[i] = rand() % 101;
    
    time(&start);
    changes = bubble(arr_a, std::size(arr_a));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_a) << " элементов. ";
    std::cout << "Обменов: " << changes;
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    time(&start);
    changes = bubble(arr_b, std::size(arr_b));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_b) << " элементов. ";
    std::cout << "Обменов: " << changes;
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    time(&start);
    changes = bubble(arr_c, std::size(arr_c));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_c) << " элементов. ";
    std::cout << "Обменов: " << changes;
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    return 0;
}
