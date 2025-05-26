/*Алгоритм Демукрона*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 7
#define SMAX 2

bool demucron();

// вектор смежности
int vector[SIZE][SMAX] = {
    {3, 0},
    {1, 3},
    {0, 0},
    {2, 0},
    {4, 6},
    {0, 0},
    {6, 1}
};

int result[SIZE][3];

int path[10];

bool demucron() {
    int entries [SIZE];  // полустепень захода
    bool visited[SIZE];
    for (int i = 0; i < SIZE; i++) visited[i] = false;
    int sum = 0;

    // получение полустепеней захода
    for (int i = 0; i < SIZE; i++) {
        entries[i] = 0;
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SMAX; k++) {
                if ((i + 1) == vector[j][k]) {
                    entries[i]++;
                    sum++;
                }
            }
        }
    }
    // Получение отсортированных элементов
    int step = 0;
    bool isAny;
    do{
        bool isAny = false;
        for (int i = 0; i < SIZE; i++) {
            if (visited[i]) continue;
            if (entries[i] > 0) continue;
            visited[i] = true;
            isAny = true;
            path[step] = i + 1;
            step++;
            for (int k = 0; k < SMAX; k++) {
                int point = vector[i][k];
                if (point) {
                    entries[point - 1]--;
                    sum--;
                    result[i][0] = (i + 1);
                    result[i][k+1] = point;
                }
            }
            printf("На %d уровне находятся вершины %d %d \n", i+1, result[i][1], result[i][2]);
            break;
        }
        if (!isAny) return false;
    }
    while (sum > 0);
    
    for (int i = 0; i < SIZE; i++) {
        if (visited[i] == false) {
            path[step] = (i + 1);
            result[i][0] = i + 1;
            printf("На %d уровне находятся вершины %d %d \n", i+1, 0, 0);
            step++;
        }
    }
    
    return true;
}

int main(){
    bool is_path = demucron();
    printf("Путь: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", path[i]);
    printf("\n");
    return 0;
}
