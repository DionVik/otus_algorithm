// Уровень Junior. Сортировка методом кучей. 

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

int main() {
    time_t start;
    time_t end;
    double duration;
    int arr_a[15];
   
    std::cout << "\nСортировка кучей\n";
    for (int i = 0; i < std::size(arr_a); i++) arr_a[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_a); i++) std::cout << arr_a[i] << " ";
    time(&start);
    heap_sort(arr_a, std::size(arr_a));
    time(&end);
    duration = difftime(end, start);
    std::cout << std::endl;
    for (int i = 0; i < std::size(arr_a); i++) std::cout << arr_a[i] << " ";
    std::cout << std::endl;
    std::cout << "Массив из " << std::size(arr_a) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    return 0;
}
