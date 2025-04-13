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
    int A[] = {318, 49, 102, 444, 2};
    for (int i = 0; i < std::size(A); i++) std::cout << A[i] << " ";
    std::cout << std::endl;
    radix_sort(A, std::size(A));
    for (int i = 0; i < std::size(A); i++) std::cout << A[i] << " ";
    std::cout << std::endl;
    return 0;
}
