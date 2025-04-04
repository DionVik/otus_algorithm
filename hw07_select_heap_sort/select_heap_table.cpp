// Уровень Middle. Сравнительная таблица сортировок выбором и кучей. 

#include <iostream>
#include <cstdlib>
#include <ctime>

int get_max(int *p, int a, int b) {
    return (p[a] > p[b]) ? a : b;
}

void swap(int *p, int a, int b) {
    int temp = p[a];
    p[a] = p[b];
    p[b] = temp;
}

// Сортировка выбором ---------------------------------------------
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

// сортировка кучей----------------------------------------------------
void order_tree(int *p, int arr_size, int root) {
    int max_value_index;
    int i = root;
    bool is_placed = false;
    while (i < arr_size && is_placed != true) {
        int left = 2 * i + 1;
        if (left > (arr_size - 1)) break;
        if (left == (arr_size - 1)) max_value_index = left;
        else {
            int right = 2 * i + 2;
            max_value_index = get_max(p, left, right);
        }
        if (p[i] < p[max_value_index]) {
            swap(p, i, max_value_index);
            i = max_value_index;
        }
        else {
            is_placed = true;
        }
    }
}

void heap_sort(int *p, int arr_size) {
    int n = arr_size;
    for (int i = (n / 2)-1; i >= 0; i--) order_tree(p, n, i);
    while (n > 0 ) {
        swap(p, 0, n - 1);
        order_tree(p, n - 1, 0);
        n--;
    }
}
//---------------------------------------------------------------------
int main() {
    time_t start;
    time_t end;
    double duration;
    int arr_a[100];
    int arr_b[1000];
    int arr_c[10000];
    int arr_d[100000];
    int arr_e[1000000];
    
    std::cout << "\nСравнительная таблица\n";
    std::cout << "\nСортировка выбором\n";
    for (int i = 0; i < std::size(arr_a); i++) arr_a[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_b); i++) arr_b[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_c); i++) arr_c[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_d); i++) arr_d[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_e); i++) arr_e[i] = rand() % 101;
    // массив из 100
    time(&start);
    select_sort(arr_a, std::size(arr_a));
    time(&end);
    duration = difftime(end, start);
    std::cout << " Массив из " << std::size(arr_a) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 1000
    time(&start);
    select_sort(arr_b, std::size(arr_b));
    time(&end);
    duration = difftime(end, start);
    std::cout << " Массив из " << std::size(arr_b) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 10000
    time(&start);
    select_sort(arr_c, std::size(arr_c));
    time(&end);
    duration = difftime(end, start);
    std::cout << " Массив из " << std::size(arr_c) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 100000
    time(&start);
    select_sort(arr_d, std::size(arr_d));
    time(&end);
    duration = difftime(end, start);
    std::cout << " Массив из " << std::size(arr_d) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 1000000
    time(&start);
    select_sort(arr_e, std::size(arr_e));
    time(&end);
    duration = difftime(end, start);
    std::cout << " Массив из " << std::size(arr_e) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    std::cout << "\nСортировка кучей\n";
    for (int i = 0; i < std::size(arr_a); i++) arr_a[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_b); i++) arr_b[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_c); i++) arr_c[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_d); i++) arr_d[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_e); i++) arr_e[i] = rand() % 101;
    // массив из 100
    time(&start);
    heap_sort(arr_a, std::size(arr_a));
    time(&end);
    duration = difftime(end, start);
    std::cout << " Массив из " << std::size(arr_a) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 1000
    time(&start);
    heap_sort(arr_b, std::size(arr_b));
    time(&end);
    duration = difftime(end, start);
    std::cout << " Массив из " << std::size(arr_b) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 10000
    time(&start);
    heap_sort(arr_c, std::size(arr_c));
    time(&end);
    duration = difftime(end, start);
    std::cout << " Массив из " << std::size(arr_c) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 100000
    time(&start);
    heap_sort(arr_d, std::size(arr_d));
    time(&end);
    duration = difftime(end, start);
    std::cout << " Массив из " << std::size(arr_d) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 1000000
    time(&start);
    heap_sort(arr_e, std::size(arr_e));
    time(&end);
    duration = difftime(end, start);
    std::cout << " Массив из " << std::size(arr_e) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    return 0;
}
