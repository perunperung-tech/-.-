#pragma once
#include <vector>

// сумма всех элементов (для пустого вектора 0)
int sum(const std::vector<int>& values);

// среднее значение, для пустого вектора - invalid_argument
double average(const std::vector<int>& values);

// максимальный элемент, для пустого вектора - invalid_argument
int maxValue(const std::vector<int>& values);
