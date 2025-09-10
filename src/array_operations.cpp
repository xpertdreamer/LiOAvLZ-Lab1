#include "flheaders.hpp"

using namespace std;

int* generate_random_array(int size, int min, int max) {
    int *array = static_cast<int*>(malloc(size * sizeof(int)));
    if (!array) throw runtime_error("Ошибка выделения памяти");

    for (int i = 0; i < size; i++) array[i] = min + (rand() % (max - min + 1));

    return array;
}

void print_array(const int* array, int size) {
    for (int i = 0; i < size; i++) cout << array[i] << " ";
}

int calculate_difference(int* array, int size) {
    if (size <= 1) return 0;

    sort(array, array + size);
    int diff = array[size - 1] - array[0];

    return diff;
}

int** create_2DArray(int rows, int cols, int min, int max) {
    int **array = static_cast<int**>(malloc(rows * sizeof(int*)));
    if (!array) throw runtime_error("Ошибка выделения памяти");

    for (int i = 0; i < rows; i++) {
        array[i] = static_cast<int*>(malloc(cols * sizeof(int)));
        if (!array[i]) { 
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            throw runtime_error("Ошибка выделения памяти");
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = min + (std::rand() % (max - min + 1));
        }
    }

    return array;
}

void print_2DArray(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << setw(5) << matrix[i][j] << "   ";
        cout << endl;
    }
}

int calculate_sum_in_row(int** matrix, int row_index, int cols, int rows) {
    int sum = 0;
    if (matrix == nullptr 
        || row_index - 1 <= 0
        || row_index - 1 > rows
        || cols <= 0) return 0;
    int i = 0;
    while (i < cols) {
        sum += matrix[row_index - 1][i];
        i++;
    }

    return sum;
}

void free_2DArray(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);
}