# сортировка блоками

def bucketsort(A: list):
    # помещаем элементы массива А в блоки
    B = []
    for i in range(len(A)):
        bucket = []
        B.append(bucket)
    for i in range(len(A)):
        m = (A[i] * len(A)) // 100
        B[m].append(A[i])
        
    # сортировка элементов в блоках
    for i in range(len(B)):
        if len(B[i]) == 0:
            continue
        quicksort(B[i], 0, (len(B[i])-1))
    
    # извлекаем элементы из блоков в массив А
    A.clear()
    for i in range(len(B)):
        if len(B[i]) == 0:
            continue
        for j in range(len(B[i])):
            A.append(B[i][j])
        
def quicksort(a: list, left: int, right: int):
    if left < right:
        pivot = split(a, left, right)
        quicksort(a, left, pivot-1)
        quicksort(a, pivot+1, right)
    
def split(a: list, left: int, right: int):
    pivot = right
    b = left
    for i in range(left, right):
        if a[i] <= a[pivot]:
            a[i], a[b] = a[b], a[i]
            b += 1
    a[b], a[pivot] = a[pivot], a[b]
    return b
        
def main():
    A = [60, 80, 13,  15, 44, 2, 22, 83, 16, 3, 12, 11]
    print(A)
    bucketsort(A)
    print(A)
    
if __name__ == "__main__":
    main()



    
