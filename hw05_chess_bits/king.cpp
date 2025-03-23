// Уровень Junior. 
// Находим доступные ячейки и их кол-во для шахматного короля. 

#include <iostream>

class King {
    int base_index; // индекс клетки, на которой стоит фигура
    
    public:
        int count = 0; // кол-во возможных ходов
        unsigned long long bb = 1; // битовое представление индекса
        King(int index);
        unsigned long long get_available_cells();
};

King::King(int index) {
    base_index = index;
    bb = bb << base_index;
}

unsigned long long King::get_available_cells() {
    unsigned long long mask = 0;           // битовая маска возможных ходов
     
    mask = (bb & 0xFEFEFEFEFEFEFEFE) >> 1; // влево
    if (((bb & 0xFEFEFEFEFEFEFEFE) >> 1) != 0) count++;
    mask |= (bb & 0xFEFEFEFEFEFEFEFE) << 7; //  вверх влево 
    if (((bb & 0xFEFEFEFEFEFEFEFE) << 7) != 0) count++;
    mask |= (bb & 0xFEFEFEFEFEFEFEFE) >> 9; // вниз влево
    if (((bb & 0xFEFEFEFEFEFEFEFE) >> 9) != 0) count++;
    
    mask |= (bb & 0x7F7F7F7F7F7F7F7F) << 1; //  вправо
    if (((bb & 0x7F7F7F7F7F7F7F7F) << 1) != 0) count++;
    mask |= (bb & 0x7F7F7F7F7F7F7F7F) >> 7; // вниз вправо
    if (((bb & 0x7F7F7F7F7F7F7F7F) >> 7) != 0) count++;
    mask |= (bb & 0x7F7F7F7F7F7F7F7F) << 9; //  вверх вправо
    if (((bb & 0x7F7F7F7F7F7F7F7F) << 9) != 0) count++;
    
    mask |=  bb >> 8;                       // вниз
    if ((bb >> 8) != 0) count++;
    mask |= bb << 8;                        //  вверх
    if ((bb << 8) != 0) count++;
    
    return mask;
}

int main() {
     while (true) {
        std::cout << "\nВведите индекс позиции фигуры от 0 до 63"; 
        std::cout << " (q - выход): ";
        char str [3];
        std::cin >> str;
        if (str[0] == 'q') return 0;
        int index = std::stoi(str);
        King king(index);
        unsigned long long result = king.get_available_cells();
        std::cout << "Количество доступных ходов: " << king.count;
        std::cout << "\nДоступные клетки для фигуры: " << result << std::endl;
    }
    return 0;
}
