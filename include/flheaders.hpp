#ifndef FLHEADERS_H
#define FLHEADERS_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <ctime>
#include <locale>
#include <algorithm>
#include "windows.h"
#include <string>
#include <iterator>
#include <limits>

struct Student {
    std::string surname;
    std::string firstname;
    std::string faculty;
    int id;
};
inline Student studs[5] = {
        {"Будников", "Алексей", "ФВТ", 12},
        {"Иванов", "Иван", "ФФМЕН", 344},
        {"Васильев", "Василий", "ЛФ", 993},
        {"Гурин", "Алексей", "ФВТ", 32},
        {"Захаров", "Артём", "ФВТ", 48},
    };;

int* generate_random_array(int size, int min, int max);
void print_array(const int* array, int size);
int calculate_difference(int* array, int size);

int** create_2DArray(int rows, int cols, int min, int max);
void print_2DArray(int** matrix, int rows, int cols);
void free_2DArray(int** matrix, int rows);
int calculate_sum_in_row(int** matrix, int row_index, int cols, int rows);

template<class Pred>
Student* find_student(struct Student st[], int n, Pred pred) {
    for (std::size_t i = 0; i < n; ++i)
        if (pred(st[i])) return &st[i];
    return nullptr;
}

void initialize();
bool validate_input(std::istream& input, int& value, const char* prompt);
bool validate_input(std::istream& input, int& value1, int& value2, const char* prompt);
bool validate_input(std::istream& input, std::string& value, const char* prompt);

#endif // FLHEADERS_H