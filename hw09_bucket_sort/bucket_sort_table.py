# сортировка блоками

import random
from datetime import datetime

def bucketsort(A: list):
    # помещаем элементы массива А в блоки
    B = []
    for i in range(len(A)):
        bucket = []
        B.append(bucket)
    for i in range(len(A)):
        m = (A[i] * len(A)) // 1000
        B[m].append(A[i])
        
    # сортировка элементов в блоках
    for i in range(len(B)):
        if len(B[i]) == 0:
            continue
        #q uicksort(B[i], 0, (len(B[i])-1))
        insert(B[i])
    
    # извлекаем элементы из блоков в массив А
    A.clear()
    for i in range(len(B)):
        if len(B[i]) == 0:
            continue
        for j in range(len(B[i])):
            A.append(B[i][j])
        
def insert(a: list):
    for i in range(1, len(a)):
        index = i - 1
        while index >= 0:
            if a[index] <= a[i]:
                break
            a[index], a[i] = a[i], a[index]
            i -= 1
            index -= 1
            
def main():
    arr_a = [random.randint(0, 999) for i in range(0, 100)]
    arr_b = [random.randint(0, 999) for i in range(0, 1000)]
    arr_c = [random.randint(0, 999) for i in range(0, 10000)]
    arr_d = [random.randint(0, 999) for i in range(0, 100000)]
    arr_e = [random.randint(0, 999) for i in range(0, 1000000)]
    arrays = [arr_a, arr_b, arr_c, arr_d, arr_e]
    
    print ("Блочная сортировка")
    for i in arrays:
        start = datetime.now()
        bucketsort(i)
        end = datetime.now()
        tdelta = end - start
        print(f"Массив из {len(i)} элементов. Продолжительность {tdelta.seconds}")
        
if __name__ == "__main__":
    main()



    
