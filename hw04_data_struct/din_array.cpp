#include <iostream>
#include <ctime>

class FixArray {
    char *p;
    int arr_size;
    int count;
    public:
        char name[50] = "Фиксированный массив";
        FixArray(int size);
        ~FixArray();
        char get_element(int index);
        void set_element(int index, char value);
        void put(char value);
};

FixArray::FixArray(int size = 1) {
    count = 0; // последний заполненный индекс массива
    arr_size = size;
    p = new char[arr_size];
    for (int i = 0; i < arr_size; i++) p[i] = '*';

}

FixArray::~FixArray() {
    delete [] p;
}


char FixArray::get_element(int index) {
    return p[index];
}

void FixArray::set_element(int index, char value) {
    p[index] = value;
}

void FixArray::put(char value) {
    p[count] = value;
    count++;
}
//"Динамический массив + 1"=============================================
class Vector : public FixArray {
    char *p;
    char *p_vector;
    int count;
    
    public:
        Vector(int size);
        ~Vector();
        int arr_size;
        int realloc = 0;
        void put(char value);
        void add(int index, char value);
        void remove(int index);
        char name[50] = "Динамический массив + 1";
};

Vector::Vector(int size) {
    count = 0; // индекс первой незаполненной ячейки
    arr_size = size;
    p = new char[arr_size];
    p = new char[arr_size];
    for (int i = 0; i < arr_size; i++) p[i] = '*';
}

Vector::~Vector() {
    delete [] p;
}

void Vector::put(char value) {
    if (count < arr_size) {
        p[count] = value;
        count++;
    } else {
        realloc++;
        arr_size = count + 1;
        char *p_vector = new char[arr_size];
        for (int i = 0; i < arr_size; i++) p_vector[i] = '-';
        for (int i = 0; i < count; i++){
            p_vector[i] = p[i];
        }
        p_vector[count] = value;
        count++;
        p = p_vector;
    }
}

void Vector::add(int index, char value) {
    if (count < arr_size) {
        for (int i = count-1; i >= index; i--) p[i+1] = p[i]; // сдвигаем
        p[index] = value;
        count++;
    } else {
        realloc++;
        arr_size = count + 1;
        char *p_vector = new char[arr_size]; //создаём новый
        for (int i = 0; i < arr_size; i++) p_vector[i] = '-'; // заполняем 
        for (int i = 0; i < count; i++) p_vector[i] = p[i]; //копируем
        for (int i = count-1; i >= index; i--) p_vector[i+1] = p[i]; //сдвигаем
        p_vector[index] = value;
        count++;
        p = p_vector;
    }
}

void Vector::remove(int index) {
    for (int i = index; i < count; i++) p[i] = p[i+1]; // сдвигаем
    count--;
}
//"Динамический массив + 100"=========================================
class Range : public FixArray {
    char *p;
    char *p_range;
    int count;
    
    public:
        Range(int size);
        ~Range();
        int arr_size;
        int realloc = 0;
        void put(char value);
        void add(int index, char value);
        void remove(int index);
        char name[50] = "Динамический массив + 100";
};

Range::Range(int size) {
    count = 0; // индекс первой незаполненной ячейки
    arr_size = size;
    p = new char[size];
    for (int i = 0; i < arr_size; i++) p[i] = '*';
}

Range::~Range() {
    delete [] p;
}

void Range::put(char value) {
    if (count < arr_size) {
        p[count] = value;
        count++;
    } else {
        realloc++;
        arr_size = count + 100;
        char *p_range = new char[arr_size];
        for (int i = 0; i < arr_size; i++) p_range[i] = '-';
        for (int i = 0; i < count; i++){
            p_range[i] = p[i];
        }
        p_range[count] = value;
        count++;
        p = p_range;
    }
}
void Range::add(int index, char value) {
    if (count < arr_size) {
        for (int i = count-1; i >= index; i--) p[i+1] = p[i]; // сдвигаем
        p[index] = value;
        count++;
    } else {
        realloc++;
        arr_size = count + 100;
        char *p_range = new char[arr_size]; //создаём новый
        for (int i = 0; i < arr_size; i++) p_range[i] = '-'; // заполняем 
        for (int i = 0; i < count; i++) p_range[i] = p[i]; //копируем
        for (int i = count-1; i >= index; i--) p_range[i+1] = p[i]; //сдвигаем
        p_range[index] = value;
        count++;
        p = p_range;
    }
}

void Range::remove(int index) {
    for (int i = index; i < count; i++) p[i] = p[i+1]; // сдвигаем
    count--;
}
//"Динамический массив *2==========================================
class Factor : public FixArray {
    char *p;
    char *p_factor;
    int count;
    
    public:
        Factor(int size);
        ~Factor();
        int arr_size;
        int realloc = 0;
        void put(char value);
        void add(int index, char value);
        void remove(int index);
        char name[50] = "Динамический массив *2";
};

Factor::Factor(int size) {
    count = 0; // индекс первой незаполненной ячейки
    arr_size = size;
    p = new char[size];
    for (int i = 0; i < arr_size; i++) p[i] = '*';
}

Factor::~Factor() {
    delete [] p;
}

void Factor::put(char value) {
    if (count < arr_size) {
        p[count] = value;
        count++;
    } else {
        realloc++;
        arr_size = count * 2;
        char *p_factor = new char[arr_size];
        for (int i = 0; i < arr_size; i++) p_factor[i] = '-';
        for (int i = 0; i < count; i++) p_factor[i] = p[i];
        p_factor[count] = value;
        count++;
        p = p_factor;
    }
}
void Factor::add(int index, char value) {
    if (count < arr_size) {
        for (int i = count-1; i >= index; i--) p[i+1] = p[i]; // сдвигаем
        p[index] = value;
        count++;
    } else {
        realloc++;
        arr_size = count * 2;
        char *p_factor = new char[arr_size]; //создаём новый
        for (int i = 0; i < arr_size; i++) p_factor[i] = '-'; // заполняем 
        for (int i = 0; i < count; i++) p_factor[i] = p[i]; //копируем
        for (int i = count-1; i >= index; i--) p_factor[i+1] = p[i]; //сдвигаем
        p_factor[index] = value;
        count++;
        p = p_factor;
    }
}

void Factor::remove(int index) {
    for (int i = index; i < count; i++) p[i] = p[i+1]; // сдвигаем
    count--;
}
//==================================================================           
int main(){
    Vector vec1(3), vec2(3);
    Range range1(3), range2(3);
    Factor fact1(3), fact2(3);
    time_t start;
    time_t end;
    double duration;
    std::cout << "\n Добавление значения в конец - put \n";
    for (int N = 100; N < 100000; N*=10) {
        std::cout << "N = " <<  N << std::endl;
        // для массива +1
        time(&start);
        for (int i = 0; i < N; i++) vec1.put('a');
        time(&end);
        duration = difftime(end, start);
        std::cout << vec1.name;
        std::cout << " Изменений размера = " << vec1.realloc;
        std::cout << " Длительность = " << duration << " сек.\n";
        // для массива +100
        time(&start);
        for (int i = 0; i < N; i++) range1.put('a');
        time(&end);
        duration = difftime(end, start);
        std::cout << range1.name;
        std::cout << " Изменений размера = " << range1.realloc;
        std::cout << " Длительность = " << duration << " сек.\n";
        // для массива *2
        time(&start);
        for (int i = 0; i < N; i++) fact1.put('a');
        time(&end);
        duration = difftime(end, start);
        std::cout << fact1.name;
        std::cout << " Изменений размера = " << fact1.realloc;
        std::cout << " Длительность = " << duration << " сек.\n";
    }
    
    std::cout << "\n Вставка значения в индекс 2 - add \n";
    for (int N = 100; N < 100000; N*=10) {
        std::cout << "N = " <<  N << std::endl;
        // для массива +1
        time(&start);
        for (int i = 0; i < N; i++) vec2.add(2, 'a');
        time(&end);
        duration = difftime(end, start);
        std::cout << vec2.name;
        std::cout << " Изменений размера = " << vec2.realloc;
        std::cout << " Длительность = " << duration << " сек. \n";
        // для массива +100
        time(&start);
        for (int i = 0; i < N; i++) range2.add(2, 'a');
        time(&end);
        duration = difftime(end, start);
        std::cout << range2.name;
        std::cout << " Изменений размера = " << range2.realloc;
        std::cout << " Длительность = " << duration << " сек. \n";
        // для массива *2
        time(&start);
        for (int i = 0; i < N; i++) fact2.add(2, 'a');
        time(&end);
        duration = difftime(end, start);
        std::cout << fact2.name;
        std::cout << " Изменений размера = " << fact2.realloc;
        std::cout << " Длительность = " << duration << " сек. \n";
    }
    return 0;
}
