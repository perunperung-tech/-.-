#include "calculation.h"
#include <stdexcept>

int sum(const std::vector<int>& values)
{
    int result = 0;
    for (size_t i = 0; i < values.size(); i++)
        result += values[i];
    return result;
}

double average(const std::vector<int>& values)
{
    if (values.empty())
        throw std::invalid_argument("vector is empty");

    return static_cast<double>(sum(values)) / values.size();
}

int maxValue(const std::vector<int>& values)
{
    if (values.empty())
        throw std::invalid_argument("vector is empty");

    int result = values[0];
    for (size_t i = 1; i < values.size(); i++)
    {
        if (values[i] > result)
            result = values[i];
    }
    return result;
}
