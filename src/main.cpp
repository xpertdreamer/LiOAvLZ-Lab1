#include "flheaders.hpp"

using namespace std;

int main() {
    try {
        initialize();

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
        cout << "Сумма чисел в строке под номером " << row_index << ": " << calculate_sum_in_row(matrix, row_index, cols, rows) << endl;
        free_2DArray(matrix, rows);

        int choice;
        if (!validate_input(cin, choice, "Выберите поле для поиска(1 - имя, 2 - фамилия, 3 - факультет, 4 - id): ")) 
            throw runtime_error("Ошибка ввода");
        switch (choice)
        {
            case 1:
            {
                string firstname;
                if (!validate_input(cin, firstname, "Введите имя: ")) throw runtime_error("Ошибка ввода");
                Student* res = find_student(studs, std::size(studs), [firstname](Student &s){return s.firstname == firstname; });
                print_student(res);
                break;
            }
            case 2:
            {
                string surname;
                if (!validate_input(cin, surname, "Введите фамилию: ")) throw runtime_error("Ошибка ввода");
                Student* res = find_student(studs, std::size(studs), [surname](Student &s){return s.surname == surname; });
                print_student(res);
                break;
            }
            case 3:
            {
                string faculty;
                if (!validate_input(cin, faculty, "Введите фaкультет: ")) throw runtime_error("Ошибка ввода");
                Student* res = find_student(studs, std::size(studs), [faculty](Student &s){return s.faculty == faculty; });
                print_student(res);
                break;
            }
            case 4:
            {
                int id;
                if (!validate_input(cin, id, "Введите номер зачетной книжки: ")) throw runtime_error("Ошибка ввода");
                Student* res = find_student(studs, std::size(studs), [id](Student &s){return s.id == id; });
                print_student(res);
                break;
            }
            default:
                cout << "Неверный выбор!" << endl;                
        }
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}