# Нахождение кол-ва счастливых билетов 2N с помощью рекурсии
# Для уровня Middle

def count_happy_tickets(n):
    sum1 = 0
    sum2 = 0
    count = 0
    
    def count_tickets(n, sum1, sum2):
        nonlocal count
        if n == 0:
            if sum1 == sum2:
               count += 1
            return
        for n1 in range(0, 10):
            for n2 in range(0, 10):
                count_tickets(n-1, sum1+n1, sum2+n2)
            
    count_tickets(n, 0, 0)
    return count
    
def main():
    n = int(input("Введите кол-во цифр: "))
    count = count_happy_tickets(n)
    print(count)

if __name__ == "__main__":
    main()
