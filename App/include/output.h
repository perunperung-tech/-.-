#pragma once
#include <string>

// "Average: 4.50", для отрицательного числа - invalid_argument
std::string formatAverage(double value);

// "Max grade: 5", для отрицательного числа - invalid_argument
std::string formatMax(int value);
