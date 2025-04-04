// Уровень Junior. Сортировка методом выбора. 

#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int *p, int a, int b) {
    int temp = p[a];
    p[a] = p[b];
    p[b] = temp;
}

int select_sort(int *p, int arr_size) {
    for (int i = 0; i < arr_size - 1; i++) {
        int index_of_min = i;
        for (int j = i + 1; j < arr_size; j++) {
            if (p[j] < p[index_of_min]) {
                index_of_min = j;
            } 
        }
        swap(p, i, index_of_min);
    }
    return 0;
}

int main() {
    time_t start;
    time_t end;
    double duration;
    int arr_a[15];
   
    std::cout << "\nСортировка выбором\n";
    for (int i = 0; i < std::size(arr_a); i++) arr_a[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_a); i++) std::cout << arr_a[i] << " ";
    time(&start);
    select_sort(arr_a, std::size(arr_a));
    time(&end);
    duration = difftime(end, start);
    std::cout << std::endl;
    for (int i = 0; i < std::size(arr_a); i++) std::cout << arr_a[i] << " ";
    std::cout << std::endl;
    std::cout << "Массив из " << std::size(arr_a) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    return 0;
}
