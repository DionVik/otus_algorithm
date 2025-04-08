// Уровень Junior. Быстрая сортировка и сортировка слиянием.
// Сранвительная таблица сортировок

#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int *p, int a, int b) {
    int temp = p[a];
    p[a] = p[b];
    p[b] = temp;
}

int partitition(int *p, int left, int right) {
    // Для ускорения опорный элемент лучше задать рандомно, а потом поменять его местами с конечным
    int pivot = right; // опорный элемент определяем равным конечному элементу
    int b = left; // 'граница', разделяющая элементы меньше опорного и элементы больше опорного
    for (int i = left; i < right; i++) {
        if (p[i] <= p[pivot]) {
            swap(p, i, b);
            b++;
        }
    }
    swap(p, b, pivot);
    return b;
}

int quicksort(int *p, int left, int right) {
    if (left < right) {
        int pivot = partitition(p, left, right); // устанавливаем опорный опорный элемент на место
        quicksort(p, left, pivot - 1);
        quicksort(p, pivot + 1, right);
    }
    return 0;
}

void mergearrays(int *p, int left, int mid, int right){
    int size = right - left +1;
    int *c = new int[size]; // вспомогательный массив
    for (int k = left; k <= right; k++) {
         c[k - left] = p[k];
    }
    int i = 0; // указатель для первой отсортированной части
    int j = mid - left + 1; // указатель для второй отсортированной части
    int cm = mid - left; // индекс последнего эл-та первой части
    int ch = right - left; // индекс последнего эл-та второй части
    
    for (int k = left; k <= right; k++) {
        if (i > cm) {
            p[k] = c[j];
            j++;
        }
        else if (j > ch) {
            p[k] = c[i];
            i++;
        }
        else if (c[i] < c[j]) {
            p[k] = c[i];
            i++;
        }
        else {
            p[k] = c[j];
            j++;
        }
    }
    delete [] c;
}

void mergesort(int *p, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(p, left, mid);
        mergesort(p, mid+1, right);
        mergearrays(p, left, mid, right);
    }
}

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
    std::cout << "\nБыстрая сортировка\n";
    for (int i = 0; i < std::size(arr_a); i++) arr_a[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_b); i++) arr_b[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_c); i++) arr_c[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_d); i++) arr_d[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_e); i++) arr_e[i] = rand() % 101;
    // массив из 100
    int left = 0;
    int right = std::size(arr_a) - 1;
    time(&start);
    quicksort(arr_a, left, right);
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_a) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 1000
    right = std::size(arr_b) - 1;
    time(&start);
    quicksort(arr_b, left, right);
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_b) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 10000
    right = std::size(arr_c) - 1;
    time(&start);
    quicksort(arr_c, left, right);
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_c) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 100000
    right = std::size(arr_d) - 1;
    time(&start);
    quicksort(arr_d, left, right);
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_d) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 1000000
    right = std::size(arr_e) - 1;
    time(&start);
    quicksort(arr_e, left, right);
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_e) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    std::cout << "\nСортировка слиянием\n";
    for (int i = 0; i < std::size(arr_a); i++) arr_a[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_b); i++) arr_b[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_c); i++) arr_c[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_d); i++) arr_d[i] = rand() % 101;
    for (int i = 0; i < std::size(arr_e); i++) arr_e[i] = rand() % 101;
    // массив из 100
    left = 0;
    right = std::size(arr_a) - 1;
    time(&start);
    mergesort(arr_a, left, right);
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_a) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 1000
    right = std::size(arr_b) - 1;
    time(&start);
    mergesort(arr_b, left, right);
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_b) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 10000
    right = std::size(arr_c) - 1;
    time(&start);
    mergesort(arr_c, left, right);
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_c) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 100000
    right = std::size(arr_d) - 1;
    time(&start);
    mergesort(arr_d, left, right);
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_d) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    // массив из 1000000
    right = std::size(arr_e) - 1;
    time(&start);
    mergesort(arr_e, left, right);
    time(&end);
    duration = difftime(end, start);
    std::cout << "Массив из " << std::size(arr_e) << " элементов. ";
    std::cout << " Продолжительность: " << duration <<std::endl;
    
    return 0;
}

