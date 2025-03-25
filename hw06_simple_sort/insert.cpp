// Уровень Junior. Сортировка вставками. 

#include <iostream>
#include <cstdlib>
#include <ctime>

int insert(int *p, int arr_size) {
    int chg = 0; // кол-во обменов
    for (int i = 1; i < arr_size; i++) {
        int index = i - 1;
        while (index >= 0) {
            if (p[index] <= p[i]) break;
            chg++;
            int temp = p[i];
            p[i] = p[index];
            p[index] = temp;
            i--;
            index--;
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
   
    std::cout << "\nСортировка вставками\n";
    for (int i = 0; i < std::size(arr_a); i++) arr_a[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_b); i++) arr_b[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_c); i++) arr_c[i] = rand() % 101;
    
    time(&start);
    changes = insert(arr_a, std::size(arr_a));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_a) << " элементов. ";
    std::cout << "Обменов: " << changes;
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    time(&start);
    changes = insert(arr_b, std::size(arr_b));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_b) << " элементов. ";
    std::cout << "Обменов: " << changes;
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    time(&start);
    changes = insert(arr_c, std::size(arr_c));
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_c) << " элементов. ";
    std::cout << "Обменов: " << changes;
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    return 0;
}
