#include "flheaders.hpp"
#include <list.hpp>

using namespace std;

int main() {
    try {
        initialize();

        constexpr int min = -40;
        constexpr int max = 40;
      
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
        cout << "Сумма чисел в строке под номером " << row_index << ": " << calculate_sum_in_row(matrix, row_index, cols, rows) << endl;
        free_2DArray(matrix, rows);

        cout << "Список студентов: " << endl;
        for (auto &stud : studs)
            cout << stud.id << " | " << stud.surname << " " << stud.firstname << " | " << stud.faculty << "\n";

        string search_term;
        if (!validate_input(cin, search_term, "Введите строку для поиска: ")) 
            throw runtime_error("Ошибка ввода");
        const List<Student> res = find_student(studs, std::size(studs), [search_term](const Student &s) {
            return contains_any(s, search_term);
        });
        print_student(res);
        
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
