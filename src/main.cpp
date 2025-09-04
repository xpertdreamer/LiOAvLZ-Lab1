#include "flheaders.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <algorithm>
#include <limits>
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {
    try {
        srand(static_cast<unsigned int>(time(nullptr)));
        locale::global(locale(""));
        
        #ifdef _WIN32
        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);
        #endif

        const int min = -40;
        const int max = 40;

        int size;
        if (!validate_input(cin, size, "Введите размер массива: ")) 
            throw runtime_error("Ошибка ввода");

        int *array = generate_random_array(size, min, max);
        cout << "Сгенерированный массив: ";
        print_array(array, size);
        cout << endl;

        cout << "Разница: " << calculate_difference(array, size) << endl;
        free(array);  

        int cols, rows;
        if (!validate_input(cin, rows, cols, "Введите количество строк и столбцов (rows cols): ")) 
            throw runtime_error("Ошибка ввода");
        
        int **matrix = create_2DArray(rows, cols, min, max);
        cout << "Сгенерированная матрица:" << endl;
        print_2DArray(matrix, rows, cols);

        int row_index;
        if (!validate_input(cin, row_index, "Введите номер строки: "))
            throw runtime_error("Ошибка ввода");
        cout << "Сумма чисел в строке под номером " << row_index << ": " << calculate_sum_in_row(matrix, row_index, cols, rows);
        free_2DArray(matrix, rows);
        
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}