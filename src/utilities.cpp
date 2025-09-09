#include "flheaders.hpp"

using namespace std;

#ifdef max
#undef max
#endif

#ifdef _WIN32
#include <windows.h>
#endif 

void initialize() {
    srand(static_cast<unsigned int>(time(nullptr)));
    locale::global(locale(""));

#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif
}

bool validate_input(istream& input, int& value, const char* prompt) {
    cout << prompt;
    if (!(input >> value) || value <= 0) {
        input.clear();
        // игнорируем ввод до конца строки
        input.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool validate_input(istream& input, string& value, const char* prompt) {
    cout << prompt;
    if (!(input >> value) || value == " " ) {
        input.clear();
        // игнорируем ввод до конца строки
        input.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool validate_input(istream& input, int& value1, int& value2, const char* prompt) {
    cout << prompt;
    if (!(input >> value1 >> value2) || value1 <= 0 || value2 <= 0) {
        input.clear();
        // игнорируем ввод до конца строки
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
} 

void print_student(Student *st) {
    if (st) cout << "Найден: " << st->id << " | " << st->surname << " " << st->firstname << " | " << st -> faculty << "\n";
    else cout << "Не найден" << endl;
}

void print_student(const std::vector<Student> &sts) {
    if(sts.size() == 0) cout << "Не найден" << endl;
    else 
    for (const auto& st : sts) {
        cout << "Найден: " << st.id << " | " << st.surname << " " << st.firstname << " | " << st.faculty << "\n";
    }
}

bool contains_substring(const Student& student, const std::string& substring) {
    return student.surname.find(substring) != std::string::npos ||
           student.firstname.find(substring) != std::string::npos ||
           student.faculty.find(substring) != std::string::npos;
}

bool contains_any(const Student& student, const std::string& substring) {
    return student.surname.find(substring) != std::string::npos ||
           student.firstname.find(substring) != std::string::npos ||
           student.faculty.find(substring) != std::string::npos ||
           to_string(student.id).find(substring) != std::string::npos;
}