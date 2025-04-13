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
    int A[] = {1, 0, 0, 2, 0, 2, 1};
    for (int i = 0; i < std::size(A); i++) std::cout << A[i] << " ";
    std::cout << std::endl;
    count_sort(A, std::size(A));
    for (int i = 0; i < std::size(A); i++) std::cout << A[i] << " ";
    std::cout << std::endl;
    return 0;
}
