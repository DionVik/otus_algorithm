# Нахождение кол-ва счастливых билетов для 6 значного числа.
# Уровень Junior

def main():
    count = 0
    for a1 in range(0, 10):
        for a2 in range(0, 10):
            for a3 in range(0,10):
                sum = a1 + a2 + a3
                for b1 in range(0, 10):
                    for b2 in range(0, 10):
                        b3 = sum - b1 - b2
                        if b3 >= 0 and b3 < 10:
                            count += 1
    print(f"count = {count}")


if __name__ == "__main__":
    main()

# ответ count = 55252
# затрачено 10 мин.

