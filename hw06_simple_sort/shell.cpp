// Уровень Junior. Сортировка Шелла. 

#include <iostream>
#include <cstdlib>
#include <ctime>

int shell(int *p, int arr_size) {
    int chg = 0; // кол-во обменов
    for (int gap = (arr_size / 2); gap >= 1; gap /= 2){
        for (int j = gap; j < arr_size; j++) {
            for (int i = j; i >= gap; i -= gap) {
                if (p[i - gap] < p[i]) break;
                chg++;
                int temp = p[i];
                p[i] = p[i - gap];
                p[i - gap] = temp;
            }
        }
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
   
    std::cout << "\nСортировка Шелла\n";
    for (int i = 0; i < std::size(arr_a); i++) arr_a[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_b); i++) arr_b[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_c); i++) arr_c[i] = rand() % 101;
    
    time(&start);
    changes = shell(arr_a, std::size(arr_a));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_a) << " элементов. ";
    std::cout << "Обменов: " << changes;
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    time(&start);
    changes = shell(arr_b, std::size(arr_b));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_b) << " элементов. ";
    std::cout << "Обменов: " << changes;
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    time(&start);
    changes = shell(arr_c, std::size(arr_c));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_c) << " элементов. ";
    std::cout << "Обменов: " << changes;
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    return 0;
}
