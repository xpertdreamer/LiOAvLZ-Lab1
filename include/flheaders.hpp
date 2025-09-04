#ifndef FLHEADERS_H
#define FLHEADERS_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <ctime>
#include <locale>
#include <algorithm>
#include "windows.h"

int* generate_random_array(int size, int min, int max);
void print_array(const int* array, int size);
int calculate_difference(int* array, int size);

int** create_2DArray(int rows, int cols, int min, int max);
void print_2DArray(int** matrix, int rows, int cols);
void free_2DArray(int** matrix, int rows);
int calculate_sum_in_row(int** matrix, int row_index, int cols, int rows);

void initialize();
bool validate_input(std::istream& input, int& value, const char* prompt);
bool validate_input(std::istream& input, int& value1, int& value2, const char* prompt);

#endif // FLHEADERS_H