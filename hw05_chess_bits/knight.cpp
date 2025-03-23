// Уровень Junior. 
// Находим доступные ячейки и их кол-во для шахматного коня. 

#include <iostream>

class Knight {
    int base_index; // индекс клетки, на которой стоит фигура
    
    public:
        int count = 0; // кол-во возможных ходов
        unsigned long long bb = 1; // битовое представление индекса
        Knight(int index);
        unsigned long long get_available_cells();
};

Knight::Knight(int index) {
    base_index = index;
    bb = bb << base_index;
}

unsigned long long Knight::get_available_cells() {
    unsigned long long mask = 0;           // битовая маска возможных ходов
    unsigned long long left_side_mask = 0xFEFEFEFEFEFEFEFE;
    unsigned long long left_side_mask2 = 0xFCFCFCFCFCFCFCFC;
    unsigned long long right_side_mask = 0x7F7F7F7F7F7F7F7F;
    unsigned long long right_side_mask2 = 0x3F3F3F3F3F3F3F3F;
    
    mask = (bb & left_side_mask2) << 6; // влево вверх
    if (((bb & left_side_mask2) << 6) != 0) count++;
    
    mask |= (bb & left_side_mask) << 15; //  влево вверх 
    if (((bb & left_side_mask) << 15) != 0) count++;
    
    mask |= (bb & left_side_mask2) >> 10; // влево вниз
    if (((bb & left_side_mask2) >> 10) != 0) count++;
    
    mask |= (bb & left_side_mask) >> 17; // влево вниз
    if (((bb & left_side_mask) >> 10) != 0) count++;
    
    mask |= (bb & right_side_mask2) << 10; //  вправо вверх
    if (((bb & right_side_mask2) << 10) != 0) count++;
    
    mask |= (bb & right_side_mask) << 17; //  вправо вверх
    if (((bb & right_side_mask) << 17) != 0) count++;
    
     mask |= (bb & right_side_mask2) >> 6; //  вправо вниз
    if (((bb & right_side_mask2) >> 6) != 0) count++;
    
    mask |= (bb & right_side_mask) >> 15; //  вправо вниз
    if (((bb & right_side_mask) >> 15) != 0) count++;
    
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
        Knight knight(index);
        unsigned long long result = knight.get_available_cells();
        std::cout << "Количество доступных ходов: " << knight.count;
        std::cout << "\nДоступные клетки для фигуры: " << result << std::endl;
    }
    return 0;
}
