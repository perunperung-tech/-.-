#pragma once
#include <string>
#include <vector>

// переводит строку в число, если не получилось - invalid_argument
int parseNumber(const std::string& text);

// оценка должна быть от 2 до 5
bool isValidGrade(int grade);

// читает оценки с клавиатуры, пустая строка - конец ввода
std::vector<int> readGrades();
